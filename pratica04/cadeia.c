#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
//KLAUS ALMEIDA SOUZA SANTOS
//GABRIEL DE SOUZA MATHEUS
//LUCAS CARDOSO NASCIMENTO
typedef struct pilha {
    char dados[MAX];
    int topo;
}Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

void empilhar(Pilha *p,char c){
    p->topo++;
    p->dados[p->topo]=c;
}

char desempilhar(Pilha *p){
    char removido;
    removido = p->dados[p->topo];
    p->topo--;
    return removido;
    }

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}


int verificarFormato(char *string, int n){
    Pilha p;
    int i;
    int tam = n;

    inicializar(&p);

    for(i=0; string[i]!='C';i++){
        empilhar(&p,string[i]);
    }
    i++;

    while(i<tam){
        if(pilhaVazia(&p) || string[i] != desempilhar(&p)){
            return 0;
        }
        i++;
    }
    return pilhaVazia(&p);
}

int main(){

    int entradas;

    while(scanf("%d\n",&entradas) == 1 && entradas != 0){
        char string[entradas];

        for(int i=0; i<entradas; i++){
            scanf("%c",&string[i]);
        }

        if(verificarFormato(string, entradas)){
        printf("SIM\n");
        }

        else{
        printf("NAO\n");
        }
    }

    return 0;
}




