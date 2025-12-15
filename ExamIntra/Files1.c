#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char *argv[])
{
FILE *fd;

fd = fopen(argv[1] , "w");
fwrite("bonjour\n",1,9,fd);
fclose(fd);

return 0;
}
