#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "bubblesort.h"
#include "quicksort.h"
#include "radixsort.h"
#include "fila.h"

int main() {
    //inicia o array original
    int array[10] = {23,65,2,4,56,43,12,45,78,34};

    //tamanho do array original
    int tamanho = sizeof(array)/sizeof(array[0]);

    //inicia a lista original
    struct list l;
    initLista(&l);

    //insere os elementos do array em uma lista
    for (int i = 0; i < tamanho; i++) {
        inserirNaLista(&l, array[i]);
    }
    
    //------------------------------------------------------------------
    //                          bubblesort
    //------------------------------------------------------------------

    //copia os elementos da lista para o array que sera ordenado no bubblesort
    struct tlist arrayBubbleSort[tamanho];
    inserirListaNoArray(&l, arrayBubbleSort, tamanho);

    //ordena o array
    bubblesort(arrayBubbleSort, tamanho);

    //inicia fila do bubblesort
    struct queue filaBubbleSort;
    iniciarFila(&filaBubbleSort);

    //insere os elementos ordenados no array na fila
    for (int i = 0; i < tamanho; i++) {
        inserirElementos(&filaBubbleSort, arrayBubbleSort[i].valor);
    }


    //------------------------------------------------------------------
    //                          quicksort
    //------------------------------------------------------------------

    //copia os elementos da lista para o array que sera ordenado no quicksort
    struct tlist arrayQuickSort[tamanho];
    inserirListaNoArray(&l, arrayQuickSort, tamanho);

    //ordena o array
    quicksort(arrayQuickSort, tamanho);

    //inicia fila do quicksort
    struct queue filaQuickSort;
    iniciarFila(&filaQuickSort);

    //insere os elementos ordenados no array na fila
    for (int i = 0; i < tamanho; i++) {
        inserirElementos(&filaQuickSort, arrayQuickSort[i].valor);
    }


    //------------------------------------------------------------------
    //                          radixsort
    //------------------------------------------------------------------

    //copia os elementos da lista para o array que sera ordenado
    struct tlist arrayRadixSort[tamanho];
    inserirListaNoArray(&l, arrayRadixSort, tamanho);

    //ordena o array
    radixSort(arrayRadixSort, tamanho);

    //inicia fila do radixsort
    struct queue filaRadixSort;
    iniciarFila(&filaRadixSort);

    //insere os elementos ordenados no array na fila
    for (int i = 0; i < tamanho; i++) {
        inserirElementos(&filaRadixSort, arrayRadixSort[i].valor);
    }

    //------------------------------------------------------------------
    //                    Printa Filas Ordenadas
    //------------------------------------------------------------------

    printf("Fila da ordenacao realizada pelo bubblesort: \n");
    imprimirFila(&filaBubbleSort);
    printf("Fila da ordenacao realizada pelo quicksort: \n");
    imprimirFila(&filaQuickSort);
    printf("Fila da ordenacao realizada pelo radixsort: \n");
    imprimirFila(&filaRadixSort);

    return 0;
}