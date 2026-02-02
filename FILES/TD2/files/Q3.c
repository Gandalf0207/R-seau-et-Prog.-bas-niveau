#include <stdio.h>


void f(int a, int b, int *s, int *p) {
    *s = a + b;
    *p = a * b;
}

int main() {
    int x, y;
    f(12, 4, &x, &y);
    printf("x = %d, y = %d\n", x, y);
}
