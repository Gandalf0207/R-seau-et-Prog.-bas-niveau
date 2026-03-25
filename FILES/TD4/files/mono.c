#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int fdin, fdout; // descripteurs de fichiers en entrée et en sortie
	char buffer[4096];	// buffer utilisée pour les lectures/écritures
	int nbread;	// nombre d'octets lus après chaque appel à read

	if(argc != 3) {
		perror("Nombre d'argument invalid");
		return -1;
	}

	char* file1 = argv[1];
	char* file2 = argv[2];

	// [1] Ouverture des fichiers en entrée et sortie
	// le nom du fichier à lire est passé en premier argument du programme, le
	// nom du fichier dans lequel écrire le résultat est passé en second
	// argument
	fdin = open(file1, O_RDONLY);
	fdout = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fdin < 0 || fdout < 0) {
		perror(fdin < 0 ? file1:file2);
		return -1;
	}


	// [2] Lecture de l'entête du fichier en entrée, modification des données
	// nécessaires dans le buffer et écriture de l'entête modifié dans le
	// fichier en sortie
	nbread = read(fdin, buffer, 44);

	int* x ;
	x = (int *) (buffer + 4);
	*x =( *x - 36 )/ 2 + 36;

	// modif nbrcannaux
	short int* v;
	v = (short int*) (buffer + 22);
	*v = 1;

	// byte per sec
	int* z;
	z = (int *) (buffer + 28);
	*z = *z/2;

	// byte per block
	short int* a;
	a = (short int *) (buffer + 32);
	*a = *a/2;

	// datasize
	int* e;
	e = (int *) (buffer + 40);
	*e = *e/2;

	write(fdout, buffer, 44);

	// [3] Lecture des données du fichier en entrée (par blocs de 4096 octets)
	// et écriture dans le fichier en sortie des octets correspondant aux
	// échantillons du premier canal.
	do {
		// lecture
		nbread = read(fdin, buffer, 4096);

		//deplacement des octect
		for(int i = 0; i < nbread/2; i+=2) {
			int source_index = i*2;
			buffer[i] = buffer[source_index];
			buffer[i+1] = buffer[source_index+1];
		}
		write(fdout, buffer, nbread/2);


	} while (nbread > 0);


	close(fdin);
	close(fdout);
}
