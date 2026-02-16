#include <stdio.h>
#include <limits.h>


void minmax(int t[], int n, int *pmin, int *pmax) {

    *pmin = INT_MAX;
    *pmax = INT_MIN;

    for(int i = 0; i < n; i++) {
        if (t[i] > *pmax) {
            *pmax = t[i];
        }

        if(t[i] < *pmin) {
            *pmin = t[i];
        }
    }
}
