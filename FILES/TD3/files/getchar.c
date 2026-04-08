#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int getchar(void) {
    unsigned char c;
    if (read(0, &c, 1) == 1) {
        return (int)c;
    }
    else return EOF;
}
