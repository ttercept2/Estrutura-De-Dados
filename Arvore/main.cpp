#include <iostream>
#include "ArvoreBinaria.hpp"
#include <vector>
#include "ArvoreGeral.hpp"
int main(){
    //TESTANDO A ARVORE BINARIA

    /*No*raiz = NULL;
    raiz = inserir(raiz,5);
    raiz = inserir(raiz,3);
    raiz = inserir(raiz,4);
    raiz = inserir(raiz,2);
    raiz = inserir(raiz,8);
    raiz = inserir(raiz,7);
    raiz = inserir(raiz,9);
    imprimir(raiz);*/

    //TESTANDO A ARVORE GERAL
    Noo * raiz = NULL;
    raiz = new Noo('A');
    Noo * no1 = new Noo('B');
    Noo * no2 = new Noo('C');
    Noo * no3 = new Noo('D');
    Noo * no4 = new Noo('E');
    Noo * no5 = new Noo('F');
    raiz->filho.push_back(no1);
    raiz->filho.push_back(no2);
    no1->filho.push_back(no3);
    no3->filho.push_back(no4);
    no3->filho.push_back(no5);
    cout << percorrer(raiz,'A') << endl;
    return 0;
}