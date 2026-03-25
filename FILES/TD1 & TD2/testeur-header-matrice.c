int main() {
  struct Matrice M;
  M.nb_lignes = 2;
  M.nb_colonnes = 3;
  int l1[3] = {1, 2, 3};
  int l2[3] = {4, 5, 6};
  int* v[2] = {l1, l2};
  M.valeurs = v;
  affiche(M);
}
