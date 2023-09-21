#include <stdio.h>


void printV(int vetor[], int size) {

	for (int a = 0;  a < size; a++) {

		printf("%d ", vetor[a]);
	}

}



int main() {

	int maior;
	int menor;

	int vetor[] = {15, 8, 42, 19, 30};
	printf("Vetor: \n");
	printV(vetor, 5);
	


	for(int i = 0; i < 5; i++) {

		if(maior < vetor[i]) {

			maior = vetor[i];
		}

		if(menor > vetor[i]) {
			menor = vetor[i];
		}
	}

	printf("\nMaior Valor do Vetor: %d", maior);
	printf("\nMenor Valor do Vetor: %d", menor);

	return 0;
}