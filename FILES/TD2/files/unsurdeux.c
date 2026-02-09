#include <stdio.h>
#include <stdlib.h>


int* unsurdeux(int* tab, int n) {
    int* tab2 = malloc(sizeof(int)*(n/2));
    for(int i = 0; i < n; i++) {
        if(i %2 == 0) {
            tab2[i/2] = tab[i];
        }
    }
    return tab2;
}
