#include <stdio.h>

int lngcha(char* chaine)
{
    int cpt = 0;
    do {
        cpt++;
    } while(chaine[cpt] != '\0');
    return cpt;
}
