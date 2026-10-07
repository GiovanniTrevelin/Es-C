#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid = fork();

    if (pid == 0) {


        int numero;
        int primo = 1;

        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        if (numero < 2) {
            primo = 0;
        }

        for (int i = 2; i < numero; i++) {
            if (numero % i == 0) {
                primo = 0;
            }
        }

        if (primo == 1) {
            exit(1);
        }

        if (numero % 2 == 0) {
            exit(2);
        }

        exit(3);

    } else {


        int status;

        wait(&status);

        int risultato = WEXITSTATUS(status);

        if (risultato == 1) {
            printf("Il numero è primo");
        }

        if (risultato == 2) {
            printf("Il numero è pari e non primo");
        }

        if (risultato == 3) {
            printf("Il numero è dispari e non primo");
        }
    }

    return 0;
}