#ifndef FAMILLE_H
#define FAMILLE_H

#include <stdio.h>

struct Personne
{
    char *nom;
    int age;
    float taille;
};

struct Famille
{
    char *nom;
    struct Personne pere;
    struct Personne mere;
    int nb_enfants;
    struct Personne *enfants;
};

#endif
