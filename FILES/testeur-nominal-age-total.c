#include <stdlib.h>
#include "famille.h"

int main() {
    struct Personne p1 = {"Xavier", 45, 1.80};
    struct Personne p2 = {"Nathalie", 42, 1.65};

    int nbe = 3;
    struct Personne* enfants = malloc(nbe * sizeof(struct Personne));

    enfants[0].nom = "Sphanle";
    enfants[0].age = 13;
    enfants[0].taille = 1.66;

    enfants[1].nom = "Dayvid";
    enfants[1].age = 10;
    enfants[1].taille = 1.40;

    enfants[2].nom = "Enzo";
    enfants[2].age = 8;
    enfants[2].taille = 1.30;

    struct Famille uneFamille = {"Dupont", p1, p2, nbe, enfants};

    int cible = 118; // résultat attendu : 45 + 42 + 13 + 10 + 8 = 118

    int resultat = age_total(uneFamille);

    free(enfants);

    if (resultat == cible) {
        return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }

}
