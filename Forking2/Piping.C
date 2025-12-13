#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define CHILD_PROCESS_ID 0

int child_function(int *fd){
	printf("fonction enfant \n");
	close(fd[1]);
	char msg[20];
	read(fd[0],msg,20);
	printf("message : %s\n",msg);
	return 42;
}
int parent_function(){
	printf("fonction parent \n");
	return 1;
}

int main() {
	printf("Bonjour\n");
int fd[2];

int pErr = pipe(fd);
if (pErr == -1){
	exit(1);
}

pid_t fID =fork();

	if (fID < 0){
		exit(1);
	}

if(fID == CHILD_PROCESS_ID) {
child_function(fd);
}else { parent_function();
int status_enfant;

char msg[20] = "Hello World\n";
close(fd[0]);
write(fd[1],msg,20);



wait(&status_enfant);
printf("Child exited with status : %d\n", WEXITSTATUS(status_enfant));
}

return 0;
}

