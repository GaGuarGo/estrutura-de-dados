#include <stdio.h>


void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {



	int size;
	printf("Digite o tamanho do vetor: \n");
	scanf("%d", &size);

	int vetor[size];
	printf("Digite os elementos do vetor:\n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &vetor[i]);
	}
	
	int k;
	printf("Digite quantas posições deseja rotacionar para a direita:\n");
	scanf("%d", &k);
	
	for(int i = 0; i < k; i++) {
		
		swap(&vetor[i], &vetor[i + 1]);
		
	}
	
	printf("Vetor Rotacionado: %d");
	for(int j = 0; j < size; j++){
		printf("%d ", vetor[j]);
	}

	return 0;
}