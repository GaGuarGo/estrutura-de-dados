#include<stdio.h>
#define MAX_SIZE 5

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Função para inicializar a fila
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Função para verificar se a fila está vazia
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Função para verificar se a fila está cheia
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Função para adicionar um elemento à fila
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("A fila está cheia. Não é possível adicionar mais elementos.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Função para remover um elemento da fila
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("A fila está vazia. Não é possível remover elementos.\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Elemento removido: %d\n", dequeue(&queue));
    printf("Elemento removido: %d\n", dequeue(&queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);

    return 0;
}
