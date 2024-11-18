#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


void mostrar_FechaYHora(int signal)
{
   time_t hora;
   time(&hora);
   char * fecha = ctime(&hora);
   printf("Fin del proceso %d : %s",getpid(),fecha);
   exit(0);
}

int main()
{
   time_t hora;
   time(&hora);
   char * fecha = ctime(&hora);
   printf ("Inicio del proceso %d : %s", getpid(), fecha);

   signal(SIGINT, mostrar_FechaYHora);

   while (1)
   {
      pause();
   }
   return 0;
}
