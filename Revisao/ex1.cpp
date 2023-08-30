#include <stdio.h>
#include <stdlib.h>

#define TAM 3



int main() {
	
	
	int vetor1[] = {1,4,9};
	int vetor2[] = {2,3,5};
	int vetorSoma[3];
	
	printf("Vetor 1: \n");
	for(int i = 0; i < TAM; i++){
		printf("%d ", vetor1[i]);
	}
	
	printf("\n\nVetor 2: \n");
	for(int i = 0; i < TAM; i++){
		printf("%d ", vetor2[i]);
	}
	
	
	printf("\n\nVetor Soma: \n");
	for(int i = 0; i < TAM; i++ ){
		printf("%d ", vetor1[i] +vetor2[i]);
	
	}
	
	
	
	return 0;
}