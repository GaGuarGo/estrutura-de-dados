#include <stdio.h>

#define MAX_DISKS 64

// Estrutura para representar uma pilha
struct Stack {
    int top;
    int array[MAX_DISKS];
};

// Função para inicializar a pilha
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Função para empilhar um elemento na pilha
void push(struct Stack *stack, int item) {
    if (stack->top == MAX_DISKS - 1) {
        printf("A pilha está cheia.\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Função para desempilhar um elemento da pilha
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("A pilha está vazia.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Função auxiliar para resolver a Torre de Hanoi
void hanoi(int n, struct Stack *source, struct Stack *aux, struct Stack *dest) {
    if (n == 1) {
        int disk = pop(source);
        push(dest, disk);
        printf("Mova o disco %d de %c para %c\n", disk, 'A' + source->top, 'A' + dest->top);
        return;
    }

    hanoi(n - 1, source, dest, aux);

    int disk = pop(source);
    push(dest, disk);
    printf("Mova o disco %d de %c para %c\n", disk, 'A' + source->top, 'A' + dest->top);

    hanoi(n - 1, aux, source, dest);
}

int main() {
    int numDisks;
    struct Stack towerA, towerB, towerC;

    initializeStack(&towerA);
    initializeStack(&towerB);
    initializeStack(&towerC);

    printf("Digite o número de discos: ");
    scanf("%d", &numDisks);

    // Inicializa a torre A com os discos
    for (int i = numDisks; i > 0; i--) {
        push(&towerA, i);
    }

    printf("Resolvendo a Torre de Hanoi com %d discos:\n", numDisks);
    hanoi(numDisks, &towerA, &towerB, &towerC);

    return 0;
}
