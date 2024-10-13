#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"

//inicia a fila
void iniciarFila(struct queue *f) {
    f->head = NULL;
    f->tail = NULL;
}

//insere elementos na fila
void inserirElementos(struct queue *f, int valor) {
    struct tqueue *novo = (struct tqueue*)malloc(sizeof(struct tqueue));
    novo->valor = valor;
    novo->next = NULL;

    if(f->head == NULL){
        f->head = novo;
    } else {
        f->tail->next = novo;
    }
    f->tail = novo;
}

//remove elemento da fila
void removerElemento(struct queue *f) {
    struct tqueue *aux = f->head;
    f->head = f->head->next;
    free(aux);
}

//printa fila
void imprimirFila(struct queue *f) {
    struct tqueue *aux = f->head;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->next;
    }
}

//destroi fila
void destruirFila(struct queue *f) {
    struct tqueue *aux = f->head;
    while(aux != NULL){
        struct tqueue *temp = aux->next;
        free(aux);
        aux = temp;
    }
    f->head = NULL;
    f->tail = NULL;
}