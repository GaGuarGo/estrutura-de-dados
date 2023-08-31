#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct
{
	int data[MAX_SIZE];
	int front;
	int rear;
	bool isFull;
} CircularQueue;

void initQueue(CircularQueue *queue)
{
	queue->front = -1;
	queue->rear = -1;
	queue->isFull = false;
}

bool isEmpty(CircularQueue *queue)
{
	return (queue->front == -1 && queue->rear == -1);
}

bool isFull(CircularQueue *queue)
{
	return queue->isFull;
}

void enqueue(CircularQueue *queue, int value)
{
	if (isFull(queue))
	{
		printf("Queue is full. Cannot enqueue.\n");
		return;
	}

	if (isEmpty(queue))
	{
		queue->front = 0;
		queue->rear = 0;
	}
	else
	{
		queue->rear = (queue->rear + 1) % MAX_SIZE;
	}

	queue->data[queue->rear] = value;

	if (queue->rear == ((queue->front - 1 + MAX_SIZE) % MAX_SIZE))
	{
		queue->isFull = true;
	}
}

int dequeue(CircularQueue *queue)
{
	if (isEmpty(queue))
	{
		printf("Queue is empty. Cannot dequeue.\n");
		return -1;
	}

	int dequeuedValue = queue->data[queue->front];

	if (queue->front == queue->rear)
	{
		queue->front = -1;
		queue->rear = -1;
		queue->isFull = false;
	}
	else
	{
		queue->front = (queue->front + 1) % MAX_SIZE;
	}

	return dequeuedValue;
}

void displayQueue(CircularQueue *queue)
{
	if (isEmpty(queue))
	{
		printf("Queue is empty.\n");
		return;
	}

	printf("Queue: ");
	int i = queue->front;
	do
	{
		printf("%d ", queue->data[i]);
		i = (i + 1) % MAX_SIZE;
	} while (i != (queue->rear + 1) % MAX_SIZE);
	printf("\n");
}

void adicionarTarefa(CircularQueue *trabalho, int time)
{

	int somaMinutos = 0;

	if (isEmpty)
	{
		somaMinutos = time;
	}
	else
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{

			somaMinutos = somaMinutos + trabalho->data[i];
		}
	}

	printf("SOMA TOTAL DE MINUTOS: %d \n", somaMinutos);

	if (somaMinutos > 300)
	{
		printf("\nLimite de 300 minutos acumulados atingido!");
		return 0;
	}
	else
	{
		printf("\nTarefa Adicionada com Sucesso!\n\n");
		enqueue(trabalho, &time);
	}
}

void executarTarefa(CircularQueue *trabalho)
{

	if (isEmpty)
	{

		printf("Não Há tarefas a serem Executadas!");
	}
	else

	{
		printf("Tarefa Executada com Sucesso!");
		dequeue(trabalho);
	}
}

int main()
{

	CircularQueue trabalho;
	initQueue(&trabalho);

	int opcao;
	int minutos = 0;

	do
	{
		printf("Escolha uma opcao:\n");
		printf("1. Adicionar Tarefa\n");
		printf("2. Executar Tarefa\n");
		printf("0. Sair\n");
		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:

			printf("Digite a duração da tarefa em Minutos: [m]\n");
			scanf("%d", &minutos);

			adicionarTarefa(&trabalho, minutos);

			break;
		case 2:

			executarTarefa(&trabalho);

			break;

		case 0:
			break;
		default:
			printf("Opcao invalida.\n");
		}
	} while (opcao != 0);

	return 0;
}
