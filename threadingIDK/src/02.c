#include <pthread.h>
#include <stdio.h>

typedef struct {
    int nombre1;
    int nombre2;
    int somme;
} thread_args_nb;

void *threadSomme(void *arg) {
    thread_args_nb *data = (thread_args_nb *)arg;
    thread_args_nb pasP = *data;
    data->somme = data->nombre1 + data->nombre2;
    
    return NULL;
}

int main() {
    pthread_t thread;
    thread_args_nb data;
    data.nombre1 = 5;
    data.nombre2 = 6;
    pthread_create(&thread, NULL, threadSomme, &data);
    pthread_join(thread, NULL);
    printf("Somme = %d\n", data.somme);
    return 0;
}
