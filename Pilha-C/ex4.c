#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Função para verificar se um caractere é um operador válido
bool ehOperadorValido(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função para verificar se uma expressão contém operadores em posições válidas
bool verificaExpressao(char *expressao) {
    int comprimento = strlen(expressao);
    
    // Verifica se a expressão está vazia
    if (comprimento == 0) {
        return false;
    }

    // Verifica se o primeiro caractere é um operador, o que não é válido
    if (ehOperadorValido(expressao[0])) {
        return false;
    }

    // Verifica se o último caractere é um operador, o que não é válido
    if (ehOperadorValido(expressao[comprimento - 1])) {
        return false;
    }

    for (int i = 1; i < comprimento - 1; i++) {
        // Verifica se há dois operadores consecutivos, o que não é válido
        if (expressao[i] == ' ') {
        
            
            char antecessor = expressao[i-2];
            char sucessor = expressao[i+2];
            
            if(!ehOperadorValido(antecessor) && !ehOperadorValido(sucessor)){
            	return false;
			} 
            
        } 
    }

    return true;
}

int main() {
    char expressao[100];

    printf("Digite a expressão: ");
    scanf("%99[^\n]", expressao);

    if (verificaExpressao(expressao)) {
        printf("Expressão válida\n");
    } else {
        printf("Expressão inválida\n");
    }

    return 0;
}
