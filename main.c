#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "bubblesort.h"

int main() {
    //inicia o array original
    int array[10] = {23,65,2,4,56,43,12,45,78,34};

    //iniciando a lista
    struct list l;
    initList(&l);

    //transformando o array em uma lista
    for (int i = 0; i < 10; i++) {
        insertList(&l, array[i]);
    }

    //copiando os elementos da lista para o array que sera ordenado
    struct tlist array2[10];
    insertListInArray(&l, array2, 10);

    //ordenando o array
    bubblesort(array2, 10);

    //imprimindo o array ordenado pelo bubblesort
    for (int i = 0; i < 10; i++) {
        printf("%d ", array2[i].valor);
    }


    return 0;
}