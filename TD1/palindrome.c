#include <stdio.h>

int main(){
    char* list = "kayak";
    printf("%i", palindrome(list));

}

int palindrome(char *s) {
    int len = strlen(s) -1;
    printf("%i", len);

    int i = 0;
    while (i < len/2 + 1) {
        if((s+i) !=(s+len-i)) {
            return 0;
        }
        i++;
    }
    return 1;

}
