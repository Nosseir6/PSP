#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid1, pid2;
	
	pid1 = fork();
	
	if (pid1 != 0)
	{
		pid2 = fork();
		if (pid2 != 0)
		{
			wait(NULL);
			wait(NULL);
			printf("Soy el proceso padre\n");
		}
		else
		{
			printf("Soy el proceso hijo con pid: %d\n",getpid());
			printf("El pid de mi padre es: %d\n", getppid());
		}
	}
	else
	{	
		printf("Soy el proceso hijo con pid: %d\n", getpid());
		printf("El pid de mi padre es: %d\n", getppid());
		sleep(10);
		printf("Despierto al finalizar\n");
	}
}
