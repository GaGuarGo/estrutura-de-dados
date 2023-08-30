#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
	char items[MAX_SIZE];
	int top;
};

// Inicializa a pilha
void initialize(struct Stack *s) {
	s->top = -1;
}
int isEmpty(struct Stack *s) {
	return s->top == 1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *s) {
	return s->top == MAX_SIZE - 1;
}


// Empilha um elemento na pilha
void push(struct Stack *s, int value) {
	if (isFull(s)) {
		printf("Erro: Pilha cheia\n");
	} else {
		s->top++;
		s->items[s->top] = value;
	}
}

// Desempilha um elemento da pilha
int pop(struct Stack *s) {
	if (isEmpty(s)) {
		printf("Erro: Pilha vazia\n");
		return -1;
	} else {
		int value = s->items[s->top];
		s->top--;
		return value;
	}
}



int estaBalanceado(char expression[MAX_SIZE]) {

	struct Stack exp;
	initialize(&exp);

	int balanced = 0;

	for(int i = 0; i < MAX_SIZE; i++) {

		if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
			push(&exp, expression[i]);
		}

		else if(expression[i] == ')') {

			if(pop(&exp) == '(') {
				balanced = 1;
			} else {
				balanced = 0;
			}

		} else if(expression[i] == ']') {

			if(pop(&exp) == '[') {
				balanced = 1;
			} else {
				balanced = 0;
			}

		} else if(expression[i] == '}') {

			if(pop(&exp) == '{') {
				balanced = 1;
			} else {
				balanced = 0;
			}




		}
		if (balanced == 0) return balanced;
	}
	return balanced;
}
int main () {


	char expression[MAX_SIZE];
	printf("Digite a expressão:\n");
	scanf("%s", expression);

	if(estaBalanceado(expression) == 1) {
		printf("\nA Expressao esta balanceada");
	} else {
		printf("\nA Expressao nao esta balanceada!");
	}




	return 0;
}