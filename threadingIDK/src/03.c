#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int nombreDepart;
    int nombreMax;
    int threadId;
} Arguments;


// Mutex pour protéger l'accès à la variable partagée
pthread_mutex_t verrou;

// Variable partagée pour stocker le premier nombre premier trouvé
int premierTrouve = 0;

// Vérifie si un nombre est premier
bool estPremier(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Fonction exécutée par les threads
void *trouverPremier(void *arg) {
    Arguments *arguments = (Arguments *)arg;
    int depart = arguments->nombreDepart;
    int max = arguments->nombreMax;

    // Si le nombre de départ est pair, on l'incrémente de 1
    if (depart % 2 == 0) depart++;

    int i; 
    for (i = depart; i <= max ; i += 2) {
        if (premierTrouve!= 0) {
            break;
        }

        if (estPremier(i)) {
            pthread_mutex_lock(&verrou);
            premierTrouve = i;
            printf("Thread %d : Premier trouvé %d\n", arguments->threadId, i);
            pthread_mutex_unlock(&verrou);
            break;
        }
    }
    printf("Thread %d terminé. i est %d\n", arguments->threadId, i);
    return NULL;
}


int main(int argc, char *argv[]) {

    // Prendre en compte les arguments pour le nombre de depart et le nombre max
    if( argc == 3 ) {
        printf("Nombre de départ : %s\n", argv[1]);
        printf("Nombre max : %s\n", argv[2]);

    } else if( argc > 3 ) {
        printf("Trop d'arguments fournis.\n");
        return EXIT_FAILURE;
    } else {
        printf("Nombre de départ et nombre max non fournis.\n");
        return EXIT_FAILURE;
    }

    int nombreDepart = atoi(argv[1]); 
    int nombreMax = atoi(argv[2]); 

    Arguments arguments;
    arguments.nombreDepart = nombreDepart;
    arguments.nombreMax = (nombreMax - nombreDepart) / 2 + nombreDepart;
    arguments.threadId = 1;

    Arguments arguments2;
    arguments2.nombreDepart = arguments.nombreMax + 1;
    arguments2.nombreMax = nombreMax;
    arguments2.threadId = 2;

    pthread_t thread1, thread2;

    // Initialisation du mutex
    pthread_mutex_init(&verrou, NULL);

    // Création des threads
    if (pthread_create(&thread1, NULL, trouverPremier, &arguments) != 0) {
        perror("Échec de la création du thread 1");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thread2, NULL, trouverPremier, &arguments2) != 0) {
        perror("Échec de la création du thread 2");
        return EXIT_FAILURE;
    }

    // Attente de la fin des threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

      // Nettoyage du mutex
    pthread_mutex_destroy(&verrou);

    return EXIT_SUCCESS;
}

