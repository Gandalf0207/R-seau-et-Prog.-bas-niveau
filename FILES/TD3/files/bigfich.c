#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Prend en argument une liste de noms de fichiers et affiche le nom du plus grand d'entre eux.
 * Le nombre de noms de fichiers passé en argument doit être au moins 1 mais peut être arbitrairement grand.
 */
int main(int argc, char **argv) {


    if(argc < 2) {
        printf("opérande de fichier manquant");
        exit(1);
    }

    struct stat buf;


    char* maxName =argv[2];
    int maxLength = 0;
    for(int i = 2; i < argc; i++) {
        if(stat(argv[i], &buf)==0) { // pas de soucis
            if(buf.st_size > maxLength) {
                maxLength = buf.st_size;
                maxName = argv[i];
            }
        }
        else {
            perror(argv[i]);
        }
    }
    printf("%s\n", maxName);
    return 0;
}
