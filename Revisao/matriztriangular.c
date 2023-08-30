#include <stdio.h>

void printarMatriz(int size, int matriz[size][size]) {

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

}

void gerarMatriz(int size, int matriz[size][size], int choice) {

	printf("%d", size);

	if(size % 2 != 0) {

		if(choice == 1) {


			int valor = 1;

			for(int i = 0; i < size; i++) {

				for(int j = 0; j < size; j++) {


					if(i > j) {
						matriz[i][j] = 0;
					} else {
						matriz[i][j] = valor;

					}

					valor++;
					printf("%d", matriz[i][j]);

				}

				printf("\n");
			}

		} else if( choice ==2) {

			int valor = 1;

			for(int i = 0; i < size; i++) {

				for(int j = 0; j < size; j++) {


					if(i < j) {
						matriz[i][j] = 0;
					} else {
						matriz[i][j] = valor;

					}

					valor++;
					printf("%d", matriz[i][j]);

				}

				printf("\n");

			}
		} else {

			printf("Escolha uma opção válido!");

		}


	} else {
		printf("\nDIGITE UM ÍNDICE ÍMPAR!");
	}

}

int main() {

	int option;
	printf("Digite [1] para Triangular Superior ou [2] para Triangular Inferior: \n");
	scanf("%d", &option);

	int size;
	printf("Digite o tamanho da matriz N x N: [N ímpar]\n");
	scanf("%d", size);

	int matriz[size][size];

	gerarMatriz(size, matriz, option);

	return 0;
}