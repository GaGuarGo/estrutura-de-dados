#include <stdio.h>

void calcularProdutoVetores(int vetor1[], int vetor2[], int tamanho) {
    int produto = 0;
    
    for (int i = 0; i < tamanho; i++) {
        produto += vetor1[i] * vetor2[i];
    }
    
    printf("O produto dos vetores é: %d\n", produto);
}

int main() {
    int tamanho;
    
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tamanho);
    
    int vetor1[tamanho], vetor2[tamanho];
    
    printf("Digite os elementos do vetor 1:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor1[i]);
    }
    
    printf("Digite os elementos do vetor 2:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor2[i]);
    }
    
    calcularProdutoVetores(vetor1, vetor2, tamanho);
    
    return 0;
}