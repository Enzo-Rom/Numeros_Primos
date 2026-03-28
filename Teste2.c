#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAMANHO 1000000
int main(){
    void *malloc(size_t size);
    int *num_primos;
    int *num_naturais;
    num_naturais = malloc(TAMANHO * sizeof(int));
    num_primos = malloc(TAMANHO * sizeof(int));
    int k = 0; //indice do vetor de primos
    double raiz;
    long i;
    int eprimo;
    FILE *file;
    time_t t_inicio = time(NULL);
    time_t t_fim;
    
    file = fopen("NumerosPrimos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    //inicializando com 0
    for (i = 0; i < TAMANHO; i++)
    {
        num_naturais[i] = i + 2;
    }
    
    for (i = 0; i < TAMANHO && k < TAMANHO; i++)
    {
        while (num_naturais[k] == 0)
        {
            k++;
        }
        num_primos[i] = num_naturais[k];
        for (long j = num_primos[i] - 2; j < TAMANHO; j++)
        {
            if (num_naturais[j] != 0)
            {
                if (num_naturais[j] % num_primos[i] == 0)
                {
                    num_naturais[j] = 0;
                }
            }
        }
    }
    fprintf(file, "%ld Números Primos: \n", i);
    k = 0;
    while (num_primos[k] > 0 && k < TAMANHO)
    {
        fprintf(file, "%d - ", num_primos[k]);
        k++;
        if (k % 10 == 0)
        {
            fprintf(file, "\n");
        }
    }
    t_fim = time(NULL);
    printf(" Tempo de execucao: %lds\n", t_fim - t_inicio);
    free(num_primos); 
    free(num_naturais); 
    fclose(file);
    return 0;
}