#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *items;
    int top;
    int max_size;
};

// Inicializa a pilha
void initialize(struct Stack *s, int size) {
    s->max_size = size;
    s->items = (int *)malloc(size * sizeof(int));
    s->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *s) {
    return s->top == s->max_size - 1;
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

// Libera a memória alocada pela pilha
void destroy(struct Stack *s) {
    free(s->items);
}

int main() {
    struct Stack myStack;
    int stackSize = 5;  // Tamanho máximo da pilha

    initialize(&myStack, stackSize);

    push(&myStack, 5);
    push(&myStack, 10);
    push(&myStack, 20);

    printf("Elemento desempilhado: %d\n", pop(&myStack));
    printf("Elemento desempilhado: %d\n", pop(&myStack));
    printf("Elemento desempilhado: %d\n", pop(&myStack));

    destroy(&myStack);  // Libera a memória alocada

    return 0;
}
