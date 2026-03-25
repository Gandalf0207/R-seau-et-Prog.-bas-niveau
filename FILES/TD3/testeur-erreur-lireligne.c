#include <stdlib.h> // pour EXIT_SUCCESS et EXIT_FAILURE

int lireligne(int, char *, int);

int main(int argc, char **argv) {
  char buf[4096];
  int size = 4096;
  int n = lireligne(16, buf, size);
  if (n == -1)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
