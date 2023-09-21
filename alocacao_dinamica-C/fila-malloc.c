#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da fila
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para a fila
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Função para criar uma nova fila vazia
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        perror("Erro na alocação de memória para a fila");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para enfileirar um elemento
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Função para desenfileirar um elemento
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Fila vazia\n");
        return -1; // Valor sentinela para indicar fila vazia
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Função para liberar a memória da fila
void freeQueue(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Elemento desenfileirado: %d\n", dequeue(queue));
    printf("Elemento desenfileirado: %d\n", dequeue(queue));
    printf("Elemento desenfileirado: %d\n", dequeue(queue));

    freeQueue(queue);

    return 0;
}
