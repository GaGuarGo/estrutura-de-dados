#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 3

struct Stack {
	int items[MAX_SIZE];
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

int calcular(char expression[MAX_SIZE]) {

	struct Stack stack;
	initialize(&stack);
	
	char str[30] = "";
	
	int result;

	for(int i = 0; i < strlen(expression); i++) {
		if(expression[i] == '+') {

			int num1 = pop(&stack);
			int num2 =  pop(&stack);


			push(&stack, num1 + num2);

		} else if (expression[i] == '-') {
			int num1 = pop(&stack);
			int num2 =  pop(&stack);

			push(&stack, num1 - num2);

		} else if(expression[i] == '*') {
			int num1 = pop(&stack);
			int num2 =  pop(&stack);

			push(&stack, num1 * num2);

		} else if(expression[i] == '/') {
			int num1 = pop(&stack);
			int num2 =  pop(&stack);

			push(&stack, num1/num2);
		}  else {
			
			//printf("%d ", expression[i] - '0');
			push(&stack, expression[i] - '0');
			
		}
	}
	
	result = pop(&stack);
	return result;

}


int main() {

	//char expressao[MAX_SIZE];
	//printf("Digite sua expressão na notação polonesa inversa!\n");
	//scanf("%s", &expressao);


	printf("Resultado da conta: %d", calcular("54+"));


	return 0;
}