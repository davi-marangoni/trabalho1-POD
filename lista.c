#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void initList(struct list* l){
    l->head = NULL;
    l->tail = NULL;
}

void insertList(struct list* l, int valor){
    struct tlist* novo = (struct tlist*) malloc(sizeof(struct tlist));
    novo->valor = valor;
    novo->next = NULL;
    if(l->head == NULL){
        l->head = novo;
        l->tail = novo;
    } else {
        l->tail->next = novo;
        l->tail = novo;
    }
}

void printList(struct list* l){
    struct tlist* aux = l->head;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->next;
    }
    printf("\n");
}