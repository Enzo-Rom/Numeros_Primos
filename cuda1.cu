#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

//Bilhao 1000000000, Milhao 1000000

__global__ void cuda_main(AYN *ayn){
    int i = threadIdx.x;
    ayn->is_prime[i*6+1] = true;
    ayn->is_prime[i*6+5] = true;

    return NULL;
}

int main(){
    int i;
    clearv <<<1, 10>>> (i);
    cudaDeviceSynchronize();

    return 0;
}