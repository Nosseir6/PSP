#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int numero)
{
	printf("Ha sonado la alarma");
	alarm(1);
	signal(SIGALRM,signal_handler);
}


int main()
{
	
	signal(SIGALRM,signal_handler);
	alarm(1);	
	while(1)
	{
		sleep(1);
	}
	return 0;
}
