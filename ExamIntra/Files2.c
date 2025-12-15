#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char *argv[])
{
FILE *fd;
char buffer[100];

fd = fopen(argv[1] , "r");
fread(buffer,sizeof(buffer),100,fd);
printf("%s",buffer);
return 0;
}
