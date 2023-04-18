#include <iostream>
#include <stack>
#include <string>

//Klaus Almeida Souza Santos 201920073
//Gabriel de Souza Matheus Oliveira 202121097
//Lucas Cardoso Nascimento 202021567

using namespace std;

double avaliarExpressaoPosfixa(string expressao) {
    stack<double> pilha;
    double resultado;
    double op1, op2;
    char operador;

    for (int i = 0; i < expressao.size(); i++) {
        if (isdigit(expressao[i]) || expressao[i] == '.') {
            string valorString;
            
            if(expressao[i] == '.') {
                //Se for um ponto, vamos pegar o valor anterior e somar os números seguintes a string, para formar o número com suas casas decimais
                string s = to_string(pilha.top());
                valorString = s[0];
                valorString +='.';
                i++;
              
                while(isdigit(expressao[i]) && expressao[i+1] !='.'){
                  valorString += expressao[i];
                  i++;
                }
              
                pilha.pop();
                pilha.push(stod(valorString));
                i--;//Esse i-- serve para que o for não acabe pulando um elemento da string
            }
              
            else {
              string s(1,expressao[i]);
              pilha.push(stod(s));
            }
          
        } else {
            operador = expressao[i];
            if(pilha.empty()){
                cout << "erro linha 42\n"<< endl;
                return 0;
            }
            op2 = pilha.top();
            pilha.pop();
            if(pilha.empty()){
                cout << "erro linha 48\n"<< endl;
                return 0;
            }
            op1 = pilha.top();
            pilha.pop();

            switch (operador) {
                case '+':
                    resultado = op1 + op2;
                    break;

                case '-':
                    resultado = op1 - op2;
                    break;

                case '*':
                    resultado = op1 * op2;
                    break;

                case '/':
                    resultado = op1 / op2;
                    break;
                case '^':
                    if(op2 == 0){
                      resultado = 1;
                    }
                    else {
                      resultado = op1;
                      for(int i = 2; i<=op2;i++){
                        resultado *=op1;
                      }
                    }
                    break; 
                default:
                    break;
            }

            pilha.push(resultado);
        }
    }
    if(pilha.empty()){
      cout << "erro linha 89\n"<< endl;
      return 0;
    }

    return pilha.top();
}

int main() {
    string expressao = "";
    int n;
    double resultado;
    string coletar;
    
    while(cin >> n && n != 0){
      for(int i = 0; i<n ;i++){
        cin >> coletar;
        expressao +=coletar;
      }
      resultado = avaliarExpressaoPosfixa(expressao);
      printf("%.3f\n",resultado);
      expressao = "";
    }

    
    return 0;
}
