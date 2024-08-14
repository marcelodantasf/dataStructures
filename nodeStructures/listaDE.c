#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[255];
} data;

typedef struct {
    data d;
    struct no* prev;
    struct no* next;
} no;

data setData(data d, int userId, char userName[]) {
    d.id = userId;
    strcpy(d.name,userName);

    return d;
}

void pushB(no** l, data uData) {
    if(*l == NULL) {
        *l = malloc(sizeof(no));

        (*l)->d = uData;
        (*l)->prev = NULL;
        (*l)->next = NULL;

        printf("element pushed in!\n");
        return;
    }

    no* setter = malloc(sizeof(no));
    setter->d = uData;
    setter->prev = NULL;
    setter->next = *l;

    *l = setter;
    printf("element pushed in!\n");
}

void pushE(no** l, data uData) {
    if(*l == NULL) {
        *l = malloc(sizeof(no));

        (*l)->d = uData;
        (*l)->prev = NULL;
        (*l)->next = NULL;

        printf("element pushed in!\n");
        return;
    }

    no* getter = *l;

    while (getter->next)
        getter = getter->next;
    
    no* setter = malloc(sizeof(no));
    setter->d = uData;
    setter->prev = getter;
    setter->next = NULL;

    getter->next = setter;
    printf("element pushed in!\n");
}

void list(no* l) {
    if (l == NULL) {
       printf("no elements found\n");
       return;
    }

    no* getter = l;

    printf("\nReading:\n");
    while (getter!= NULL) {
        printf("[id: %d] [name: %s]\n", getter->d.id, getter->d.name);
        getter = getter->next;
    }
    printf("\n");
}

void popB(no** l) {
    if(*l == NULL) {
        printf("no elements found\n");
        return;
    }

    if(!(*l)->next) {
        free(*l);
        *l = NULL; //medida de segurança adicional contra memory leak, linha descartável.

        printf("element popped out!\n");
        return;
    }

    no* getter = *l;

    *l = (*l)->next;
    (*l)->prev = NULL;

    free(getter);
    getter = NULL; //medida de segurança adicional contra memory leak, linha descartável.
    printf("element popped out!\n");
}

void popE(no** l) {
    if(*l == NULL) {
        printf("no elements found\n");
        return;
    }

    if(!(*l)->next){
        free(*l);
        *l = NULL;

        printf("element popped out!\n");
        return;
    }

    no* getter = *l;
    while(getter->next)
        getter = getter->next;

    no* aux = getter;
    aux = aux->prev;
    aux->next = NULL;

    free(getter);
    getter = NULL; // TO MALUCO
    printf("element popped out!\n");
}

int main() {
    data e1 = setData(e1,1,"temperance");
    data e2 = setData(e2,2,"seeley");
    data e3 = setData(e3,3,"max");
    data e4 = setData(e4,4,"christine");

    no* myList = NULL;

    pushB(&myList, e2);
    pushB(&myList, e1);

    list(myList);

    pushE(&myList, e3);
    pushE(&myList, e4);

    list(myList);

    popB(&myList);

    list(myList);

    popE(&myList);

    list(myList);

    return 0;
}