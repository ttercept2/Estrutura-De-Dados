#include <stdio.h>
#include <stdlib.h>


typedef struct listaDecimal
{
    double elemento;
    struct listaDecimal *prox;
}lista;

void inserirFim(lista **cabeca,double n){
    lista *novo;
    novo = (lista*) malloc(sizeof(lista));
    novo->elemento=n;
    novo->prox= NULL;
    
    if(*cabeca == NULL){
        *cabeca = novo;
    }
    else {
        lista *p = *cabeca;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox=novo;
    }
}

void trocaValor(lista *a,lista *b){
    double aux;
    aux = a->elemento;
    a->elemento = b->elemento;
    b->elemento = aux;
}

void printarLista(lista *cabeca){
    lista *p = cabeca;
    while(p != NULL){
        printf("%f ",p->elemento);
        p = p->prox;
    }
        printf("\n");
    }


void ordernar(lista *cabeca){

    if(cabeca == NULL){
        return;
    }
    if(cabeca->prox == NULL){
        return;
    }
    int trocas = 1;

    while(trocas){
        trocas = 0;

        lista *p1 = cabeca;
        lista *p2 = p1->prox;

        while(p2 != NULL){
            if(p1->elemento > p2->elemento){
                trocaValor(p1,p2);
                trocas = 1;
            }
            p1 = p2;
            p2 = p1->prox;
        }
    }

}

int main(){
    lista *a;
    inserirFim(&a,10);
    inserirFim(&a,2);
    inserirFim(&a,10);
    inserirFim(&a,1);
    inserirFim(&a,3);
    inserirFim(&a,5);
    inserirFim(&a,6);
    printarLista(a);
    ordernar(a);
    printarLista(a);
}
