#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int contador = 1;
  
    int rc = fork();
	
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0) {
        contador+= 5;
    }else {
        contador+= 2;
    }
    printf("%d\n", contador);
    
    return 0;
}
