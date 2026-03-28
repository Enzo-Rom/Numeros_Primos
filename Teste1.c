#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(){
    void *malloc(size_t size);
    int *num_primos;
    num_primos = malloc(1000 * sizeof(int));
    int k = 0; //indice do vetor de primos
    double raiz;
    int eprimo;
    FILE *file;
    time_t t_inicio = time(NULL);
    time_t t_fim;
    
    file = fopen("NumerosPrimos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    for (long i = 2; i < 1000; i++)
    {
        raiz = sqrt(i);
        eprimo = 1;
        for (long j = 0; num_primos[j] <= raiz && num_primos[j] != 0 && eprimo == 1; j++)
        {
            if (i % num_primos[j] == 0)
            {
                eprimo = 0;
            }
        }
        if (eprimo == 1)
        {
            num_primos[k] = i;
            k++;
        }
    }
    fprintf(file, "%d Números Primos - ", k);
    k = 0;
    while (num_primos[k] > 0)
    {
        fprintf(file, "%d - ", num_primos[k]);
        k++;
        if (k % 20 == 0)
        {
            fprintf(file, "\n");
        }
    }
    t_fim = time(NULL);
    printf(" Tempo de execucao: %lds\n", t_fim - t_inicio);
    free(num_primos); 
    fclose(file);
    return 0;
}