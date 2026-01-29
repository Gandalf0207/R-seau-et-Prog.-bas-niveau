#include <stdio.h>
#include <string.h>


int palindrome(char *s) {
   int len = strlen(s);

    if (len > 0 && s[len - 1] == '\n') {
        len--;
    }

    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}


int main(){

}
