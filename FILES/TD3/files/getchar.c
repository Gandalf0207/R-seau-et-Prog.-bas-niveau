#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int getchar(void) {
    char buf[1];
    int err = read(0, buf, 1);
    if(err == 1) return (int)buf[0];
    if(err < 0) perror("getchar");
    return EOF;
}
