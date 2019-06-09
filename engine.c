// engine.c

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello world\n");

    int fd = open("./file.txt", O_RDWR | O_CREAT);
    if (!fd) {
        perror("open");
    }
    write(fd, "abcde", 5);

}
