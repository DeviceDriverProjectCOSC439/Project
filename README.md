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

<h2>Instructions for setting up encryption library on USB.</h2>

encryption library: https://github.com/google/fscrypt?tab=readme-ov-file#building-and-installing

In terminal run the following commands:
1. ```sudo apt update```
2. ```sudo apt install build-essential libssl-dev libuuid1``` this is to install the runtime dependencies for the encryption library
3. Then, you want to clone the git repo with the following command: ```git clone https://github.com/google/fscrypt.git --recursive```
then navigate into the directory with ```cd fscrypt```
5. Once in the directory, run the ```make``` then install the m4 dependency with ```sudo apt install m4``` ```sudo make install``` command
6. Then, you must setup the config file so that it can be called within your USB's directory, run command ```sudo fscrypt setup```
7. Now we need to mount the USB, but before we can do that we need to make sure that our USB is using the correct linux filesystem. This library requires ext4, but most USB drives come with the vfat file system installed. This although, can be changed. To do so, make sure that your USB has not been mounted and does not have any processes running, then run the command ```sudo mkfs.ext4 /dev/sdb1``` Note: this will delete any files that are on the USB so relocate files if necessary.
8. Once the filesystem version has been changed, we can mount the usb using the command ```sudo mount /dev/sdb1 /mnt``` Note: the name of your partition of your USB may not be called sdb1. This can be checked using this command ```lsblk```
9. We can now initialize our usb to support this filesystem encryption library by running the command ```sudo fscrypt setup /mnt```
10. Now, create a directory within /mnt named whatever you want, in this case I will call it secure, using this command ```sudo mkdir /mnt/secure```
11. From there we can add the fscrypt library to that directory with this command ```sudo fscrypt encrypt /mnt/secure``` this will prompt you with terminal commands to setup a private key. Hit 2, then create a username and private key as you are prompted.
12. For copying from PC to USB, the USB directory needs to be unlocked to grant write privledges using this command ```sudo fscrypt unlock /mnt/secure```








