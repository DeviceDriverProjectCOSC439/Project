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




