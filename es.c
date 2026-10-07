#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid = fork();

    if (pid == 0) {


        printf("Sono il padre");

        pid_t pid2 = fork();

        if (pid2 == 0) {


            printf("Sono il nipote");
            printf("Il nipote termina");

            exit(0);

        } else {

            wait(NULL);

            printf("Il padre termina");

            exit(0);
        }

    } else {

        wait(NULL);

        printf("Il nonno termina");

        exit(0);
    }

    return 0;
}