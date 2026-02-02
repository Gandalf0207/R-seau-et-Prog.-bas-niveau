#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int lngcha(char*);

int main() {
  if (lngcha("Bonjour") == 7 && lngcha("Bonjour tout le monde !") == 23)
    return EXIT_SUCCESS; // OK
  else return EXIT_FAILURE; // ÉCHEC
}
