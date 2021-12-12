#include <stdio.h>
#include <unistd.h> // para utilizar el fork
#include <sys/types.h> // Para el pid_t
#include <sys/wait.h> // para utilizar el wait

#include "maxrand.h" // La librería que dio el profe para los números random


pid_t pid;

int main(void) {

  printf("[%d] Primera impresión\n", getpid());
  pid = fork();
  
  if (pid == -1){
    printf("Sucedió un error");
    return -1;
  }else if(pid == 0){
    int v = maxrand(10);
    printf("[%d] Soy el hijo, y el valor aleatorio es: %d\n", getpid(),v);
    return v;
  }else{
    int valorDelHijo;
    printf("[%d] Soy el padre\n", getpid());
    wait(&valorDelHijo); 
    printf("[%d] mi hijo salió con el código %d\n",getpid(), WEXITSTATUS(valorDelHijo));
    if(WIFEXITED(valorDelHijo)==1){
      printf("[%d] La salida del hijo salió correcta, puesto que el resultado fue de %d\n",getpid(),WIFEXITED(valorDelHijo));
    }// R// La validación de salida quiere decir que la obtención del valor por medio del wait con el parámetro de tipo entero dentro de dicha función resultó correcto, dando como retorno el valor de 1 (caso contrario daría 0 o false)
  }

  printf("[%d] Terminó el programa\n", getpid());

  return 0;
}