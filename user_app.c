# include <unistd.h>
# include <fcntl.h>

int main(){

    system('sudo apt update');
    system('sudo apt install build-essential libssl-dev libuuid1');
    system('make');
    system('sudo apt install m4');
    system('sudo make install');
    system("sudo fscrypt setup");
    system('sudo mkfs.ext4 /dev/sdb1');
    system('sudo mount /dev/sdb1 /mnt');
    system('sudo fscrypt setup /mnt');
    system('sudo mkdir /mnt/encrypted');
    system('sudo fscrypt encrypt /mnt/encrypted');
    system('sudo fscrypt unlock /mnt/secure');

}
