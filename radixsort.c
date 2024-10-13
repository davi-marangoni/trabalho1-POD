#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "radixsort.h"

//encontra o maior elemento no array
int maiorElemento(struct tlist* array, int tamanho) {
    int max = array[0].valor;
    for (int i = 1; i < tamanho; i++) {
        if (array[i].valor > max) {
            max = array[i].valor;
        }
    }
    return max;
}

//realiza o counting sort de acordo com o digital atual
void countingSort(struct tlist* array, int tamanho, int expoente) {
    struct tlist output[tamanho];
    int count[10] = {0};

    //conta a ocorrencia de cada digital
    for (int i = 0; i < tamanho; i++) {
        count[(array[i].valor / expoente) % 10]++;
    }

    //calcula a posicao correta de cada elemento no array de saida
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    //cria array de saida
    for (int i = tamanho - 1; i >= 0; i--) {
        output[count[(array[i].valor / expoente) % 10] - 1] = array[i];
        count[(array[i].valor / expoente) % 10]--;
    }

    //copia o array de saida para o array original
    for (int i = 0; i < tamanho; i++) {
        array[i] = output[i];
    }
}

//funcao principal do radix sort
void radixSort(struct tlist* array, int tamanho) {    
    //encontra o maior elemento no array
    int max = maiorElemento(array, tamanho);

    //realiza o counting sort para cada digito
    for (int expoente = 1; max / expoente > 0; expoente *= 10) {
        countingSort(array, tamanho, expoente);
    }
}