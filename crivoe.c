#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
int main(){
    FILE *file;
    time_t t_inicio = time(NULL);
    time_t t_fim;
    void *malloc(size_t size);
    size_t n, k = 0;
    scanf("%lu", &n);
    size_t rn = sqrt(n); 
    bool *is_prime;
    is_prime = malloc(n * sizeof(bool));
    file = fopen("NumerosPrimos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    for (size_t i = 1; i < n; i=i+2)
    {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    for (size_t i = 3; i <= rn; i=i+2) {
        if (is_prime[i] == true) {
            for (size_t j = i * i; j <= n; j = j + i){
                is_prime[j] = false;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (is_prime[i] == true)
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
    free(is_prime); 
    fclose(file);
    return 0;
}

