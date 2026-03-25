#include <stdio.h>  // pour printf...
#include <stdlib.h> // pour malloc...
#include <unistd.h>

/* pour wait */
#include <sys/types.h>
#include <sys/wait.h>

#include <string.h> // pour strcmp

/*
Donnée : un tableau argv de n chaînes de caractères tel qu'il existe un indice
1<i<n-1 avec argv[i] égal à "--pipe" et argv[n]==NULL Résulat : retourne un
tableau T de chaînes de caractères tel que T[0]==argv[1], T[1]==argv[2]...
T[i-1]==NULL
 */
char **premiervecteurdarguments(char *argv[]) {
  int i = 0;
  while (strcmp(argv[i], "--pipe") != 0) {
    i++;
  }
  printf("i=%d", i);
  char **vecteur = (char **)malloc((i - 1) * sizeof(char *));
  int j;
  for (j = 0; j < i - 1; j++) {
    vecteur[j] = argv[j + 1];
  }
  printf("j=%d", j);
  vecteur[j] = NULL;
  return vecteur;
}

/*
Donnée : un tableau argv de n chaînes de caractères tel qu'il existe un indice
1<i<n-1 avec argv[i] égal à "--pipe" et argv[n]==NULL Résulat : retourne un
tableau T de chaînes de caractères tel que T[0]==argv[i+1], T[1]==argv[i+2]...
T[n-i-1]==NULL
 */
char **deuxiemevecteurdarguments(char *argv[]) {
  int i = 0;
  while (strcmp(argv[i], "--pipe") != 0) {
    i++;
  }
  i++;
  int j = 0;
  while (argv[i + j] != NULL)
    j++;

  char **vecteur = malloc(j * sizeof(char *));
  for (int k = 0; k < j; k++) {
    vecteur[k] = argv[i + k];
  }
  vecteur[j] = NULL;
  return vecteur;
}

int main(int argc, char *argv[], char *envp[]) {
  char **argv1 = premiervecteurdarguments(argv);
  char **argv2 = deuxiemevecteurdarguments(argv);

  int tube[2];
  if (pipe(tube) == -1) {
    perror("pipe");
    return EXIT_FAILURE;
  }

  int f1 = fork();
  if (f1 == -1) {
    perror("fork");
    return EXIT_FAILURE;
  }

  if (f1 == 0) { // CODE POUR LE PREMIER ENFANT : avec dup2, perror et execvp
    printf("Je suis le premier enfant...\n");

    // copie fd
    close(tube[0]);
    int fd = dup2(tube[1], 1);
    if (fd < 0) {
      perror("dup2");
    }
    close(tube[1]);
    execvp(argv1[0], argv1);
  } // FIN CODE PREMIER ENFANT

  else { // CODE POUR LE PÈRE
    int f2 = fork();
    if (f2 == -1) {
      perror("fork");
      return EXIT_FAILURE;
    }

    if (f2 == 0) { // CODE POUR LE DEUXIÈME ENFANT : avec dup2, perror, close et
                   // execvp
      printf("Je suis le deuxième enfant...\n");

      // copie fd
      close(tube[1]);
      int fd = dup2(tube[0], 0);
      if (fd < 0) {
        perror("dup2");
      }
      close(tube[0]);
      execvp(argv2[0], argv2);

    } // FIN CODE DEUXIEME ENFANT

    else { // CODE POUR LE PÈRE : avec close et waitpid

      close(tube[0]);
      close(tube[1]);      // close des éléments

      waitpid(f1, NULL, 0);
      waitpid(f2, NULL, 0);
    }
  }
}


// on ferme les tubes sinon on ne passe jamais à la suite

