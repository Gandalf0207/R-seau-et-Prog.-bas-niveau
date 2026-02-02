#include <stdio.h>
#include <stdlib.h>

int* copie(int* tab, int n) {
    // int tab2[n];
    int *tab2 = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        tab2[i] = tab[i];
    }
    return tab2;
}


int main() {

}
