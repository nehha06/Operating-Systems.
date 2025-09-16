#include <stdio.h>
#include <sys/stat.h>  // for chmod and permission macros
#include <stdlib.h>    // for exit()

int main() {
    char filename[] = "file.txt";

    // Set permissions: rw-rw-r--
    mode_t new_permissions = S_IRUSR | S_IWUSR |   // User: read & write
                             S_IRGRP | S_IWGRP |   // Group: read & write
                             S_IROTH;              // Others: read only

    if (chmod(filename, new_permissions) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        perror("Error changing permissions");
        exit(1);
    }

    return 0;
}

