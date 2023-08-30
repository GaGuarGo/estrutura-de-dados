#include <stdlib.h>
#include <stdio.h>

int main() {



	int n;
	printf("Digite o tamanho do vetor: \n");
	scanf("%d", &n);

	int vetor[n];
	printf("Digite os elementos do vetor:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}

	int comprimentoMax = 1; 
	int comprimentoAtual = 1;

	int inicioSubsequencia = 0; 
	int inicioMaxSubsequencia = 0; 

	for (int i = 1; i < n; i++) {
		if (vetor[i] > vetor[i - 1]) {
			comprimentoAtual++;
			if (comprimentoAtual > comprimentoMax) {
				comprimentoMax = comprimentoAtual;
				inicioMaxSubsequencia = inicioSubsequencia;
			}
		} else {
			comprimentoAtual = 1;
			inicioSubsequencia = i;
		}
	}

	printf("Maior subsequência crescente: ");
	for (int i = inicioMaxSubsequencia; i < inicioMaxSubsequencia + comprimentoMax; i++) {
		printf("%d ", vetor[i]);
	}

	return 0;
}