#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lireligne(int fd, unsigned char* buffer, int size) {
	ssize_t nbread = read(fd, buffer, size);
	if (nbread == -1) {
		return EXIT_FAILURE;
	}

	int i;
	for (i = 0; i < nbread; i++) {
		if (buffer[i] == '\n') {
			i++;
			break;
		}
	}
	lseek(fd, i - nbread, SEEK_CUR);
	return i;
}


int main(int argc, char **argv) {
    int fd_in;  // descripteur de fichier du fichier ouvert en lecture
    int fd_out; // descripteur de fichier du fichier ouvert en écriture
    int nbread;
    unsigned char *buffer = malloc(4096 * sizeof(unsigned char));    // buffer de lecture

	if(argc != 4) {
		char * str = "nombre d'arguments incorrect\n";
		write(2,str, strlen(str));
		return EXIT_FAILURE;
	}

	char* file1 = argv[1];
	char* file2 = argv[2];
	int value = atoi(argv[3]);

	fd_in = open(file1, O_RDONLY);
	fd_out = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd_in < 0 || fd_out < 0) {
		perror(fd_in < 0 ? file1:file2);
		return EXIT_FAILURE;
	}

	// écriture des infos dans le nouveau fichier.
	for(int i = 0; i < 3; i++) {
		nbread = lireligne(fd_in, buffer, 4096);
		write(fd_out, buffer, nbread);
	}

	do {
		nbread = read(fd_in, buffer, 4096);
		for(int i = 0; i < nbread; i++) {
			if(buffer[i] + value >=255) {
				buffer[i] = 255;
			}
			else if (buffer[i] + value < 0) {
				buffer[i] = 0;
			}
			else {
				buffer[i] += value;
			}
		}
		write(fd_out, buffer, nbread);
	} while(nbread > 0);

    return 0;
}
