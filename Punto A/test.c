#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int contador = 1;
	printf("hello (pid:%d)\n", (int) getpid());
    pid_t rc;
    rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0) {
        printf("hello, I am child of  (pid:%d)\n", (int) getpid());
        contador = 5;
    }else {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        contador = 2;
    }
    printf("%d\n", contador);
    return 0;
}
