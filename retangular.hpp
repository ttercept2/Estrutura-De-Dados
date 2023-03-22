#include <iostream>

using namespace std;

class retangular{
    private:
    int resposta;
    int linhas,colunas;
    public:
    retangular(int linhas,int colunas){
        this->linhas = linhas;
        this->colunas = colunas;
    }
    int calculaDentro(){
        if(linhas<=2 && colunas<=2){
            return 0;
        } else {
            resposta = (linhas-2)*(colunas-2);
        }
        return resposta;
    }
};