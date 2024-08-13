#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacidade;
    int topo;
    int *dados;
} pilha;

void init(pilha *p, int cap){
    p->capacidade = cap;
    p->topo = -1;
    p->dados = calloc(p->capacidade,sizeof(int));
    printf("Memory space allocated successfully!\n");
}

void list(pilha *p) {
    printf("Stack:\n");
    for(int i = 0; i < p->topo+1; i++) {
        printf("[%d] ",*(p->dados+i));
    }
    printf("\n");
}

void free_all(pilha *p){
    free(p->dados);
    printf("Memory freed!\n");
}

int insert(pilha *p, int valor){
    if (p->topo + 1 == p->capacidade){
        printf("ERROR!\nNo space available\n");
        return -1;
    }
    int i = p->topo + 1;
    *(p->dados + i) = valor;
    printf("Value [%d] added to stack!\n", valor);
    p->topo += 1;
}

int delete(pilha *p){
    if (p->topo < 0)
    {
        printf("ERROR!\nEmpty stack!\n");
        return -1;
    }
    p->topo -= 1;
    printf("Element removed from queue!\n");
}

int main(){
    pilha stack;
    init(&stack,5);
    insert(&stack, 10);
    insert(&stack, 8);
    insert(&stack, 6);
    list(&stack);
    delete(&stack);
    list(&stack);
    free_all(&stack);
    exit(0);
}