#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * Copie le contenu du fichier message.txt dans un fichier copie.txt
 */
int main(int argc, char** argv) {


    // check des arguments
    if(argc != 3) {
        if(argc == 1 || argc == 2) {
            printf("opérande de fichier manquant");
            exit(1);
        }
        else {
            printf("nombre d'arguments incorrect");
            exit(1);
        }
    }

    // récup des infos
    char* file = argv[1];
    char* targetFile = argv[2];
    int fd = open(file, O_RDONLY);

    //gestion des erreurs
    if(fd < 0) {
        perror(file);
        exit(1);
    };

    // tableau de stockage mémoire
    char* buf = malloc(sizeof(char)*4096);
    int size;

    // création nouveau fichier
    int fdCopy = open(targetFile, O_WRONLY | O_CREAT, 0644);

    do {
        size = read(fd, buf, 4095); // 32 = taille de traitement

        if(size < 0) {
            exit(1); // il y a eu une erreur
        };

        buf[size] = '\0';
        int value = write(fdCopy, buf, size);

        if(value < 0) {
            exit(1); // il y a eu une erreur
        };

    } while (size == 4095);


    close(fd);
}

