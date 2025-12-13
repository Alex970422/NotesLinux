#include <stdio.h>
#include <stdlib.h>

int main(){
	char var[50];
	scanf("%s" , var);
        char *Env_var = getenv(var);

	 if(Env_var = NULL)
	 {printf("la variable n'existe pas\n");}
	else
	{printf("%s\n",Env_var);
	printf("test\n");}
	 	
	return 0;
}
