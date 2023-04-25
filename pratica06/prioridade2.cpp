
#include <iostream>
using namespace std;
typedef struct LIsta {
    int valor;
    struct LIsta* proximo;
}lista;

void inserirFim(lista **cabeca,int n){
    lista *novo;
    novo = new lista;
    novo->valor=n;
    novo->proximo= nullptr;
    
    if(*cabeca == nullptr){
        *cabeca = novo;
    }
    else {
        lista *p = *cabeca;
        while(p->proximo != nullptr){
            p = p->proximo;
        }
        p->proximo=novo;
    }
}

void exibirLista(lista** p) {
    lista* temp = *p;
    while (temp != nullptr) {
        cout << (temp)->valor;
        temp = (temp)->proximo;
        if(temp != nullptr){
            cout << " ";
        }
    }
    cout << endl;
}

void removerMaiorValor(lista ** p) {
    if (*p == nullptr) {
        return;
    }
    int maiorValor = (*p)->valor;
    lista * noMaiorValor = *p;
    lista * noAtual = (*p)->proximo;
    while (noAtual != nullptr) {
        if (noAtual->valor > maiorValor) {
            maiorValor = noAtual->valor;
            noMaiorValor = noAtual;
        }
        noAtual = noAtual->proximo;
    }
    if (noMaiorValor == *p) {
        *p = (*p)->proximo;
    } else {
        lista * noAnterior = *p;
        while (noAnterior->proximo != noMaiorValor) {
            noAnterior = noAnterior->proximo;
        }
        noAnterior->proximo = noMaiorValor->proximo;
    }
    delete noMaiorValor;
}

int main() {
    // cria uma lista vazia
    lista *p = nullptr;
    int n;
    int i;
    char acao;
    int valor;
    while(cin >> n && n != 0){

        for(i = 0; i < n; i++){
            cin >> acao;
            if(acao == 'D'){
                removerMaiorValor(&p);
                exibirLista(&p);
            }
            else{
                cin >> valor;
                inserirFim(&p,valor);
                exibirLista(&p);
            }
        }
        p = nullptr;
    }
    return 0;
}
