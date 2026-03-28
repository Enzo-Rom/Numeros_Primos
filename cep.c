#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

//Bilhao 1000000000, Milhao 1000000

struct AYN //All you need is love
{
    size_t n;
    size_t raizn;
    bool *is_prime;
};

void* pmod5(void * arg1){
    struct AYN *ayn = (struct AYN *)arg1;
    for (size_t i = 5; i < ayn->n; i=i+6)
    {
        ayn->is_prime[i] = true;
    }
    return NULL;
}
void* pmod1(void * arg1){
    struct AYN *ayn = (struct AYN *)arg1;
    for (size_t i = 1; i < ayn->n; i=i+6)
    {
        ayn->is_prime[i] = true;
    }
    return NULL;
}
void* dmod5(void * arg1){
    struct AYN *ayn = (struct AYN *)arg1;
    for (size_t i = 5; i <= ayn->raizn; i=i+6) {
        if (ayn->is_prime[i] == true) {
            for (size_t j = i * i; j <= ayn->n; j = j + i){
                ayn->is_prime[j] = false;
            }
        }
    }
    return NULL;
}
void* dmod1(void * arg1){
    struct AYN *ayn = (struct AYN *)arg1;
    for (size_t i = 1; i <= ayn->raizn; i=i+6) {
        if (ayn->is_prime[i] == true) {
            for (size_t j = i * i; j <= ayn->n; j = j + i){
                ayn->is_prime[j] = false;
            }
        }
    }
    return NULL;
}

int main(){
    time_t t_inicio = time(NULL);
    time_t t_fim;

    struct AYN ayn;
    scanf("%lu", &ayn.n);
    ayn.raizn = sqrt(ayn.n);
    void *malloc(size_t size);
    ayn.is_prime = malloc(ayn.n * sizeof(bool));

    size_t k = 0;

    FILE *file;
    file = fopen("NumerosPrimos2.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    pthread_t thread_pmod5, thread_pmod1, d_pmod5, d_pmod1;

    pthread_create(&thread_pmod5, NULL, pmod5, &ayn);
    pthread_create(&thread_pmod1, NULL, pmod1, &ayn);
    pthread_join(thread_pmod5, NULL);
    pthread_join(thread_pmod1, NULL);

    ayn.is_prime[0] = ayn.is_prime[1] = false;
    ayn.is_prime[2] = ayn.is_prime[3] = true;

    
    pthread_create(&d_pmod5, NULL, dmod5, &ayn);
    pthread_create(&d_pmod1, NULL, dmod1, &ayn);
    pthread_join(d_pmod5, NULL);
    pthread_join(d_pmod1, NULL);

    for (size_t i = 0; i < ayn.n; i++)
    {
        if (ayn.is_prime[i] == true)
        {
            fprintf(file, "%lu - ", i);
            k++;
            if (k % 10 == 0)
            {
                fprintf(file, "\n");
            }
            
        }
    }

    printf("%lu Números Primos \n", k);

    t_fim = time(NULL);
    printf(" Tempo de execucao: %lds\n", t_fim - t_inicio);
    free(ayn.is_prime); 
    fclose(file);
    return 0;
}