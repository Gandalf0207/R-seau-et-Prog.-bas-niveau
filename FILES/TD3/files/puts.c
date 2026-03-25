#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int puts(const char* s) {
    int len = strlen(s);
    write(STDOUT_FILENO, s, len);
    printf("\n");
    return 1;
};
