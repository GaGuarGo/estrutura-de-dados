#include <stdio.h>


void printV(int vetor[], int size) {

	for (int a = 0;  a < size; a++) {

		printf("%d ", vetor[a]);
	}

}

int getPosition(int vetor[],int size, int numEscolhido) {
	if(numEscolhido == vetor[size]) {
		return size;
	} else {
	 	size--;
		return getPosition(vetor,size, numEscolhido);
	}
}

int main() {

	int num;

	int vetor[] = {15, 8, 42, 19, 30};
	printf("Digite um valor do vetor para saber sua posicao:  ");
	printV(vetor, 5);
	printf("\n");
	scanf("%d", &num);

	printf("A posicao do numero e: %d", getPosition(vetor, 5, num));




	return 0;
}