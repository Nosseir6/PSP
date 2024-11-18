#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

#define PIPE02 "PIPE02"

int main()
{
    int numrandom, numfactorial;
    int fd;

    mkfifo(PIPE02, 0666);

     time_t t;
     srand((unsigned) time(&t));

     numrandom=rand() % 10; 

    //Abre el pipe, genera y envia el número aleatorio al proceso fifo22
     fd = open(PIPE02, O_WRONLY);
     write(fd, &numrandom, sizeof(numrandom));
     close(fd);

     printf("FIFO21: Número : %d\n", numrandom);

    //Abre el pipe y lee el resultado del factorial para fifo22
     fd = open(PIPE02, O_RDONLY);
     read(fd, &numfactorial, sizeof(numfactorial));
     close(fd);

     printf("FIFO21: Factorial : %d\n", numfactorial);

     unlink(PIPE02);

     return 0;
}