#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void print_permissions(mode_t mode) {
    char permissions[3];
    permissions[0] = (mode & S_IRUSR) ? 'r' : '-';
    permissions[1] = (mode & S_IWUSR) ? 'w' : '-';
    permissions[2] = (mode & S_IXUSR) ? 'x' : '-';

    printf("-");
    for (int i = 0; i < 3; ++i) {
        printf("%c", permissions[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    mode_t mode;
    {
        struct stat file_stat;
        if (fstat(fd, &file_stat) != 0) {
            perror("fstat");
            close(fd);
            exit(1);
        }
        mode = file_stat.st_mode;
    } 

    print_permissions(mode);

    close(fd);
    return 0;
}
