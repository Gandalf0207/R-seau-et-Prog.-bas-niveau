#include <stdio.h>
int main() {
    int t[2];
    printf("Premiere adresse: %lu,\nseconde adresse: %lu\n",
    (long unsigned) t,
    (long unsigned) (t+1));
}
