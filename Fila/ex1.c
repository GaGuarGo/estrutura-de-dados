#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 20

struct Queue
{
    char items[MAX_SIZE];
    int front;
    int rear;
};

// Função para inicializar a fila
void initialize(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Função para verificar se a fila está vazia
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Função para verificar se a fila está cheia
int isFull(struct Queue *queue)
{
    return queue->rear == MAX_SIZE - 1;
}

// Função para adicionar um elemento à fila
void enqueue(struct Queue *queue, char value)
{
    if (isFull(queue))
    {
        printf("A fila está cheia. Não é possível adicionar mais elementos.\n");
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Função para remover um elemento da fila
char dequeue(struct Queue *queue)
{
    char item;
    if (isEmpty(queue))
    {
        printf("A fila está vazia. Não é possível remover elementos.\n");
        return -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}
bool isPalindromo(char palavra[MAX_SIZE])
{

    struct Queue queue;
    initialize(&queue);

    // enfileira a palavra

    ;
    for (int a = 0; a < strlen(palavra); a++)
    {
        enqueue(&queue, palavra[a]);
    }

    // verifica se é palíndromo
    
    for (int i = strlen(palavra) - 1; i >= 0; i--)
    {
    	
    //	printf("Fila: %c\n" , dequeue(&queue));
    	//printf("Palavra invertida: %c\n", palavra[i]);
    	
        if (palavra[i] != dequeue(&queue))
        {
            return false;
        }
    }

    return true;
}

int main()
{

    char word[MAX_SIZE];

    printf("Digite sua Palavra: \n");
    scanf("%s", &word);

    if (isPalindromo(word))
    {
        printf("Sua Palavra eh um palindromo!");
    }
    else
    {
        printf("Sua Palavra não eh um palindromo!");
    }

    return 0;
}