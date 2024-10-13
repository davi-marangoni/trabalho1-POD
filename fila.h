struct tqueue {
    int valor;
    struct tqueue* next;
};

struct queue {
    struct tqueue* head;
    struct tqueue* tail;
};

void iniciarFila(struct queue *f);
void inserirElementos(struct queue *f, int valor);
void removerElemento(struct queue *f);
void imprimirFila(struct queue *f);
void destruirFila(struct queue *f);