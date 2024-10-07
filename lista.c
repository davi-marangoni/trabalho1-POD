#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// funcao para iniciar a lista
void initLista(struct list* l) {
    l->head = NULL;
    l->tail = NULL;
}

// funcao para inserir elemento na lista
void inserirNaLista(struct list* l, int valor) {
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

// funcao para printar a lista
void printarLista(struct list* l) {
    struct tlist* aux = l->head;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->next;
    }
    printf("\n");
}

// funcao para inserir a lista em um array
void inserirListaNoArray(struct list* l, struct tlist* array, int tamanho) {
    struct tlist* aux = l->head;
    for (int i = 0; i < tamanho; i++) {
        array[i] = *aux;
        aux = aux->next;
    }
}

// funcao para realizar a troca de posicao dos elementos
void trocar(struct tlist* a, struct tlist* b) {
    struct tlist aux = *a;
    *a = *b;
    *b = aux;
}