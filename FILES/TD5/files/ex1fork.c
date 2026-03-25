#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int i;
  printf("PID: %d (avant fork)\n", getpid());

  sleep((unsigned int)5);
  i = fork();
  if (i != 0) { // code du pere
    printf("PID: %d, résultat du fork: %d\n", getpid(), i);
  } else { // code du fils
    printf("PID: %d, résultat du fork: %d \n", getpid(), i);
  }
  // code des deux
  printf("PID: %d (après fork)\n", getpid());
}

/**
 * Exo 1 Q1 :
 * On observe que suite à un fork, le PID de l'élément forké
 * change et augmente de 1.
 *
 * Exo1 Q2 :
 * Le PID change largement, ce n'est plus 1 de plus mais 30-50... en plus
 * Cela est du au fait que l'on attend avant de créer le fork de main
 * Donc le processeur fait d'autre calculs en attendant et lance de nouveaux
 * processus entre temps.
 * Quand on execute le programme, ce dernier "dort" pendant un certain temps
 * ici 5 secondes
 *
 * Exo1 Q3 :
 * On observe que entre le PID de débat et d'arrivé avant et après le fork
 * il y a des processus qui se sont lancé entre : le sleep et le cpuUsage.sh
 *
 *
 *
 *
 *
 **/
