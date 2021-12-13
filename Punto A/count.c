#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	
    int contador = 1;
	
  //Variable que contendrá la función fork()
    int rc = fork();
	
    if (rc < 0) {
        fprintf(stderr, "Error. Fork ha fallado\n");
        exit(1);
    }else if (rc == 0) {
	//Proceso hijo
        contador+= 5;
    }else {
	//Proceso padre
        contador+= 2;
    }
    printf("%d\n", contador);
    
    return 0;
}
