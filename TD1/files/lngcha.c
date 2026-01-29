#include <stdio.h>

int lngcha(char *chaine)
{
    int cpt;
    do {
        cpt++;
    } while(&chaine[cpt] != "\0");
    return cpt-1;
}

int main() {

}
