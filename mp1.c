#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid, pid_padre, pid_hijo;
	
	pid = fork();
	
	if(pid != 0)
	{
		wait(NULL);
		printf("El pid del hijo era %d\n",pid);
		printf("El pid del padre es %d\n", getpid());
	}
	else
	{
		printf("Nosseir\n");
		printf("El proceso hijo termina\n");
	}
}
