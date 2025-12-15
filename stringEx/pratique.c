#include <stdio.h>
#include <unistd.h>

int main(){

	char nom[64] = {0};
	int padding =0;
	int nipSecret = 0xdeadbeef;
	int autre = 0x00000000;
	printf("Bonjour, quel est votre nom?\n");
	read(0,nom,64);
	printf(nom);
	printf("bye\n");
        if (nipSecret == 0){
		printf("vous avez trouver le secret\n");
	}
} 
