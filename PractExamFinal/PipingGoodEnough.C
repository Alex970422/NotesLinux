#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <ctype.h>

int fctEnfant(int *fd) {
    //read pipe and print msg
    close(fd[1]);
    
    for(int K = 0; K < 5;K++){
	    char result[20];
	    char msg[30];
	    int i = 0;
    read(fd[0], msg, 30);
    printf("yippee%s\n",msg);
      
    for(int m = 0; msg[m] != '\0' ; m++)
   { 
		switch (msg[m]) {
		   case 'a':
	           case 'e':
	 	   case 'i':
		   case 'o':
	           case 'u':
		   case 'y':break;
	           default: result[i] = toupper(msg[m]);
			   //* printf("test%c\n",msg[m]);
			    i++;
			    break;
		}
   }
    result[i + 1] = '\n';
    printf("%s ->  %s\n", msg , result);
    }    
    exit(0);

}

int main() {
    int fd[2];
    char msg[30];
    FILE* file = fopen("/home/alex/PrepExam/PractExamFinal/entrees.txt","r");
    
   //* sortir les lignes via loop 
   if(!file)
   {printf("oh!oh!\n");} 
    
    int pErr = pipe(fd);
    if (pErr == -1) {
        printf("Error creating pipe\n");
        return 1;
    }

    printf("%s\n",msg); 
    if (fork() == 0) {  // Processus enfant
        fctEnfant(fd); 

    } else {  // Processus parent
        //write msg to pipe
	
	    close(fd[0]);
	    for(int K = 0; K < 5; K++)
		 {
        fgets(msg,30,file);
        msg[29] = '\n';	
        write(fd[1], msg, 30);
		 }
	    close(fd[1]);
	int status_enfant;
	wait(&status_enfant);
	
    }
	printf("a\n");

  
    fclose(file);
    return 0;
}
