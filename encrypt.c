#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Get the file path from the command-line argument
    char *file_path = argv[1];

    
    char encrypted_file[512];
    snprintf(encrypted_file, sizeof(encrypted_file), "%s.enc", file_path);  
   
    char openssl_command[1024];
    snprintf(openssl_command, sizeof(openssl_command),
             "openssl aes-256-cbc -salt -a -e -in \"%s\" -out \"%s\"",
             file_path, encrypted_file);

    int ret = system(openssl_command);


    return 0;
}
