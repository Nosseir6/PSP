#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>
#include <errno.h>



int main()
{
    
    if (mkfifo("FIFO1", 0777) == -1)
    {
        if (errno == EEXIST)
        {
            printf("Error al crear el fifo\n");
            return 1;
        }
        
    }

    printf("Abriendo...\n");
    int fd1 = open("FIFO1", O_WRONLY);
    if (fd1 == -1)
    {
        return 1;
    }
    
    printf("Abierto...\n");
    int num_aleatorio;

    time_t t;
    srand((unsigned) time(&t));
    //Generamos numero aleatorio entre 0 y 10 
    num_aleatorio=rand() % 10 +1;
    printf("Escribiendo el numero aleatorio %d\n", num_aleatorio);

    if (write(fd1, &num_aleatorio, sizeof(num_aleatorio)) == -1)
    {
        printf("Error al escribir el contenido en el fichero\n");
        return 2;
    }
    printf("Escrito\n");
    close(fd1);

    int fd2;
    while ((fd2 = open("FIFO2", O_RDONLY)) == -1 )
    {
        if (errno != ENOENT)
        {
            printf("Error al abrir FIFO2");
            return 3;
        }
        
        sleep(1);
    }
    
    printf("Abriendo el archivo con el factorial\n");
    int num_factorial;

    if (read(fd2, &num_factorial,sizeof(num_factorial)) == -1)
    {
        printf("Error al leer el numero factorial del FIFO2\n");
        return 2;
    }
    
    printf("El fatorial del numero %d es: %d\n", num_aleatorio, num_factorial);
    close(fd2);

    unlink("FIFO1");
    unlink("FIFO2");
    return 0;
}
