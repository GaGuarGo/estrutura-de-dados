#include <stdio.h>
#define MAX_SIZE 10

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

int main() {
    struct Stack myStack;
    initialize(&myStack);

    //Empilha
    push(&myStack, 5);
    push(&myStack, 10);
    push(&myStack, 20);

    printf("Elemento desempilhado: %d\n", pop(&myStack));
    printf("Elemento desempilhado: %d\n", pop(&myStack));
    printf("Elemento desempilhado: %d\n", pop(&myStack));

    return 0;
}