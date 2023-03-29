#include <stdio.h>
#include <stdlib.h>


typedef struct elemento {
	int valor;
	struct elemento *proximo;
	struct elemento *anterior;
}Elemento;

Elemento* criarNo(int n){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->valor = n;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}
void inserirFim(Elemento **inicio,int n){
    Elemento *novo = criarNo(n);
    
    if(*inicio == NULL){
        *inicio = novo;
    }
    else {
        Elemento *p = *inicio;
        while(p->proximo != NULL){
            p = p->proximo;
        }
        p->proximo = novo;
        novo->anterior = p;
    }
}

void inserirInicio(Elemento **inicio,int n){
    Elemento *novo = criarNo(n);
    
    if(*inicio == NULL){
        *inicio = novo;
    }
    else {
        novo->proximo = *inicio;
        (*inicio)->anterior = novo;
        *inicio = novo;
    }
}

void removerInicio(Elemento **inicio){
    if(*inicio == NULL){
        return;
    }
    if((*inicio)->proximo == NULL){
        free(*inicio);
    } 
    else {
        *inicio=(*inicio)->proximo;
        free((*inicio)->anterior);
    }
}

void removerFim(Elemento **inicio){
    if(*inicio == NULL){
        return;
    }
    if((*inicio)->proximo == NULL){
        free(*inicio);
    }
    else {
        Elemento *p = *inicio;
        while(p->proximo != NULL){
            p = p->proximo;
        }
        p->anterior->proximo = NULL;
        free(p);
    }
}

void printarLista(Elemento *cabeca){
    Elemento* p = cabeca;
    while(p != NULL){
        printf("%d ",p->valor);
        p = p->proximo;
    }
        printf("\n");
}

void limparMemoria(Elemento* a){
    while(a != NULL){
        if(a->proximo != NULL){
            a = a->proximo;
            free(a->anterior);
        }
        else{
            free(a);
        }
    }
}

int main(){
    Elemento *a;
    
    inserirFim(&a,10);
    inserirInicio(&a,55);
    inserirFim(&a,10);
    inserirInicio(&a,1);
    inserirFim(&a,3);
    inserirInicio(&a,11);
    inserirFim(&a,6);
  
    printarLista(a);
  
    removerFim(&a);
  
    printarLista(a);
  
    removerInicio(&a);
  
    printarLista(a);
}

