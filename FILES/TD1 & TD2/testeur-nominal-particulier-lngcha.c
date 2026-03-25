int lngcha(char *);

int main() {
  int n = lngcha("abc\ndef");

  if (n == 7)
    return 0; // OK
  else
    return 1; // ÉCHEC
}
