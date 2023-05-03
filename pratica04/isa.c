//Klaus Almeida Souza Santos 201920073
//Gabriel de Souza Matheus Oliveira 202121097
//Lucas Cardoso Nascimento 202021567

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Pilha {
    int *dados;
    int topo;
} Pilha;

Pilha *criar_pilha(int tamanho) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->dados = (int *) malloc(tamanho * sizeof(int));
    pilha->topo = -1;
    return pilha;
}

void empilhar(int valor, Pilha *pilha) {
    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
}

int desempilhar(Pilha *pilha) {
    int valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return valor;
}

int main() {
    int N, i, valor;
    char instrucao[10];
    Pilha *pilha;

    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }

        pilha = criar_pilha(MAX);

        for (i = 0; i < N; i++) {
            scanf("%s", instrucao);
            if (strcmp(instrucao, "BIPUSH") == 0) {
                scanf("%d", &valor);
                empilhar(valor, pilha);
            } else if (strcmp(instrucao, "IADD") == 0) {
                int valor1 = desempilhar(pilha);
                int valor2 = desempilhar(pilha);
                empilhar(valor1 + valor2, pilha);
            } else if (strcmp(instrucao, "ISUB") == 0) {
                int valor1 = desempilhar(pilha);
                int valor2 = desempilhar(pilha);
                empilhar(valor1 - valor2, pilha);
            } else if (strcmp(instrucao, "IMUL") == 0) {
                int valor1 = desempilhar(pilha);
                int valor2 = desempilhar(pilha);
                empilhar(valor1 * valor2, pilha);
            }
        }
        printf("%d\n", pilha->dados[pilha->topo]);
        free(pilha->dados);
        free(pilha);
    }

    return 0;
}
