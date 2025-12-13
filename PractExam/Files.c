#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main(){
FILE *Fd;
char buffer[100];

fd = fopen(FileIn,"r");

fread(buffer ,sizeof(buffer),100, fd);

fclose(fd);

if (strstr(buffer,"secret") != NULL)
{fd = fopen(FileOut , "w");
	fwrite(fd ,25 ,25, "Le secret a ete trouve\n");}

	else
	{printf("nuh huh\n");
	exit(1);}
return 0;
}
