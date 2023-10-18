#include <stdio.h>

int calcularFatorial(int n) {
    // Caso base: fatorial de 0 é 1
    if (n == 0 || n == 1)
        return 1;
    else
        return n * calcularFatorial(n - 1);
}

int main() {
    int num;
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Não é possível calcular o fatorial de um número negativo.\n");
    } else {
        int resultado = calcularFatorial(num);
        printf("O fatorial de %d é: %d\n", num, resultado);
    }

    return 0;
}
