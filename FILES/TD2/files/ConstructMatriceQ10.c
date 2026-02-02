#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

struct Matrice matrice(int nbl, int nbc, int *valeur)
{
    // création des tableau vide avec malloc
    int** t1 = malloc(sizeof(int) * nbl);
    for (int i = 0; i < nbl; i++)
    {

        // création d'une ligne
        int* t2 = malloc(sizeof(int) * nbc);
        for (int j = 0; j < nbc; j++)
        {
            t2[j] = valeur[i * nbc + j];
        }

        // ajout de la ligne
        t1[i] = t2;
    }
    struct Matrice m1 = {nbl, nbc, t1};

    return m1;
}


void affiche(struct Matrice mat) {
    for(int i = 0; i < mat.nb_lignes; i++) {
        for(int j = 0; j < mat.nb_colonnes; j++) {
            printf("%3i", mat.valeurs[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v1[12] = {
    1, 2, 3, 4,
    2, 4, 6, 8,
    3, 6, 9, 12,
};

struct Matrice m1 = matrice(3, 4, v1);
affiche(m1);
}
