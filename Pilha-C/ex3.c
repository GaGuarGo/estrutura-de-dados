#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50
struct Stack {
	int items[MAX_SIZE];
	int top;
};


// Inicializa a pilha
void initialize(struct Stack *s) {
	s->top = -1;
}


// Verifica se a pilha está vazia
int isEmpty(struct Stack *s) {
	return s->top == -1;
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

void reverterPalavra(char word[MAX_SIZE]) {


	struct Stack wordStack;
	initialize(&wordStack);


	//Empilhando a Palavra

	for(int i = 0; i < strlen(word); i++) {

		push(&wordStack, word[i]);

	}

	//Desempilhando na Ordem Reversa

	for(int i = 0; i < strlen(word); i++) {

		word[i] = pop(&wordStack);

	}



}

int main() {

	char palavra[MAX_SIZE];
	printf("Digite sua Palvra:\n");
	scanf("%s", &palavra);

	reverterPalavra(palavra);

	printf("%s", palavra);

	return 0;
}