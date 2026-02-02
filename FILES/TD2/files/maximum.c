#include <stdio.h>

int maximum(int *t, int n) {
    int max = t[0];

    for(int i = 1; i < n; i++) {
        if (t[i] > max) {
            max = t[i];
        }
    }
    return max;
}


int main() {

}
