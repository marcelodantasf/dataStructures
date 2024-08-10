#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int capacidade;
    int final;
    int *dados;
};

void init(struct fila *f, int cap){
    f->final = -1;
    f->capacidade = cap;
    f->dados = calloc(f->capacidade, sizeof(int));
    printf("Memory space allocated!\n");
}

void free_all(struct fila *f){
    free(f->dados);
    printf("Memory freed!\n");
}

void list(struct fila *f) {
    printf("Queue:\n");
    for(int i = 0; i < f->final+1; i++) {
        printf("[%d] ",*(f->dados+i));
    }
    printf("\n");
}

int insert(struct fila *f, int valor){
    if(f->final+1 == f->capacidade){
        printf("ERROR!\nNo space available\n");
        return -1;
    }
    int i = f->final + 1;
    *(f->dados+i) = valor;
    printf("Value: [%d] successfully added to queue!\n", valor);
    f->final += 1;
}

int remove_element(struct fila *f){
    if (f->final < 0)
    {
        printf("ERROR!\nEmpty queue!\n");
        return -1;
    }
    int i = 0;
    while (i<f->final)
    {
        *(f->dados+i) = *(f->dados+(i+1));
        i++;
    }
    f->final -= 1;
    printf("Element removed from queue!\n");
}


int main(){
    struct fila queue;
    init(&queue,5);
    remove_element(&queue);
    insert(&queue,10);
    insert(&queue,8);
    list(&queue);
    insert(&queue,5);
    insert(&queue,2);
    list(&queue);
    remove_element(&queue);
    remove_element(&queue);
    list(&queue);
    free_all(&queue);

    exit(0);
}