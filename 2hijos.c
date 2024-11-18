#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	
	pid_t pid, pr_padre, pr_hijo1, pr_hijo2;
	
	pid = fork();

	if(pid == 0){
		printf("Soy el proceso hijo que printa impares");
		for(int i = 1; i <= 100; i += 2)
		{
			printf("%d\n", i);
		}

	}
	else
	{
		pid_t pid_nuevo_hijo;
		pid_nuevo_hijo = fork();
		if (pid_nuevo_hijo == 0)
		{
			printf("Estoy en el proceso hijo que printa pares");
			for(int i = 2; i <= 100; i += 2)
			{
				printf("%d\n", i);
			}
		}
		else{
			wait(NULL);
			wait(NULL);
			printf("Estoy en el proceso padre\n");
		}
	}
}
