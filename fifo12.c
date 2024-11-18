#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

int factorial(int numero)
{
    if (numero == 0)
    {
        return 1;
    }

    else
    {
        return numero * factorial(numero-1);
    }
    
}

int main(int argc, char const *argv[])
{
    int fd1 = open("FIFO1",O_RDONLY);

    if (fd1 == -1)
    {
        return 1;
    }

    int num_leido;
    printf("Leyendo el numero del FIFO1\n");
    if(read(fd1, &num_leido, sizeof(int)) == -1)
    {
        return 2;
    }
    printf("Numero %d leido del FIFO1\n", num_leido);
    close(fd1);
    
    printf("Creando el FIFO2\n");
    if (mkfifo("FIFO2", 0777) == -1)
    {
        if (errno == EEXIST)
        {
            printf("Error al crear el fifo\n");
            return 1;
        }
        
    }
    printf("El FIFO2 se ha creado\n");

    int fd2 = open("FIFO2",O_WRONLY);
    if (fd2 == -1)
    {
        printf("Error al abrir el FIFO2\n");
        return 1;
    }

    printf("Generando el factorial del numero\n");
    int num_factorial = factorial(num_leido);

    printf("El factorial de %d es %d", num_leido, num_factorial);

    if (write(fd2, &num_factorial, sizeof(int)) == -1)
    {
        printf("Error al escribir el factorial\n");
    }

    close(fd2);
    
    return 0;
}


