#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
#include <string.h>


typedef struct thread_data_t {
	int max;
	FILE * fichier;
	int thread_id;
}thread_data_t;

void * thread_travail(void *arg){
	thread_data_t *data = (thread_data_t *)arg;
	for(int k = 0; k <= data -> max; k++)
         {
	if(k % data->thread_id)
	{
	pthread_mutex_lock;
	fprintf(data -> fichier,"Thread %d : %d\n",data->thread_id , k);
	pthread_mutex_unlock;
	}
	}
	return NULL;
}

int main(int argc , char* argv[])
{
	char * filepath = argv[1];
    FILE * file = fopen(filepath, "w");
    int nbthread = atoi(argv[2]);
    pthread_t thread[nbthread];
    int maximum = atoi(argv[3]);
	
    thread_data_t *data = malloc(sizeof(thread_data_t));
    data->max = maximum ;
    data->fichier = file;

    for(int n = 0 ;n <= nbthread ;n++ ){
    data->thread_id = n;
    pthread_create(&thread[n],NULL , thread_travail, data);
    }

    for(int j = 0 ; j <= nbthread ;j++)
    {
     pthread_join(thread[j], NULL);
    }
    fclose(file);
    return 0;
}
