#include <fcntl.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#include <unistd.h>

void sigsegv_handler();
void flag1();
#define BUFFSIZE 32

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    gid_t gid = getegid();
    setresgid(gid, gid, gid);
}

void vuln() {
    char buffer[BUFFSIZE];
    gets(buffer);
}

void printMessage(unsigned int x, char *msg) {
    printf(msg, x);
    fflush(stdout);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    init();
    printMessage(
        1, "%d - Faire un buffer overflow, c'est écrire plus de données que ce qui est prévu dans un buffer.\n");
    printMessage(
        2,
        "%d - Vous devez exploiter un buffer overflow pour gagner ce challenge avec la fonction flag1\n");
    printMessage(
        3,
        "%d Vous devez exploiter un buffer overflow pour gagner ce challenge avec la fonction flag2 et les arguments\n");
    puts("Go:");
    fflush(stdout);
    vuln();
    return 0;
}

void sigsegv_handler() {
    puts("Vous avez segfault le buffer \n ");
    int fd = open("/flag0", O_RDONLY);
    if (fd == -1) {
        exit(EXIT_FAILURE);
    }
    // read and print one char at the time
    char c;
    while (read(fd, &c, 1) == 1) {
        putchar(c);
    }
    puts("\n");
    fflush(stdout);
    close(fd);
    exit(EXIT_FAILURE);
}

asm(".rept 128; nop; .endr");
asm("gadget_flag2: pop %rdi; ret");
asm("flag2_arg1: pop %rsi; ret");
asm("flag2_arg2: pop %rdx; ret");


void flag1() {
    puts("fct flag1");
    int fd = open("/flag1", O_RDONLY);

    if (fd == -1) {
        exit(EXIT_FAILURE);
    }
    // read and print one char at the time
    char c;
    while (read(fd, &c, 1) == 1) {
        putchar(c);
    }
    puts("\n\n");
    fflush(stdout);
    close(fd);
    return;
}

void flag2(unsigned long x,unsigned long y) {
    puts("fct flag2");
    if ((x ^ y) != 0xdeadbeef) {
        puts("Mauvais arguments\n");
        printf("x = %d\n", x);
        printf("y = %d\n", y);
        printf("x ^ y = %d\n", x ^ y);
        return;
    }

    int fd = open("/flag2", O_RDONLY);
    if (fd == -1) {
        exit(EXIT_FAILURE);
    }
    // read and print one char at the time
    char c;
    while (read(fd, &c, 1) == 1) {
        putchar(c);
    }
    puts("\n\n");
    fflush(stdout);
    close(fd);
    exit(EXIT_SUCCESS);
}
