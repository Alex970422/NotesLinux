#include <stdio.h>

int gets(char *buf);
void secret(){
	printf("FLAG{flag_exemple}\n");
}

void votre_nom(){
char buffer[16];
printf("entrez votre nom\n");
gets(buffer);
printf("bonjour %s!\n", buffer);
}
int main(){
votre_nom();
return 0;
}

