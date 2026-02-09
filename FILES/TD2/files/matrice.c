#include <stdio.h>

#include "matrice.h"


void affiche(struct Matrice mat) {
    for(int i = 0; i < mat.nb_lignes; i++) {
        for(int j = 0; j < mat.nb_colonnes; j++) {
            printf("%3i", mat.valeurs[i][j]);
        }
        printf("\n");
    }
}

// int main() {
//     //TEST

//     // int l1[3] = {1, 2, 3};
//     // int l2[3] = {4, 5, 6};
//     // int *v[2] = {l1, l2};

//     // struct Matrice m = {
//     //     .nb_lignes = 2,
//     //     .nb_colonnes = 3,
//     //     .valeurs = v,
//     // };
//     // affiche(m);
// }
