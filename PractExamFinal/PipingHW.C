#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define CHILD_PROCESS_ID 0

int child_function(int *fd){
	
close(fd[1]);
char X[10];
read(fd[0],X,10);
int x = atoi(X);
char prem;
for(int i = 0;i != x ;i++;)
{
	prem = 0;
	for(int j = 2; j != x; i++;)
	{if(x % j == 0)
		prem = 1;}

	if ((x - i) % 2 == 0)
	{printf("pair et pas premier :%d\n",(x - i));}
	else
	{if (prem == 0)
		{printf("impair et pas premier:%d\n",(x - i));}
	 else{printf(printf("impair et premier:%d\n",(x - i));}}
	printf("ni pair ou impair et ni premier ni pas premier: 0\n");
	return 1;}

int parent_function(int *fd)
{
return 1;}
int main()
{
char X[10];
printf("Entrez un nombre\n");
scanf("%s",X);

int fd[2];

int pErr = pipe(fd);
if (pErr == -1){exit(1);}
pid_t fID =fork();
	if (fID < 0){exit(1);}

if(fID == CHILD_PROCESS_ID) {
child_function(fd);
}else{parent_function();}
int status_enfant;

close(fd[0]);
write(fd[1],X,10);

wait(&status_enfant);
printf("Child exited with status : %d\n", WEXITSTATUS(status_enfant));
return 0;}}

