#include <stdio.h>

int main() {
    int cpt;
    do {
        cpt++;
    } while(cpt % 260 != 0 || cpt%152!= 0);
    printf("%i",cpt);
}
