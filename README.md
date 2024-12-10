<h1> Device driver that automates encrypting and decrypting files when there are moved over to a USB drive. </h1>

<h3> There are a few dependencies that must be met before this is possible </h3>

1. This must take place on a Linux Machine
3. OpenSSL must be installed  ```sudo apt install openssl```
4. Linux Headers must be installed ```sudo apt install linux-headers-$(uname -r)```
5. A C compiler must be installed as well as Makefile tools
6. It is crucial that all of the paths in the ```main.c```, ```script.sh```, ```encrypt.c```, and ```decrypt.c``` are altered to match your device.

<h3> Building the device driver </h3>

1. Generate your public and private key. In the project's Directory, run ```openssl genrsa -out private.key 2048``` then run ```openssl rsa -in private.key -pubout -out public.key``` This creates a public and private key pair using RSA encryption.
2. In the terminal, in the projects directory, run ```make``` then ```sudo make load``` This creates a module that is then loaded into the kernel. 
3. Now, dragging and dropping a file into the USB should encrypt the file. Note that the only way to decrypt the file is by dragging and dropping it to the desktop.
   








