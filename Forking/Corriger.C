#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define CHILD_PROCESS_ID 0



int child_function(){
	printf("fonction enfant \n");
	return 42;
}
int parent_function(){
	printf("fonction parent \n");
	return 1;
}
int main() {
	printf("Bonjour\n");

	pid_t fID =fork();

	if (fID < 0){
		exit(1);
	}
if(fID == CHILD_PROCESS_ID) {
child_function();
}else { parent_function();
int status_enfant;
wait(&status_enfant);
printf("Child exited with status : %d\n", WEXITSTATUS(status_enfant));
}

return 0;
}

