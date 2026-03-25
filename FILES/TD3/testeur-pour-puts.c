#include <stdlib.h>

int puts(const char *s);

int main(int argc, char* argv[]){
  int r = puts(argv[1]);
  if (r > 0) return EXIT_SUCCESS;
  else return EXIT_FAILURE;
}
