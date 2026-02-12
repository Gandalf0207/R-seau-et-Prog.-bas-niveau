#include <stdio.h>

int main() {
  for (int i = 1; i < 101; i++) {
    if (i % 3 != 0 && i % 7 != 0) {
      printf("%i ", i);
    };
  }
}
