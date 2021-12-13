#include <stdio.h>
#include <unistd.h> // para utilizar el fork
#include <sys/types.h> // Para el pid_t
#include <sys/wait.h> // para utilizar el wait



pid_t pid;

int fibonacci(int indice){
  pid = fork();
  if(indice>1 && pid == 0){
    wait(NULL);
    return fibonacci(indice-1)+fibonacci(indice-2);
  }else{
    wait(NULL);
    return indice;
  }
}

int main(void) {

  printf("%d\n",fibonacci(25));
  return 0;
}

