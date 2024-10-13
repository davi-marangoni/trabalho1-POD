#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#include "quicksort.h"

//funcao principal do quicksort
void quicksort(struct tlist* array, int tamanho) {
    //gerador de numeros aleatorios
    srand(time(NULL));
    quicksortRecursivo(array, 0, tamanho - 1);
}

//funcao recursiva do quicksort
void quicksortRecursivo(struct tlist* array, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = parcionar(array, esquerda, direita);
        quicksortRecursivo(array, esquerda, pivo - 1);
        quicksortRecursivo(array, pivo + 1, direita);
    }
}

//parciona o array
int parcionar(struct tlist* array, int esquerda, int direita) {

    //seleciona um indice aleatorio entre esquerda e direita
    int randomIndex = esquerda + rand() % (direita - esquerda + 1);
    // printf("Pivo: %d\n", array[randomIndex].valor);
    
    //troca o pivo aleatorio com o ultimo elemento 
    trocar(&array[randomIndex], &array[direita]);

    int pivo = array[direita].valor;
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; j++) {
        if (array[j].valor < pivo) {
            i++;
            trocar(&array[i], &array[j]);
        }
    }

    trocar(&array[i + 1], &array[direita]);
    return i + 1;
}