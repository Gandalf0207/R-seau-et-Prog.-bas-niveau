#include <stdio.h>

int main() {
    int tab[3];
    tab[0] = 1;
    tab[1] = 2;

    for(int i = 0; i < 4; i++) {
        printf("à l'indice i = %i, valeur = %i \n", i ,tab[i]);
    };
}
