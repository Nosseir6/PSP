#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t varpid,pidhijoquetermina, pidhijo, pidpadre;


  // Se crea un proceso hijo, la función fork() devuelve:
  // un valor negativo -> si se produce cualquier error
  // 0 -> si estamos en el proceso hijo
  // un valor positivo (pid del hijo) -> si estamos en el proceso padre

  varpid = fork();

  if (varpid == 0 )  //Nos encontramos en Proceso hijo
  {
  	
   pidpadre = getppid();
   wait(pidpadre);
  
   for (int i = 0; i <= 100; i++)
   {
   	printf("Hijo %d", i);
   	printf("\n");
   }
  
   
  }
  else    //Nos encontramos en Proceso padre
  {
  
   for (int i = 0; i <= 100; i++)
   {
   	printf("Padre %d", i);
   	printf("\n");
   }
   
  }
   exit(0);
}
