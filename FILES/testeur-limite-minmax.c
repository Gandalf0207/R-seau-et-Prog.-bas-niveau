#include <limits.h>
#include <stdlib.h>

void minmax(int T[], int n, int *min, int *max);

int main() {
  int T[2] = {-1, 1};
  int n = 0;
  int min, max;
  minmax(T, n, &min, &max);
  if (min == INT_MAX && max == INT_MIN)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
