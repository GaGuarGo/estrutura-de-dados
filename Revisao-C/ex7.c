#include <stdio.h>
#include <stdlib.h>


//Percorre e le a matriz em forma de espiral
void espiral(int size, int matriz[size][size]) {

	int cima = 1, baixo = size, esquerda = 1, direita = size;

	while (cima <= baixo && esquerda <= direita) {

		for (int i = esquerda; i <= direita; i++) {
			printf("%d ", matriz[cima][i]);
		}
		cima++;


		for (int i = cima; i <= baixo; i++) {
			printf("%d ", matriz[i][direita]);
		}
		direita--;


		if (cima <= baixo) {
			for (int i = direita; i >= esquerda; i--) {
				printf("%d ", matriz[baixo][i]);
			}
			baixo--;
		}

		if (esquerda <= direita) {
			for (int i = baixo; i >= cima; i--) {
				printf("%d ", matriz[i][esquerda]);
			}
			esquerda++;
		}
	}
}

//Gera uma matriz do tipo NxN, sendo N ímpar

void gerarMatriz(int size, int matriz[size][size]) {


	if(size % 2 != 0) {
		for(int j = 1; j <= size; j++) {
			for(int i = 1; i <= size; i++) {

				int valor = 0;

				if(j<2) {
					valor = i;
				} else {
					
					valor = matriz[j][i-1] + 1;
				}

				printf("%d ",matriz[j][i] = valor);

			}
			printf("\n");
		}

		espiral(size, matriz);
	} else {
		printf("\nDIGITE UM ÍNDICE ÍMPAR!");
	}

}


int main() {

	int size = 0;
	int matriz[size][size];

	printf("Digite o tamanho da matriz:\n");
	scanf("%d", &size);

	gerarMatriz(size,matriz);

	return 0;
}