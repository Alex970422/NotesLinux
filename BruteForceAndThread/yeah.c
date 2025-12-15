#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct{
	char o_cle;
	char lettre_enc;
	char lettre_recherchee;
	int thread_id;
}t_data;

void * thread_bruteforce(void *arg){
	t_data * data = (t_data *)arg;
	int cle = 0x00;
	while(cle <= 0xFF){
		if((cle ^ data ->lettre_enc) == data -> lettre_recherchee)
		{
		printf("key found by %d: 0x%02X\n",data->thread_id, cle);
                data->o_cle = cle;
		break;
		}
		cle++;
}
}
int main(int argc, char** argv){

	char * file_path = argv[1];
	FILE * file = fopen(file_path, "r");
	if (file == NULL){
 	     perror("error fichier\n");
	     return EXIT_FAILURE;
	}

	char buffer[4];
	fgets(buffer,sizeof(buffer),file);
	printf("Read from file: %s\n", buffer);
	char msg_correct[] = "cst{";

	int cle = 0x00;
	while (cle <= 0xFF) {
        	char msg_test[4];
		cle++;
	}
	pthread_t threads[4];
	t_data *thread_data= malloc(4 * sizeof(t_data));

	for (int i = 0 ; i < 4;i++){
		thread_data[i].lettre_enc = buffer[i];
		thread_data[i].lettre_recherchee = msg_correct[i];
		thread_data[i].thread_id = i;	
	pthread_create(&threads[i], NULL , thread_bruteforce, (void *)&thread_data);
	}


	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);

	free(thread_data);
	thread_data = NULL;
	fclose(file);

return EXIT_SUCCESS;
}
