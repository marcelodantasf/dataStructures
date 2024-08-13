#include <stdio.h>
#include <stdlib.h>

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

    while(getter){
        printf("[%d] ", p->d.id);
        getter = getter->prox;
    }
    printf("\n");
}