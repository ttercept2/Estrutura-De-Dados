#include <iostream>

using namespace std;

typedef struct Vet{
    int key;
    int endereco;
}vet;

class Vetor{
    private:
        vet *vetor;
        int indices;
    public:
        Vetor(){
            vetor = (vet*) calloc(100000,sizeof(vet));;
            indices = 0;
        }

        void inserir(int novaKey, int novoEnd){
            if(indices > 99999){
                cout << "Vetor cheio" <<endl;
                return;
            }
            int percorrer=0;
            while(vetor[percorrer].key <= novaKey && vetor[percorrer].key != 0){
                percorrer++;
            }
            for(int i=99998; i>=percorrer;i--){
                vetor[i+1] = vetor[i];
            }
            vetor[percorrer].key = novaKey;
            vetor[percorrer].endereco = novoEnd;
            indices++;
        }

        int busca(int key){
            int min = 0;
            int max = indices;
            int meio = 0;
            while(min <= max){
                meio = (min+max)/2;
                if(vetor[meio].key == key){
                    return vetor[meio].endereco;
                }
                if(vetor[meio].key > key){
                    max = meio -1;
                }
                if(vetor[meio].key < key){
                    min = meio +1;
                }
            }
            return -1;
        }

};

int main(){
    Vetor fila;

    fila.inserir(1,10);
    fila.inserir(2,20);
    fila.inserir(3,30);
    fila.inserir(4,40);
    fila.inserir(-5,-50);
    fila.inserir(5,50);
    cout << fila.busca(-5) <<endl;

    return 0;
}
