#include <stdio.h>
#include <stdlib.h>

int main(){

int *ptr;
int nombre = 5;
ptr = &nombre;
printf(" valeur de ptr:%p addr: %p \n", ptr, &ptr);
printf("valeur de nombre:%d addr: %p\n", nombre, &nombre);


ptr = (int *) malloc(sizeof(int));
printf("adresse ptr avant free: %p\n", ptr);
printf("adresse du nombre: %p\n", &nombre);
free(ptr);
	return 0;}

