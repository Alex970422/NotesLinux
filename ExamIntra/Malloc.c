#include <stdio.h>
#include <stdlib.h>

int main(){

	char *mess;
	mess = (char*)malloc(50 * sizeof(char));
        printf("entrez une phrase\n");
	scanf("%s", mess);
	printf("la phrase est : %s\n", mess);
	free();
	return 0;}

