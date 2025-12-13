#include <stdio.h>
#include <stdlib.h>

char magic = 'A';

void win() {
    printf("Bravo ! magic = %c -> Flag : cst{FORMAT_STRING_OK}\n", magic);
    exit(0);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    char buf[64];

    printf("Voici magic : %c\n", magic);
    printf("Ton input : ");
    fgets(buf, sizeof(buf), stdin);

    printf(buf, &magic);

    if (magic == 'B') {
        win();
    } else {
        printf("magic = %c (encore 'A')\n", magic);
    }
}

