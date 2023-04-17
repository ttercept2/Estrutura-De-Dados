#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool validarFrase(string frase) {
    stack<char> pilha;
    bool resultado = true;

    for(int i = 0; i<frase.length();i++){
        if(frase[i] == '(' || frase[i] == '[' || frase[i] == '{'){
            pilha.push(frase[i]);
        }
        else if(frase[i] == ')' || frase[i] == ']' || frase[i] == '}'){
            if(pilha.empty()){
                resultado = false;
                break;
            }
            else if((frase[i] == ')' && pilha.top() == '(') || (frase[i] == ']' && pilha.top() == '[') || (frase[i] == '}' && pilha.top() == '{')){
                pilha.pop();
            }
            else{
                resultado = false;
                break;
            }
        }
    }

    if(pilha.empty()){
        resultado = true;
    }

    return resultado;
}

int main() {
    string frase1;
    string frase2;
    cin >> frase1 >> frase2;
    if (validarFrase(frase1)) {
        cout << "A expressão 1 é válida." << endl;
    } else {
        cout << "A expressão 1 é inválida." << endl;
    }

    if (validarFrase(frase2)) {
        cout << "A expressão 2 é válida." << endl;
    } else {
        cout << "A expressão 2 é inválida." << endl;
    }

    return 0;
}
