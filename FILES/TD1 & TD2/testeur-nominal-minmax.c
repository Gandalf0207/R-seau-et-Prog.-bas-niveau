#include <stdlib.h>

void minmax (int T[], int n, int *min, int *max);

int
main ()
{
  int T[9] = { 1, 2, 12, 4, 5, 6, -5, 8, 9 };
  int n = 9;
  int min, max;
  minmax (T, n, &min, &max);
  if (min == -5 && max == 12)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
