#include <iostream>
#include "ArvoreBinaria.hpp"

int main(){
    No*raiz = NULL;
    raiz = inserir(raiz,5);
    raiz = inserir(raiz,3);
    raiz = inserir(raiz,4);
    raiz = inserir(raiz,2);
    raiz = inserir(raiz,8);
    raiz = inserir(raiz,7);
    raiz = inserir(raiz,9);
    imprimir(raiz);
    return 0;
}