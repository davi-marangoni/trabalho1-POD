#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "bubblesort.h"

void bubblesort(struct tlist* array, int size) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        flag = 0;
        for (int j = 0; j < size - 1; j++) {
            if (array[j].valor > array[j + 1].valor) {
                change(&array[j], &array[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}


void change(struct tlist* a, struct tlist* b) {
    struct tlist aux = *a;
    *a = *b;
    *b = aux;
}