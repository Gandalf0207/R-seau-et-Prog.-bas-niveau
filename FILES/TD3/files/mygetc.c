#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

const BUF_SIZE = 5;

/**
 * Retourne le prochain caractère du fichier désigné par le descripteur fd sous forme d'entier (c'est à dire
 * retourne son code ASCII), ou retourne -1 en cas de fin du fichier ou de problème à la lecture.
 *
 * @param fd descripteur de fichier ouvert en lecture
 * @return code ASCII du caractère lu
 */
int mygetc(int fd) {
    char c;
    read(fd, c, 1);

    int value = c;
    return value;
}

/**
 * Retourne le prochain caractère du fichier désigné par le descripteur fd sous forme d'entier (c'est à dire
 * retourne son code ASCII), ou retourne -1 en cas de fin du fichier ou de problème à la lecture.
 *
 * @param fd descripteur de fichier ouvert en lecture
 * @return code ASCII du caractère lu
 */
int mygetc2(int fd) {
    static char* tabLecture;
    static int lecture = 0;
    int value;

    if(lecture == 0) {
        read(fd, tabLecture, BUF_SIZE);
    }

    value = tabLecture[lecture];

    if(lecture == BUF_SIZE) {
        lecture = 0;
        lseek(fd, BUF_SIZE, SEEK_SET)
    }

    return value; // cette ligne est à changer (elle n'est là que pour que le programme compile correctement)
}

int main() {
    int fd = open("test.txt", O_RDONLY);
}
