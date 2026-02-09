#include <string.h>		// pour memcmp
#include <stdlib.h>		// pour EXIT_SUCCESS et EXIT_FAILURE

int *nvtab (int[], int);

int
main ()
{
  int T[] = { -6, 3, 0, 80, 2 };
  int *U = nvtab (T, 5);
  if (memcmp (T, U, 5) == 0 && T != U)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
