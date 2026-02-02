#include <stdlib.h>

int palindrome(char *);

int main() {
  if (palindrome("neige") == 0 && palindrome("pommes") == 0 &&
      palindrome("elle") == 1 && palindrome("ressasser") == 1)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}
