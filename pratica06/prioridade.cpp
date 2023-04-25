#include <iostream>
#include <queue>
using namespace std;
class FilaComPrioridade {
public:
    // Insere um elemento na fila
    void inserir(int elemento) {
        fila.push(elemento);
    }

    // Remove e retorna o maior elemento da fila
    void remover() {
        if(fila.empty()){

            return;
        }
        fila.pop();
    }

    void esvaziar(){
        while(!fila.empty()){
            fila.pop();
        }
    }

    void imprimirFila() {
        priority_queue<int> temp = fila;

        if(temp.empty()){
            cout <<  "*" << endl;
        }
          
        else{
            while(!temp.empty()){
                cout << temp.top();
                temp.pop();
                if(!temp.empty()){
                    cout << " ";
                }
            }
            cout << endl;   
        }
    }

private:
    // Fila interna que usa um heap máximo
    priority_queue<int> fila;
};

int main(){
    FilaComPrioridade fila;
    int n;
    int i;
    char acao;
    int valor;
    while(cin >> n && n != 0){

        for(i = 0; i < n; i++){
            cin >> acao;
            if(acao == 'D'){
                fila.remover();
                fila.imprimirFila();
            }
            else{
                cin >> valor;
                fila.inserir(valor);
                fila.imprimirFila();
            }
        }
        fila.esvaziar();
    }
    return 0;
}
