#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int pid = fork();

  if(pid < 0) {
    perror("fork");
    return(EXIT_FAILURE);
  }

  if (pid == 0) { // le fils
    // Processus fils : construire le tableau d'arguments
    // tab = { argv[1], argv[2], ..., argv[argc-1], NULL }
    char *tab[argc]; // taille argc car argc-1 args + NULL
    for (int i = 0; i < argc - 1; i++) {
      tab[i] = argv[i + 1];
    }
    tab[argc - 1] = NULL;
    execvp(argv[1], tab);
  } else { // le père
    int status;
    wait(&status);
  }
}
