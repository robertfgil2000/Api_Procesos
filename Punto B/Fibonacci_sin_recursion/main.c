#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()

{



int a=0, b=1, n=a+b,i;


printf("Agregue el número para hacer la sequencia Fibonacci\n");
scanf("%d", &i);

pid_t pid = fork();
if (pid == 0)
{
    printf("El hijo hace se encarga del Fibonacci\n");
    printf("0 %d ",n);
    while (i>0) {
        n=a+b;
        printf("%d ", n);
        a=b;
        b=n;
        i--;
        if (i == 0) {
            printf("\nEl hijo termina\n");
        }
    }
}
    else 
    {
        printf("El padre espera que el hijo acabe\n");
        waitpid(pid, NULL, 0);
        printf("Padre acaba\n");
    }
    return 0;
}