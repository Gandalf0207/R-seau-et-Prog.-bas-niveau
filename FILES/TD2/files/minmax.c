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
