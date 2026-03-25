#include <stdlib.h>

int *unsurdeux (int[], int);

int
main ()
{
  int T[5] = { 1, 2, 3, 4, 5 };
  int *U = unsurdeux (T, 5);
  if (U[0] == 1 && U[1] == 3 && U[2] == 5)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
