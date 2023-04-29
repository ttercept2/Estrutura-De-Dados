#include <iostream>
using namespace std;
typedef struct  No {
    int num;
    char elemento;
    struct No *prox;
}no;

class Estrutura{


private:
    no *fila;
public:
    Estrutura(){
        fila = NULL;
    }
    void inserir(int num, char elemento){
        no* alocar = new no;
        alocar->num = num;
        alocar->elemento = elemento;
        alocar->prox = NULL;

        if(fila == NULL){
            fila = alocar;
            return;
        }
        
        if(fila->num < alocar->num){
            alocar->prox = fila;
            fila = alocar;
            return;
        }
        
        no*percorrer = fila;
        while(percorrer->prox != NULL && percorrer->prox->num > alocar->num){
            percorrer = percorrer->prox; 
        }

        alocar->prox = percorrer->prox;
        percorrer->prox = alocar;
    }

    void remover(){
        if(fila == NULL){
             return;
        }
        no *remover = fila;
        fila = fila->prox;
        free(remover);
    }

    void imprimir(){
        no* imprimir = fila;
        while(imprimir != NULL){
            cout << imprimir->num << imprimir->elemento << " ";
            imprimir = imprimir->prox;
        }
        cout << endl;
    }
};

int main(){
    Estrutura fila;
    fila.inserir(5,'c');
    fila.inserir(10,'f');
    fila.inserir(20,'e');
    fila.inserir(30,'a');
    fila.inserir(40,'b');
    fila.inserir(40,'z');
    fila.imprimir();
    fila.remover();
    fila.imprimir();
    fila.remover();
    fila.imprimir();
    

    return 0;
}
