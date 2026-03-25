#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror(argv[0]);
        return -1;
    }

    char *input = NULL;
    char *output = NULL;
    char *execArgs[argc];
    int cpt = 0;

    //get infos
    for (int i = 1; i < argc; i++) {

        // input file
        if (strcmp(argv[i], "--input") == 0) {
            if (i + 1 < argc) {
                input = argv[i+1];
                i++; // skip de l'argument
            }
        }

        //output file
        else if (strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc) {
                output = argv[i+1];
                i++; // skip de l'argument
            }
        }

        // liste de la commande
        else {
            execArgs[cpt] = argv[i];
            cpt++;
        }
    }

    execArgs[cpt] = NULL; // Fin du tableau pour execvp

    // make processus fils
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) { // Code du FILS

        // entrée
        if (input != NULL) {
            int fdIn = open(input, O_RDONLY);
            if (fdIn < 0) {
                perror("Erreur ouverture input");
                return -1;
            }
            dup2(fdIn, STDIN_FILENO); // Remplace l'entrée standard par le fichier
            close(fdIn);
        }

        // sortie
        if (output != NULL) {
            int fdOut = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fdOut < 0) {
                perror("Erreur ouverture output");
                return -1;
            }
            dup2(fdOut, STDOUT_FILENO); // Remplace la sortie standard par le fichier
            close(fdOut);
        }

        // Exécution de la commande
        if(execvp(execArgs[0], execArgs)) {
            perror("execvp");
            return -1;
        }

    } else { // Code du PÈRE
        waitpid(pid, NULL, 0); // Attend la fin du fils
    }

    return EXIT_SUCCESS;
}
