#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int capacidade;
    int final;
    int *dados;
};

void init(struct lista *l, int cap){
    l->final = -1;
    l->capacidade = cap;
    l->dados = calloc(l->capacidade, sizeof(int));
    printf("Memory space allocated!\n");
}

void free_all(struct lista *l){
    free(l->dados);
    printf("Memory freed!\n");
}

void list(struct lista *l) {
    printf("\nLista:\n");
    for(int i = 0; i < l->final+1; i++) {
        printf("[%d] ",*(l->dados+i));
    }
    printf("\n\n");
}

int insertC(struct lista *l, int valor){
    if(l->final+1 == l->capacidade){
        printf("ERROR!\nNo space available\n");
        return -1;
    }

    int i = 0;

    if(l->final = 0) {
        *(l->dados+i) = valor;
        return 0;
    }

    int aux = valor;
    int aux2;

    while(i<l->final) {
        aux2 = *(l->dados+i);
        *(l->dados+i) = aux;
        aux = aux2;
        i++;
    }

    printf("Value: [%d] successfully added to queue!\n", valor);
    l->final += 1;
}

int insertF(struct lista *l, int valor){
    if(l->final+1 == l->capacidade){
        printf("ERROR!\nNo space available\n");
        return -1;
    }
    int i = l->final + 1;
    *(l->dados+i) = valor;
    printf("Value: [%d] successfully added to queue!\n", valor);
    l->final += 1;
}

int removerComeco(struct lista *l){
    if (l->final < 0)
    {
        printf("ERROR!\nEmpty queue!\n");
        return -1;
    }
    int i = 0;
    while (i<l->final)
    {
        *(l->dados+i) = *(l->dados+(i+1));
        i++;
    }
    l->final -= 1;
    printf("Element removed from queue!\n");
}

int removerFinal(struct lista *l){
    if (l->final < 0) {
        printf("ERROR!\nEmpty queue!\n");
        return -1;
    }

    l->final -= 1;
    printf("Element removed from queue!\n");
}


int main(){
    struct lista queue;
    init(&queue,5);
    
    insertF(&queue,10);
    insertF(&queue,8);

    list(&queue);

    insertF(&queue,5);

    list(&queue);
    
    insertC(&queue,2);

    list(&queue);

    removerComeco(&queue);
    removerFinal(&queue);

    list(&queue);

    free_all(&queue);

    exit(0);
}