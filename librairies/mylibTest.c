#include <stdio.h>

int add_custom(int a ,int b);

int main(){
	int a = 5;	
	int b = 10;
	int somme = add_custom(a,b);
	printf("la somme de %d et %d est %d\n", a, b, somme);
	return 0;
}
