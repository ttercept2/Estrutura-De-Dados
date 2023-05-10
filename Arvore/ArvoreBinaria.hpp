#include <iostream>
using namespace std;

typedef struct no {
    struct no *esq;
    struct no *dir;
    int elemento;
    no(int num){
        elemento = num;
        esq = NULL;
        dir = NULL;
    }
}No;

No* inserir(No* raiz,int elemento){
    if(raiz == NULL){
        return new No(elemento);
    }
    if(raiz->elemento > elemento){
        raiz->esq = inserir(raiz->esq,elemento);
    }
    else {
        raiz->dir = inserir(raiz->dir,elemento);
    }
    return raiz;
}

void imprimir(No* raiz){
    if(raiz != NULL){
        imprimir(raiz->esq);
        cout << raiz->elemento << " ";
        imprimir(raiz->dir);
    }
}