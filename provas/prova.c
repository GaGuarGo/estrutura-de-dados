#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Stack
{
    int items[MAX_SIZE];
    int top;
};

// Estrutura para um nó da lista
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Estrutura para a lista duplamente encadeada
struct DoublyLinkedList
{
    struct Node *head;
    struct Node *tail;
};

// Inicializa a pilha
void initialize(struct Stack *s)
{
    s->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// Empilha um elemento na pilha
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Erro: Pilha cheia\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = value;
    }
}

// Desempilha um elemento da pilha
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    else
    {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

// ESTRUTURAS DA LISTA DUPLAMENTE ENCADEADA

struct DoublyLinkedList *createDoublyLinkedList()
{
    struct DoublyLinkedList *list = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    if (!list)
    {
        perror("Erro na alocação de memória para a lista");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertAtEnd(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
}

void displayDoublyList(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;
    printf("Lista: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void freeDoublyLinkedList(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void removeAtRandom(struct DoublyLinkedList *list, int position)
{

    struct Node *current = list->head;
    int pos = 0;
    // pegar o elemento na posição certa
    while (pos < position)
    {
        current = current->next;
        pos++;
    }

    // printf("\nVALOR REMOVIDO %d\n", current->data);

    struct Node *anterior = current->prev;
    struct Node *posterior = current->next;

    // PRIMEIRO TERMO
    if (anterior == NULL)
    {
        list->head = posterior;
    }
    // ÚLTIMO TERMO
    //NÃO CONSEGUI RETIRAR O TERMO QUANDO ELE É O ÚLTIMO ESTÁ DANDO ERRO
    else if (posterior == NULL)
    {

        list->tail = anterior;
    }
    else
    {

        anterior->next = posterior;
        posterior->prev = anterior;
    }

    current = NULL;
    free(current);
}

void deleteNegatives(struct DoublyLinkedList *list)
{

    struct Node *current = list->head;
    int position = 0;

    while (current->next != NULL)
    {

        if (current->data < 0)
        {
            removeAtRandom(list, position);
            position = 0;
            current = list->head;
        }

        current = current->next;
        position++;
    }
}

int lenghtList(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;
    int quant = 0;

    if (current == NULL)
    {
        printf("LISTA INEXISTENTE");
        return 0;
    }
    else
    {

        while (current->next != NULL)
        {
            current = current->next;
            quant++;
        }
    }
    return quant;
}

int main()
{

    int vetor[MAX_SIZE] = {-9, 5, 4, 5, -9, -5, 4, 7, 9, 1};

    struct Stack myStack;
    initialize(&myStack);

    // printf("Preencha A pilha com 10 valores: \n");
    // for (int i = 0; i < 10; i++)
    // {
    //     int valor;
    //     printf("Valor %d: ", i + 1);
    //     scanf("%d", &valor);
    //     push(&myStack, valor);
    // }

    // TRANSFORMAR A PILHA EM LISTA DUPLAMENTE ENCADEADA
    struct DoublyLinkedList *list = createDoublyLinkedList();
    for (int i = 0; i < MAX_SIZE; i++)
    {
        insertAtEnd(list, vetor[i]);
    }

    printf("LISTA INTEIRA: \n");
    displayDoublyList(list);

    // TIRAR OS NÚMEROS NEGATIVOS DA LISTA
    printf("LISTA POSITIVA: \n");
    deleteNegatives(list);
    displayDoublyList(list);

    //QUANTIDAICA OS ELEMENTOS
    printf("QUANTIDADE DE ELEMENTOS RESTANTES: %d", lenghtList(list) + 1);
}