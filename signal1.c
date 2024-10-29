#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void sig_handler(int numero)
{
	time_t hora;
	char *fecha;
	time(&hora);
	fecha = ctime(&hora);
	printf("La hora de fin del proceso es: %s", fecha);
	exit(0);
}

int main()
{
	pid_t pid;
	time_t hora;
	char *fecha ;
    	time(&hora);
   	fecha = ctime(&hora) ;

	pid = getpid();
	printf("Proceso iniciado a la hora: %s",fecha);
	signal(SIGINT,sig_handler);

	while(1)
	{
		sleep(1);
	}

	return 0;
}
