#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Lit une ligne du fichier correspondant au descripteur passé en argument jusqu'à lire un retour à la ligne ('\n') ou
 * avoir lu size caractères.
 *
 * @param fd descripteur de fichier ouvert en lecture
 * @param s buffer dans lequel les octets lus sont écrits
 * @param size nombre maximum d'octets à lire
 * @return le nombre d'octets effectivement lus, ou -1 en cas d'erreur.
 */
int lireligne(int fd, char *s, int size) {

    if(fd < 0) {
        return -1;
    }

    int cpt = 0;
    char c[size];


    int a = read(fd, c, size);

    if(a < 0) {
        return -1;
    };

    if(a < 0) {exit(1);};

    do{
        s[cpt] = c[cpt];
        cpt ++;

    } while (c[cpt] != '\n' && cpt < size);

    int p = lseek(fd, cpt, SEEK_SET);
    if(p < 0) {
        return -1;
    };

    if(cpt < size) {
        s[cpt] = '\n';
    }

    return p +1;

}

