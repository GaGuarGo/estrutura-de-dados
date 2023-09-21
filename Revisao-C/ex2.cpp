#include <stdio.h>
#define TAM 4

float calcMedia(int vetor[TAM]){
	
	float media;
	int soma = 0;
	
	for(int i = 0; i < TAM; i++){
		
		soma = vetor[i] + soma;
		
	}
	
	media = soma/TAM;
	
	return media;
	
}

int main() {
	
	int vetor[TAM];
	int numEscolhido;
	float media;
	
	
	
	for(int i = 0; i < TAM; i++){
		
		printf("Digite o %d numero do vetor: \n", i + 1);
		scanf("%d", &numEscolhido);
		
		vetor[i] = numEscolhido;
		
		
		
		
	}
	
	media = calcMedia(vetor);

	
	printf("Media do Vetor e: %f", media);
	
	return 0;
}