#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nome;
    int id;
} dados;

typedef struct {
    struct no* e;
    struct no* d;
    dados usuario;
} no;

dados criarUsuario(char* nome, int id) {
    return (dados) {
        .id = id,
        .nome = nome
    };
}

no* inserir(no* arvore, int id, char* nome) {
    if(arvore == NULL) {
        no* newNode = malloc(sizeof(no));
        newNode->d = NULL;
        newNode->e = NULL;
        newNode->usuario = criarUsuario(nome, id);

        printf("[R]: Usuario inserido\n");
        return newNode;
    }

    if(id <= arvore->usuario.id)
        arvore->e = inserir(arvore->e, id, nome);

    else if(id > arvore->usuario.id)
        arvore->d = inserir(arvore->d, id, nome);
}

void inserirPP(no** arvore, int id, char* nome) {
    if(!*arvore) {
        no* newNode = malloc(sizeof(no));
        newNode->d = NULL;
        newNode->e = NULL;
        newNode->usuario = criarUsuario(nome, id);

        *arvore = newNode;
        printf("[PP]: Usuario inserido\n");
        return;
    }

    no* aux = *arvore;
    if(id > aux->usuario.id)
        inserirPP(&(aux)->d,id,nome);
    else if(id <= aux->usuario.id)
        inserirPP(&(aux)->e,id,nome);
}

no* buscar(no* arvore, int id) {
    if(!arvore)
        return NULL;

    if(id > arvore->usuario.id) {
        arvore->d = buscar(arvore->d, id);
        return arvore;
    }

    else if(id < arvore->usuario.id) {
        arvore->e = buscar(arvore->e, id);
        return arvore;
    }

    printf("\n\nBUSCA: [%d]\n",arvore->usuario.id);
    return arvore;
}

no* remover(no* arvore, int id) {
    if(!arvore)
        return NULL;
    
    if(id > arvore->usuario.id) {
        arvore->d = remover(arvore->d, id);
        return arvore;
    }
    else if(id < arvore->usuario.id) {
        arvore->e = remover(arvore->e, id);
        return arvore;
    }

    if(!arvore->e && !arvore->d) { //nó sem filhos
        free(arvore);
        return NULL;
    }
    else if(arvore->d && arvore->e) { //nó com dois filhos
        no* pai = arvore;
        no* aux = arvore->e;

        while(aux->d) {
            pai = aux;
            aux = aux->d;
        }

        if(pai != arvore) {
            pai->d = aux->e;
            aux->e = arvore->e;
        }
        aux->d = arvore->d;

        free(arvore);
        return aux;
    }
    else { //nó com um filho
        no* aux = (arvore->d != NULL ? arvore->d : arvore->e);
        free(arvore);
        return aux;
    }
}

void printPre(no* arvore) {
    if(!arvore)
        return;

    printf("[ID: %d][NOME: %s]\n",arvore->usuario.id, arvore->usuario.nome);

    printPre(arvore->e);
    printPre(arvore->d);
}

void printEm(no* arvore) {
    if(!arvore)
        return;

    printEm(arvore->e);
    printf("[ID: %d][NOME: %s]\n",arvore->usuario.id, arvore->usuario.nome);
    printEm(arvore->d);
}

void printPos(no* arvore) {
    if(!arvore)
        return;

    printPos(arvore->e);
    printPos(arvore->d);
    printf("[ID: %d][NOME: %s]\n",arvore->usuario.id, arvore->usuario.nome);
}

int main() {
    no* raiz = NULL;

    raiz = inserir(raiz, 50, "martenier");
    printf("%d,%s\n\n",raiz->usuario.id,raiz->usuario.nome);

    raiz = inserir(raiz, 40, "lucas");

    raiz = inserir(raiz, 60, "matheus");

    buscar(raiz, 40);

    inserirPP(&raiz,45,"ajalmar");
    inserirPP(&raiz,65,"pedro");

    buscar(raiz,65);

    printf("\n");
    printEm(raiz);

    printf("\n");
    printPre(raiz);

    printf("\n");
    printPos(raiz);

    remover(raiz,65);
    
    printf("\n");
    printEm(raiz);

    return 0;
}