#include <stdlib.h>
#include <stdio.h>

int main(){
	char *text;
	int i = 0;
	do {
text = (char*)malloc((3+i) * sizeof(char));
i++;
}
while(scanf("%s", text) != EOF );
fprintf(stderr, text);
fprintf(stdout, text);
	return 0;}

	
