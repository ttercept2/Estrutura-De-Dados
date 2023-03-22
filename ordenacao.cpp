#include <iostream>
using namespace std;

void selecao(int A[], int tam) {
    int max, chave, j;
    for (j = tam-1; j >= 1; j--) {
        max = j;
        for (int i = 0; i < j; i++) {
            if (A[i] > A[max]) {
                max = i;
            }
        }
        chave = A[j];
        A[j] = A[max];
        A[max] = chave;
    }
}

int main() {
    int A[10] = {5, 2, 9, 1, 7, 3, 8, 6, 4, 0};
    selecao(A, 10);
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
