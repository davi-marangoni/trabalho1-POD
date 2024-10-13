#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "bubblesort.h"

//bubblesort
void bubblesort(struct tlist* array, int tamanho) {
    int flag = 0;
    for (int i = 0; i < tamanho; i++) {
        flag = 0;
        for (int j = 0; j < tamanho - 1; j++) {
            if (array[j].valor > array[j + 1].valor) {
                trocar(&array[j], &array[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {    
            break;
        }
    }
}