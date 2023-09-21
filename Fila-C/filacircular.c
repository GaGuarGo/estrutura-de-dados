#include <stdio.h>
#include <stdbool.h>

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

int main()
{
	CircularQueue queue;
	initQueue(&queue);

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	displayQueue(&queue);

	printf("Dequeued: %d\n", dequeue(&queue));
	printf("Dequeued: %d\n", dequeue(&queue));

	enqueue(&queue, 40);
	enqueue(&queue, 50);

	displayQueue(&queue);

	enqueue(&queue, 60);
	enqueue(&queue, 70);

	displayQueue(&queue);

	return 0;
}
