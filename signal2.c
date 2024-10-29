#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int cont = 0;

void signal_handler(int numero)
{
	cont += 5;
	printf("Han transcurrido %d segundos \n", cont);
	alarm(5);

}


int main()
{
	
	signal(SIGALRM,signal_handler);
	alarm(5);	
	while(1)
	{
		sleep(1);
	}
	return 0;
}
