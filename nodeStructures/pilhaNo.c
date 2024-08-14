#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[255];
} dados;

typedef struct {
    struct no* prox;
    dados d;
} no;

void push(no** p, dados data) {
    if(*p == NULL){
        *p = malloc(sizeof(no));
        (*p)->d = data;
        (*p)->prox = NULL;

        printf("element pushed!\n");
        return;
    }

    no* setter = malloc(sizeof(no));
    setter->d = data;
    setter->prox = NULL;

    no* getter = *p;
    while(getter->prox) {
        getter = getter->prox;
    }

    getter->prox = setter;
    printf("element pushed!\n");
}

void pop(no** p) {
    if(*p == NULL) {
        printf("no elements found!\n");
        return;
    }

    if((*p)->prox == NULL) {
        free(*p);
        return;
    }

    no* getter = *p;
    while(getter->prox) {
        getter = getter->prox;
    }

    no* aux = *p;
    while(aux->prox != getter) {
        aux = aux->prox;
    }

    aux->prox = NULL;
    free(getter);    
    printf("element popped!\n");
}

void list(no* p) {
    if(p == NULL) {
        printf("found no elements\n");
        return;
    }

    no* getter = p;

    printf("\nReading:\n");
    while(getter){
        printf("[id: %d] [name: %s]\n", getter->d.id, getter->d.name);
        getter = getter->prox;
    }
    printf("\n");
}

dados setData(dados d, int userId, char userName[]) {
    d.id = userId;
    strcpy(d.name,userName);

    return d;
}

int main(){
    dados e1 = setData(e1,1,"angela");
    dados e2 = setData(e2,2,"camille");
    dados e3 = setData(e3,3,"jack");

    no* stack = NULL;

    push(&stack, e1);
    push(&stack, e2);

    list(stack);

    push(&stack, e3);

    list(stack);

    pop(&stack);

    list(stack);

    return 0;
}