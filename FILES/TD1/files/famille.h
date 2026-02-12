struct Personne {
  char *nom;
  int age;
  float taille;
};

struct Famille {
  char *nom;
  struct Personne pere;
  struct Personne mere;
  int nb_enfants;
  struct Personne *enfants;
};

int age_total(struct Famille);
