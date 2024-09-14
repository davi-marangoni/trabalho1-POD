struct tlist {
    int valor;
    struct tlist* next;
};

struct list {
    struct tlist* head;
    struct tlist* tail;
};

void initList(struct list* l);
void insertList(struct list *l, int valor);
void printList(struct list* l);
void insertListInArray(struct list* l, struct tlist* array, int size);