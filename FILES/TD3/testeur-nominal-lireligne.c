// Enzo
#include <stdlib.h> // pour EXIT_SUCCESS et EXIT_FAILURE
#include <string.h> // pour memcmp
#include <unistd.h> // pour STDIN_FILENO (qui vaut 0)

int lireligne(int, char *, int);

int main(int argc, char **argv) {
  char buf[4096];
  int size = 4096;
  int n = lireligne(STDIN_FILENO, buf, size);
  char fub[] = {'/', '/', ' ', 'E', 'n', 'z', 'o', '\n'};
  if (memcmp(buf, fub, 8) == 0 && n == 8)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
