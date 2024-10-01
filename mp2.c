#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid_hijo, pid_nieto;
	pid_hijo = fork();
	
	if (pid_hijo != 0)
	{
		//Estoy en el proceso padre
		wait(NULL);
		printf("Soy el proceso P1\n");
		printf("Mi pid es: %d\n", getpid());
		printf("El pid de mi hijo es: %d\n", pid_hijo);
	}
	else
	{
		pid_nieto = fork();
		if (pid_nieto != 0 )
		{
			//Estoy en el proceso hijo
			wait(NULL);
			printf("Soy el proceso P2\n");
			printf("Mi pid es: %d\n", getpid());
			printf("El pid de mi padre es: %d\n", getppid());			
		}
		else
		{
			printf("Soy el proceso P3\n");
			printf("Mi pid es: %d\n", getpid());
			printf("El pid de mi padre es: %d\n", getppid());
		}
	}
}
