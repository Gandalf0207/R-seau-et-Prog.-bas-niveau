#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int i, j, s, tabpid[3];
  printf("[avant fork] PID: %d\n", getpid());
  for (j = 0; j < 3; j++) {
    tabpid[j] = fork();
    if (tabpid[j] != 0) {
      printf("PID: %d, retour fork: %d \n", getpid(), tabpid[j]);
    } else {
      printf("PID: %d \n", getpid());
      printf("Je suis le processus fils %d. Mon tableau de pid contient les entiers %d, %d et %d.\n", getpid(), tabpid[0], tabpid[1], tabpid[2]);
      exit(j);
    }
  }
  for (j = 0; j < 3; j++) {
    i = waitpid(tabpid[j], &s, 0);
    if (i > 0) {
      printf("code de retour %d\n", WEXITSTATUS(s));
      printf("terminé PID: %d\n", i);
    }
    sleep(1);

  }
}

/**
 *
 * Exo1 Q4
 * Ce script permet de créer un tableau de pid et de suivre leurs évolutions
 *
 * Exo 1 Q5
 * la variable s contient le wstatus. Qui est analisable car le 3e args est 0
 * on récup le code grace à WEXITSTATUS
 * lien : https://manpages.debian.org/unstable/manpages-fr-dev/waitpid.2.fr.html
 *
 * Exo 1 Q6
 * Il s'agit des pid des fork, car on leur a donné le tableau à l'indice x pour
 * stocker la valeur leurs de la création du fork. Donc meme si le processus est
 *terminé la valeur reste dans le tableau.
 *
 *
 *
 *
 *
 * ... l'appel système suspend l'exécution du père jusqu'à ce que le fils
 * (dont le PID est tabpid[j]) se termine. La valeur retournée par waitpid
 *  est le PID du fils ayant terminé (et donc en principe égale à tabpid[j]).
 * La valeur retournée par le fils (soit par un return dans la fonction main
 *  soit par la procédure exit) est renseignée par le système dans la variable s
 * du père, mais avec potentiellement d'autres choses... Un seul octet de s
 *contient la valeur retournée par le fils. Pour «isoler» cette valeur, il
 *convient d'utiliser la macro WEXITSTATUS avec s en paramètre. C'est cette
 *macro que la question 5 du sujet vous demande de trouver dans la documentation
 *(man waitpid).
 **/
