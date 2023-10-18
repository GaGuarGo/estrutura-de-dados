#include <stdio.h>
#include <stdlib.h>

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

// Função para criar uma nova lista vazia
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

// Função para inserir um elemento no final da lista
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

// Função para exibir os elementos da lista
void displayList(struct DoublyLinkedList *list)
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

// Função para liberar a memória da lista
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

void insertAtRandom(struct DoublyLinkedList *list, int data, int position)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = list->head;
    int thisPosition = 0;

    if (!newNode)
    {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }

    if (list->head == NULL)
    {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
        return;
    }
    else if (position > lenghtList(list))
    {
        perror("Posição Inválida");
        exit(EXIT_FAILURE);
    }
    else
    {

        while (thisPosition < position)
        {
            current = current->next;
            thisPosition++;
        }

        newNode->data = data;

        // anterior possui novo posterior
        current->prev->next = newNode;
        newNode->prev = current->prev;
        current->prev = newNode;
        newNode->next = current;
    }
}

//Função Ainda não Funciona, Não Descobri o ERRO
insertAtOrder(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = list->head;
    newNode->data = data;

    if (current == NULL || data < current->data)
    {
        newNode->next = current;
        list->tail = newNode;

        if (current != NULL)
        {
            current->prev = newNode;
        }
        current = newNode;
        return;
    }

    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

int main()
{
    struct DoublyLinkedList *list = createDoublyLinkedList();

    insertAtOrder(list, 20);
    insertAtOrder(list, 10);
    insertAtOrder(list, 30);
    insertAtOrder(list, 15);
    insertAtOrder(list, 5);

    // insertAtEnd(list, 10);
    // insertAtEnd(list, 20);
    // insertAtEnd(list, 40);
    // insertAtEnd(list, 50);
    // insertAtEnd(list, 60);
    // insertAtEnd(list, 70);
    // insertAtEnd(list, 80);
    // insertAtEnd(list, 90);
    // insertAtEnd(list, 100);

    displayList(list);

    // insertAtRandom(list, 50, 2);
    //  printf("\nTamanho da Lista: %d \n", lenghtList(list));

    freeDoublyLinkedList(list);

    return 0;
}
