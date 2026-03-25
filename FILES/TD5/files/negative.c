#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int lireligne(int fd, unsigned char *buffer, int size) {
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
  unsigned char *buffer =
      malloc(sizeof(unsigned char) * 4096); // buffer de lecture

  if (argc != 3) {
    perror("Nombre d'argument invalid");
    return -1;
  }

  char *file1 = argv[1];
  char *file2 = argv[2];

  fd_in = open(file1, O_RDONLY);
  fd_out = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (fd_in < 0 || fd_out < 0) {
    perror(fd_in < 0 ? file1 : file2);
    return -1;
  }

  // écriture des infos dans le nouveau fichier.
  for (int i = 0; i < 3; i++) {
    nbread = lireligne(fd_in, buffer, 4096);
    write(fd_out, buffer, nbread);
  }

  // fork (elt nouveau)
  int pid;
  pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  // aide demandé
  if (pid == 0) { // le fils
    // Il lit la suite du fichier et l'écrit telle quelle
    while ((nbread = read(fd_in, buffer, 4096)) > 0) {
      write(fd_out, buffer, nbread);
    }
    exit(0);
  } else { // le père
    // Il lit AUSSI la suite du fichier et applique le négatif
    while ((nbread = read(fd_in, buffer, 4096)) > 0) {
      for (int i = 0; i < nbread; i++) {
        buffer[i] = 255 - buffer[i]; // Transformation
      }
      write(fd_out, buffer, nbread);
    }
  }

  close(fd_in);
  close(fd_out);
  return 0;
}

/**
 * Exo 1 : Q7
 * On est face à un fichiers coroompue car e parent et le fils partagent la meme
 * tete de lecture et écrivent dans le meme buffer
 *
 * Exo1 : Q8
 * Meme soucis avec une image en couleurs
 *
 *
 *
 *
 */
