#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome [255];
} aluno;

typedef struct
{
    struct no *prox;
    aluno a;
} no;

no* create_node() {
    no* node = malloc(sizeof(no));
    return node;
}

aluno* cadastro(int mat, const char n[]){
    aluno *a = malloc(sizeof(aluno));
    a->matricula = mat;
    strcpy(a->nome, n);
    printf("Aluno [%s] cadastrado!\n", a->nome);

    return a;

    /* aluno a2 = (aluno) {
        .matricula = mat,
    };

    strcpy(a2.nome, n);
    return a2; */ 
}

void excluir_aluno(aluno* a){
  //  printf("ALERTA! esta função pode ocasionar vazamento de memória, use-a com cuidado\n");
    free(a);
    printf("Aluno removido do sistema!\n");
}

void add_fila2(no** queue, aluno al){
    if((*queue)== NULL){
        (*queue) = malloc(sizeof(no));
        
        (*queue)->a = al;
        (*queue)->prox = NULL;
        return;
    }

    no *aux = malloc(sizeof(no));

    if((*queue)->prox == NULL){
        aux->a = al;
        aux->prox = NULL;
        (*queue)->prox = aux;
        return;
    }

    no* helper = (*queue);

    while(helper->prox != NULL)
        helper = helper->prox;

    aux->a = al;
    aux->prox = NULL;

    helper->prox = aux;

    printf("Aluno [%s] inserido na fila!\n", al.nome);
    return;
}

void add_fila(no* queue, aluno al){
    if(queue == NULL){
        queue = malloc(sizeof(no));
        
        queue->a = al;
        queue->prox = NULL;
        return;
    }

    

    no *aux = malloc(sizeof(no));

    if(queue->prox == NULL){
        aux->a = al;
        aux->prox = NULL;
        queue->prox = aux;
        return;
    }

    no* helper = queue;

    while(helper->prox != NULL)
        helper = helper->prox;

    aux->a = al;
    aux->prox = NULL;

    helper->prox = aux;

    printf("Aluno [%s] inserido na fila!\n", al.nome);
    return;
}

void toString (aluno obj){
    printf("Nome do aluno: %s\n", obj.nome);
    printf("Matricula do aluno: %d\n", obj.matricula);
}

void listar_fila(no queue){
    printf("\n");

    int count = 1;
    no* aux = &queue;

    while(aux != NULL){
        printf("Indice: %d\n", count);
        toString(aux->a);

        count++;

        aux = aux->prox;
    }
}

int main(){
    no* fila = NULL;

    aluno* a1 = cadastro(1018048, "pedro");
    aluno* a2 = cadastro(1021023, "marcelo");
    aluno* a3 = cadastro(1017040, "guilherme");

    add_fila2(&fila, *a1);

    add_fila2(&fila, *a2);

    add_fila2(&fila, *a3);

    listar_fila(*fila);

    exit(0);
}