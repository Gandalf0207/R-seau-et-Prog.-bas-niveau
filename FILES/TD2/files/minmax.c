#include <stdio.h>


void minmax(int *t, int n, int *pmin, int *pmax) {
    *pmin = t[0];
    *pmax =t[0];

    for(int i = 1; i < n; i++) {
        if (t[i] > *pmax) {
            *pmax = t[i];
        }

        if(t[i] < *pmin) {
            *pmin = t[i];
        }
    }
}

int main() {
    int t[] = {-1, 4, 5, 9, 0, 3, 8, -6, 90, -123};
    int pmin, pmax;

    minmax(t, 10, &pmin, &pmax);
    printf("pmax = %i, pmin = %i\n", pmax, pmin);

}
