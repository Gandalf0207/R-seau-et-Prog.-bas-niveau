#include <stdio.h>
#include <stdlib.h>


int* unsrudeux(int* tab, int n) {
    int* tab2 = malloc(sizeof(int)*(n/2));
    int cpt = 0;
    for(int i = 0; i < n; i++) {
        if(tab[i] %2 == 0) {
            tab[cpt] = tab[i];
            cpt++;
        }
    }
    return tab2;
}

int main() {

}
