#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/**
 * Ouvre le fichier message.txt du répertoire courant et affiche son contenu à l'écran.
 */
int main(int argc, char** argv) {

    if(argc != 2) {
        if(argc == 1) {
            char* text = "opérande de fichier manquant";
            write(STDOUT_FILENO, text, 29);
            return EXIT_FAILURE;
        }
        else {
            char* text = "nombre d'arguments incorrect";
            write(STDOUT_FILENO, text, 30);
            return EXIT_FAILURE;
        }
    }

    char* file = argv[1];

    int fd = open(file, O_RDONLY);
    if(fd < 0) {
        perror(file);
        exit(1); // il y a eu une erreur
    };

        char* buf = malloc(sizeof(char)*32);
        int size;

    do {
        size = read(fd, buf, 31); // 32 = taille de traitement

        if(size < 0) {
            perror("read element");
        };

        buf[size] = '\0';
        write(STDOUT_FILENO, buf, size); // ou p-rintf("%s", buf);
    } while (size == 31);


    close(fd);
    return EXIT_SUCCESS;
}
