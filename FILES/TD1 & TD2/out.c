#include <stdio.h>
#include <string.h>

int palindrome(char *s) {
  int len = strlen(s);

  if (len > 0 && s[len - 1] == '\n') {
    len--;
  }

  int i = 0;
  int valueReturn = 1;
  while (i < len / 2 && valueReturn == 1) {
    if (s[i] != s[len - 1 - i]) {
      valueReturn = 0;
    } else {
      i++;
    }
  }
  return valueReturn;
}
