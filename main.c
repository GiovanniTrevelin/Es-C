#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 1; i <= 5; i++) {
            printf("Figlio: %d", i);
            sleep(1);
        }
        exit(0);

    } else {
        wait(NULL);
        for (int i = 6; i <= 10; i++) {
            printf("Padre: %d", i);
            sleep(1);
        }
    }
    return 0;
}