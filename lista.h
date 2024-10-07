struct tlist {
    int valor;
    struct tlist* next;
};

struct list {
    struct tlist* head;
    struct tlist* tail;
};

void initLista(struct list* l);
void inserirNaLista(struct list *l, int valor);
void printarLista(struct list* l);
void inserirListaNoArray(struct list* l, struct tlist* array, int tamanho);
void trocar(struct tlist* a, struct tlist* b);