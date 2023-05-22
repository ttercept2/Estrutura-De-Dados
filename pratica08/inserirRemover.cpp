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

No* encontrarMinimo(No* raiz) {
    if (raiz == NULL)
        return NULL;

    while (raiz->esq != NULL)
        raiz = raiz->esq;

    return raiz;
}

void imprimir(No* raiz){
    if(raiz != NULL){
        imprimir(raiz->esq);
        cout << raiz->elemento << " ";
        imprimir(raiz->dir);
    }
}

No* achar(No* raiz, int valor) {
    No* temp = raiz;
    No* pai = NULL;

    while (temp != NULL && temp->elemento != valor) {
        pai = temp;

        if (temp->elemento > valor) {
            temp = temp->esq;
        } else {
            temp = temp->dir;
        }
    }

    return pai;
}

void remover(No* raiz, int valor) {
    No* pai = achar(raiz, valor);
    No* temp;

    if (pai == NULL) {
        // Nó a ser removido é a raiz da árvore
        temp = raiz;
    } else if (pai->esq != NULL && pai->esq->elemento == valor) {
        temp = pai->esq;
    } else if (pai->dir != NULL && pai->dir->elemento == valor){
        temp = pai->dir;
    }
    else{
        temp = NULL;
    }

    if (temp != NULL) {
        if (temp->dir == NULL) {
            if (pai == NULL) {
                raiz = temp->esq;
            } else if (pai->esq == temp) {
                pai->esq = temp->esq;
            } else {
                pai->dir = temp->esq;
            }

            delete temp;
        } 
        else if (temp->esq == NULL) {
            if (pai == NULL) {
                raiz = temp->dir;
            } else if (pai->esq == temp) {
                pai->esq = temp->dir;
            } else {
                pai->dir = temp->dir;
            }

            delete temp;
        } 
        else {
            No* sucessor = encontrarMinimo(temp->dir);
            temp->elemento = sucessor->elemento;
            remover(temp->dir, sucessor->elemento);
        }
    }
}
int main(){
    No *raiz = NULL;
    raiz = inserir(raiz,1);
    raiz = inserir(raiz,2);
    raiz = inserir(raiz,3);
    raiz = inserir(raiz,4);
    raiz = inserir(raiz,5);
    raiz = inserir(raiz,-1);
    raiz = inserir(raiz,-2);
    raiz = inserir(raiz,-3);
    raiz = inserir(raiz,-4);
    raiz = inserir(raiz,-5);
    imprimir(raiz);
    cout <<endl;
    remover(raiz,1);
    imprimir(raiz);
    cout <<endl;
    remover(raiz,-4);
    imprimir(raiz);
    cout <<endl;
    return 0;
}
