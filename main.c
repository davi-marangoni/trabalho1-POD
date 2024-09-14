#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    int array[10] = {23,65,2,4,56,43,12,45,78,34};

    //iniciando a lista
    struct list l;
    initList(&l);

    //transformando o array em uma lista
    for(int i = 0; i < 10; i++){
        insertList(&l, array[i]);
    }

    //imprimindo a lista
    printList(&l);

    return 0;
}