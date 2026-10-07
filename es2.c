#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid;

    for (int i = 0; i < 3; i++) {

        pid = fork();

        if (pid == 0) {


            printf("Figlio: PID = %d", getpid());

            sleep(2);

            exit(0);
        }
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    printf("Tutti i figli sono terminati.");

    return 0;
}