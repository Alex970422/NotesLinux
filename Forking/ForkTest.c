#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

pid_t pid;
pid = fork();
pid_t pwait= wait(&status);


printf("PID parent: %d\n", getppid());
printf("PID enfant : %d\n", getpid());
prinf("Process enfant terminer en : %d\n", wait
exit(0);
	return 0; 
}


