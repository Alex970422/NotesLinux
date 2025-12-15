#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// La fonction qui sera exécutée par le thread
void *threadFunction(void *arg) {
    printf("Bonjour, je suis un thread!\n");
    return NULL;
}

int main() {
    pthread_t thread; // Déclaration du thread
    pthread_t thread2;

    int ret_thread = pthread_create(&thread, NULL, threadFunction,
                                    NULL); // Création du thread

    if (ret_thread != 0) {
        perror("Échec de la création du thread");
        return EXIT_FAILURE;
    }

    int ret_thread2 = pthread_create(&thread2, NULL, threadFunction,
                                     NULL); // Création du thread

    // Attente de la fin du thread
    if (pthread_join(thread, NULL) != 0) {
        perror("Échec de l'attente du thread");
        return EXIT_FAILURE;
    }

    printf("Thread terminé avec succès\n");
    return EXIT_SUCCESS;
}
