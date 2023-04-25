#include <iostream>
#include <queue>
#include <string>
using namespace std;

class filaDupla {
    private:
    queue<int>normal;
    queue<int>prioridade;

    public:

    void inserir(int elemento){
        if(elemento>=5000){
            normal.push(elemento);
        }
        else{
            prioridade.push(elemento);
        }
    }

    int remover(){
        int removido;
        if(!prioridade.empty()){
            removido = prioridade.front();
            prioridade.pop();
        }
        else{
            removido = normal.front();
            normal.pop();
        }
        return removido;
    }

    void esvaziar(){
        while(!prioridade.empty()){
            prioridade.pop();
        }
        while(!normal.empty()){
            normal.pop();
        }
    }
};

int main(){
    filaDupla fila;
    int n;
    int i;
    char acao;
    int valor;
    int removido;
    string removidos = "";
    int formatacao=0;
    while(cin >> n && n != 0){

        for(i = 0; i < n; i++){
            cin >> acao;
            if(acao == 'D'){
                removido = fila.remover();
                if(formatacao>0){
                    removidos += " "; 
                    removidos += to_string(removido);
                }
                else {
                    removidos += to_string(removido);
                    formatacao++;
                }
            }
            else{
                cin >> valor;
                fila.inserir(valor);
            }
        }
        fila.esvaziar();
        formatacao = 0;
        cout << removidos << endl;
        removidos = "";
    }
    return 0;
}