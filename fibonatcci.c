#include <stdio.h>

int main() {
int nombre1, nombre2, somme;
int nb_suite = 0;
nombre1 = 0;
nombre2 = 1;
printf("Nombre de la suite:\n");
scanf("%d" , &nb_suite);
printf("0/n1/n");

for(int i=2; i <= nb_suite; i++){
somme = nombre1+nombre2;
printf("%d/n",somme);
nombre1 = nombre2;
nombre 2 = somme;
}
return 0;
}

