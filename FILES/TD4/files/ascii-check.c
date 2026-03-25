#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int fdin;
	char buffer[4096];
	int nbread;
	if(argc != 2) {
		perror("Nombre d'argument invalid");
		return -1;
	}

	char* file1 = argv[1];

	fdin = open(file1, O_RDONLY);

	if(fdin < 0 ) {
		perror(file1);
		return -1;
	}
    int value;
    while(nbread = read(fdin, buffer, 4096) > 0) {

        for(int i = 0; i < nbread; i++) {
            value = buffer[i];
            if(0 > value || value > 127) {
                write(STDOUT_FILENO,"fichier incompatible ASCII", 27);
                return -1;
            }
        }
    }
    write(STDOUT_FILENO,"fichier compatible ASCII", 25);
    // return 0;
}
