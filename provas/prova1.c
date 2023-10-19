

/*
Implementar as duas funções abaixo chamadas dentro do main.
A primeira função cria uma lista simplesmente encadeada, a partir de uma lista duplamente encadeada.
Já a segunda função imprime somente os elementos impares da lista.
Por exemplo, uma lista com 5 elementos, imprime os valores dos nodes 1, 3 e 5.

struct LinkedList* list2 = createLinkedList(list1);
displayOddNodes(list2);
*/

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

// Estrutura para um nó da lista simplesmente Encadeada
struct SimpleNode
{
    int data;
    struct SimpleNode *next;
};

// Estrutura para a lista Simplesmente Encadeada
struct LinkedList
{
    struct SimpleNode *head;
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

// Função para criar uma nova lista simples a partir de uma dupla

struct LinkedList *createLinkedList(struct DoublyLinkedList *list)
{

    struct LinkedList *simpleList = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    struct SimpleNode *newNode;
    struct Node *current = list->head;
    if (!simpleList)
    {
        perror("Erro na alocação de memória para a lista");
        exit(EXIT_FAILURE);
    }

    // Starta a Lista Simples
    simpleList->head = NULL;

    // Percorre Toda a Lista Duplamente Encadeada
    while (current != NULL)
    {

        newNode = (struct SimpleNode *)malloc(sizeof(struct SimpleNode));

        // Pega termo por termo
        newNode->data = current->data;
        newNode->next = NULL;

        // Verifica se a Lista Simples esta Vazia
        if (simpleList->head == NULL)
        {
            simpleList->head = newNode;
        }
        // Caso Contrário Vai inserir no final da lista Simples
        else
        {

            struct SimpleNode *currentSimple = simpleList->head;

            // percorre toda a lista simples para inserir no final
            while (currentSimple->next != NULL)
            {
                currentSimple = currentSimple->next;
            }
            // insere no final
            currentSimple->next = newNode;
            // newNode->next = NULL;
        }
        // Dá continuidade para o loop para outro elemento da lista duplamente encadeada
        current = current->next;
    }

    return simpleList;
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

// Funças para exibir os elementos da Lista Simples

void displaySimpleList(struct LinkedList *list)
{
    struct SimpleNode *current = list->head;
    printf("Lista Simples: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função que printa somente os Nodes em posições ímpares;

void displayOddNodes(struct LinkedList *list)
{

    struct SimpleNode *current = list->head;
    int position = 0;

    printf("Lista Ímpares: ");

    while (current != NULL)
    {

        if ((position + 1) % 2 != 0)
        {
            printf("%d -> ", current->data);
        }

        current = current->next;
        position++;
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

// Funçao para liberar memória da lista

void freeLinkedList(struct LinkedList *list)
{
    struct SimpleNode *current = list->head;
    while (current != NULL)
    {
        struct SimpleNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main()
{
    struct DoublyLinkedList *list1 = createDoublyLinkedList();

    insertAtEnd(list1, 10);
    insertAtEnd(list1, 20);
    insertAtEnd(list1, 30);

    displayDoublyList(list1);

    // Implementar as duas funções abaixo:
    // Cria uma lista simples a partir de uma lista dupla
    struct LinkedList *list2 = createLinkedList(list1);
    displaySimpleList(list2);

    // Imprime somente os nodes nas posições impares, nesse caso: 10 e 30
    displayOddNodes(list2);

    freeDoublyLinkedList(list1);
    freeLinkedList(list2);

    return 0;
}