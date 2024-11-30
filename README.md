# Project

Insert flash drive into PC
Allow access for both native machine and VM

Open terminal
Run command: ```lsusb``` 	 
//Should display the drive with serial ID

Run command: ```sudo fdisk -l```		
// Displays available drives

At the start, there should be nothing on the drive so further searching is not required.
Take note of the drive path and drive ID

Path: /dev/vda

Try fdisk -l everytime you insert the device and confirm its consistency as /dev/vda

When writing code, target: /dev/vda (writing, reading, encrypting)

encryption library: https://github.com/google/fscrypt?tab=readme-ov-file#building-and-installing

Instruction for setting up encryption library on USB.
In terminal run the following commands:
1. ```sudo apt update```
2. ```sudo apt install build-essential libssl-dev libuuid1``` this is to install the runtime dependencies for the encryption library
3. Then, you want to clone the git repo with the following command: git ```clone https://github.com/google/fscrypt.git --recursive```
then navigate into the directory with ```cd fscrypt```
4. Once in the directory, you must setup the config file so that it can be called within your USB's directory, run command ```sudo fscrypt setup```
5. Now we need to mount the USB, but before we can do that we need to make sure that our USB is using the correct linux filesystem. My USB did not come with the filesystem that is required when using this encrytion library. This library requires ext4, but most USB drives come with the vfat file system installed. This although, can be changed. To do so, make sure that your USB has not been mounted and does not have any processes running, then run the command ```sudo mkfs.ext4 /dev/sdb1``` Note: this will delete any files that are on the USB so relocate files if necessary.
6. Once the filesystem version has been changed, we can mount the usb using the command ```sudo mount /dev/sdb1 /mnt``` Note: the name of your partition of your USB may not be called sdb1. This can be checked using this command ```lsblk```
7. Lastly, we can initialize our usb to support this filesystem encryption library by running the command sudo ```fscrypt setup /mnt```







