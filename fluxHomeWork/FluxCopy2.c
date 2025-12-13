#include <stdlib.h>
#include <stdio.h>

int main(){
	char *text;
text = (char*)malloc((1000) * sizeof(char));
while(scanf("%s", text) != EOF ){
fprintf(stderr,"%s\n", text);
fprintf(stdout,"%s\n", text);}
	return 0;}

	
