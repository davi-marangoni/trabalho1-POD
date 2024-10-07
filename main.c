#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "bubblesort.h"
#include "quicksort.h"

int main() {
    //inicia o array original
    int array[10] = {23,65,2,4,56,43,12,45,78,34};

    //iniciando a lista
    struct list l;
    initLista(&l);

    //transformando o array em uma lista
    for (int i = 0; i < 10; i++) {
        inserirNaLista(&l, array[i]);
    }

    //copiando os elementos da lista para o array que sera ordenado
    struct tlist array2[10];
    inserirListaNoArray(&l, array2, 10);

    //ordenando o array
    bubblesort(array2, 10);

    //imprimindo o array ordenado pelo bubblesort
    for (int i = 0; i < 10; i++) {
        printf("%d ", array2[i].valor);
    }

    printf("\n");

    //copiando os elementos da lista para o array que sera ordenado
    inserirListaNoArray(&l, array2, 10);

    //ordenando o array
    quicksort(array2, 10);

    //imprimindo o array ordenado pelo quicksort
    for (int i = 0; i < 10; i++) {
        printf("%d ", array2[i].valor);
    }

    printf("\n");



    return 0;
}