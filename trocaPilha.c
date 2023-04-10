
#include <stdlib.h>
#include <stdio.h>

typedef struct Pilha {
    int valor;
    struct Pilha *prox;
} pilha;

void inicializa(pilha **p){
    *p = NULL;
}

void push(pilha** p,int n){
    pilha* nova = (pilha*)malloc(sizeof(pilha));
    nova->valor = n;
    nova->prox= *p;
    *p = nova;
}

void pop(pilha** p){
    if(*p == NULL){
        return;
    }
    pilha *remover = *p;
    *p = (*p)->prox;
    free(remover);
}

void trocar(pilha** p){
    if(*p == NULL || (*p)->prox == NULL){
        return;
    }
    pilha *aux = (*p)->prox;
    int temp = (*p)->valor;
    (*p)->valor = aux->valor;
    aux->valor = temp;
}

void printarLista(pilha *cabeca){
    pilha* p = cabeca;
    while(p != NULL){
        printf("%d ",p->valor);
        p = p->prox;
    }
        printf("\n");
}

int main(){
    pilha* pi;
    inicializa(&pi);
    push(&pi, 1);
    push(&pi, 2);
    push(&pi, 3);
    push(&pi, 4);
    printarLista(pi);
    trocar(&pi);
    printarLista(pi);
    return 0;
}
