// search_number.c
// Démo : brute force pour trouver un entier n tel que
// (n * n) == MAGIC.
//
// Étapes suggérées :
// 1) Implémenter une version simple avec une seule boucle dans main.
// 2) Copier ce fichier et le modifier pour utiliser 2 threads.
// 3) Copier encore et le modifier pour utiliser 3 threads.

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

// ----- Paramètres du problème -----

long long init();

// Intervalle de recherche [RANGE_START, RANGE_END]
#define RANGE_START 0LL
#define RANGE_END   500000000LL

static long long KNOWN_SOLUTION = 0;
static long long MAGIC = 0;

// Retourne 1 si n satisfait la propriété, 0 sinon
int check_property(long long n)
{
    long long r = (n * n);
    return (r == MAGIC);
}

long long init() {
    srand(time(NULL));

    uint64_t r1 = rand();
    uint64_t r2 = rand();
    uint64_t r3 = rand();
    uint64_t r4 = rand();

    uint64_t result = (r1 << 45) | (r2 << 30) | (r3 << 15) | r4;
    result = result % RANGE_END;
    printf("KNOWN_SOLUTION = %lld\n", (long long)result);

    return (long long)result;
}

typedef struct thread_data_t {
	long long start;
	long long end;
	int thread_id;
}thread_data_t;

void * thread_travail(void *arg){
	long long n;
	thread_data_t *data = (thread_data_t *)arg;
	
	for (n = data -> start; n < data->end; n++){
		if (check_property(n) == 1){
			printf("found by %d ! n = %lld\n" , data->thread_id , n );
			break;
		}
	}
	
	return NULL;
}

int main(void)
{
    KNOWN_SOLUTION = init();
    MAGIC = (KNOWN_SOLUTION * KNOWN_SOLUTION);

    printf("Recherche d'un entier n dans [%lld, %lld] "
           "tel que (n * n) == %lld\n",
           RANGE_START, RANGE_END, MAGIC);

    pthread_t thread [2];

    pthread_data_t *data = malloc sizeof(thread_data_t(thread_data_t));
    data->start = RANGE_START;
    data->end = RANGE_END / 2;
    data->thread_id =0;

    pthread_data_t *data2  = malloc sizeof(thread_data_t(thread_data_t));
    data->start = RANGE_END / 2;
    data->end = RANGE_END;
    data->thread_id = 1;

    pthread_create(&thread[0],NULL , thread_travail, data);
    pthread_create(&thread[1],NULL , thread_travail, data2);

     pthread_join(thread[0], NULL);
     pthread_join(thread[1],NULL);
    // TODO Étape 1 :
    //  - Écrire une boucle for qui parcourt tous les n de RANGE_START à RANGE_END (exclu).
    //  - Pour chaque n, appeler check_property(n).
    //  - Si check_property renvoie 1 :
    //      * afficher n
    //      * sortir de la boucle (on a trouvé une solution)
    //
    // Ex. de message :
    //   printf("Trouvé ! n = %lld\n", n);

    // TODO Plus tard (Étape threads) :
    //  - Déplacer la boucle dans une fonction de travail.
    //  - Lancer plusieurs threads qui cherchent chacun dans une sous-partie du range.
    //  - Coordiner l'arrêt quand un thread trouve une solution.

    return 0;
}
