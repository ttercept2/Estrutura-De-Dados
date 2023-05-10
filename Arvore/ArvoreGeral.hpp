#include <vector>
using namespace std;
typedef struct noo {
    char dado;
    vector<struct noo*> filho;
    noo(char dado){
        this->dado = dado;
    }
}Noo;

bool percorrer(Noo *raiz,char dado){
    if(raiz == NULL){
        return false;
    }
    if(raiz->dado == dado){
        return true;
    }
    for(Noo *filho : raiz->filho){
        if(percorrer(filho,dado)){
            return true;
        }
    }
    return false;
}
