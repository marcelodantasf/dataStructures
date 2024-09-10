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

        printf("Usuario inserido\n");
        return newNode;
    }

    if(id <= arvore->usuario.id)
        arvore->e = inserir(arvore->e, id, nome);

    else if(id > arvore->usuario.id)
        arvore->d = inserir(arvore->d, id, nome);
}

no* buscar(no* arvore, int id) {
    if(!arvore)
        return NULL;

    if(id > arvore->usuario.id) {
        arvore->d = buscar(arvore->d, id);
        printf("\n\nBUSCA: [%d]",arvore->usuario.id);
        return arvore;
    }

    else if(id < arvore->usuario.id) {
        arvore->e = buscar(arvore->e, id);
        printf("\n\nBUSCA: [%d]",arvore->usuario.id);
        return arvore;
    }

    printf("\n\nBUSCA: [%d]",arvore->usuario.id);
    return arvore;
}

int main() {
    no* raiz = NULL;

    raiz = inserir(raiz, 50, "martenier");
    printf("%d,%s\n\n",raiz->usuario.id,raiz->usuario.nome);

    raiz = inserir(raiz, 40, "lucas");
    printf("%d,%s\n\n",raiz->usuario.id,raiz->usuario.nome);

    raiz = inserir(raiz, 60, "matheus");
    printf("%d,%s\n\n",raiz->usuario.id,raiz->usuario.nome);

    buscar(raiz, 40);

    return 0;
}