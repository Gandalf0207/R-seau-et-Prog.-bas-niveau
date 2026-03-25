#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int lireligne(int fd, unsigned char* buffer, int size) {
	ssize_t nbread = read(fd, buffer, size);
	if (nbread == -1) {
		return -1;
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
    unsigned char* buffer = malloc(4096 * sizeof(unsigned char));    // buffer de lecture

	if(argc != 3) {
		perror("Nombre d'argument invalid");
		return -1;
	}

	char* file1 = argv[1];
	char* file2 = argv[2];

	fd_in = open(file1, O_RDONLY);
	fd_out = open(file2, O_WRONLY |O_CREAT |O_TRUNC, 0644);

	if(fd_in < 0 || fd_out < 0) {
		perror(fd_in < 0 ? file1:file2);
		return -1;
	}

	// écriture des infos dans le nouveau fichier.
	for(int i = 0; i < 3; i++) {
		nbread = lireligne(fd_in, buffer, 4096);
		write(fd_out, buffer, nbread);
	}

	do {
		nbread = read(fd_in, buffer, 4096);
		for(int i = 0; i < nbread; i++) {
			buffer[i] = 255 - buffer[i];
		}
		write(fd_out, buffer, nbread);
	} while(nbread == 4096);

    return 0;
}
