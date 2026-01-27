#include <stdio.h>

int lngcha(char *chaine, int len)
{
    return fgets(chaine, len, stdin);
}
