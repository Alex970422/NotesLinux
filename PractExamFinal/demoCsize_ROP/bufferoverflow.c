#include <stdio.h>
#include <stdlib.h>

void secret(void) {
    puts("🔥 Bravo, vous avez atteint la fonction SECRETE !");
    system("/bin/sh");
}

void vuln(void) {
    char padding[8] = "AAAAAAA\0";
    char buffer[32];
    int i = 0x1337;

    puts("Entrez votre message :");
    gets(buffer);

    printf("Vous avez entré : %s\n", buffer);
}

int main(void) {
    puts("Presque fini la pratique !");
    vuln();
    puts("Fin normale du programme.");
    return 0;
}
