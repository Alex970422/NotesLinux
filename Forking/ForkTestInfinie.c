#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
do{
pid_t pid;
pid = fork();

printf("PID : %d\n", getppid());
}while(true == true);
	return 0; 
}
