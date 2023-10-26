/*
Implementar no código abaixo a função que inverte uma lista de forma recursiva.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista
struct Node
{
    int data;
    struct Node *next;
};

// Estrutura para a lista ligada
struct LinkedList
{
    struct Node *head;
};

// Função para criar uma nova lista vazia
struct LinkedList *createLinkedList()
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if (!list)
    {
        perror("Erro na alocação de memória para a lista");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

// Função para inserir um elemento no início da lista
void insertAtBeginning(struct LinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// Função para exibir os elementos da lista
void displayList(struct LinkedList *list)
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
void freeLinkedList(struct LinkedList *list)
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

void displayReverseListRecursive(struct Node *current, struct Node *prev)
{

    // Implemente aqui o seu código recursivo!
}

void displayReverseList(struct LinkedList *list)
{
    printf("Lista Invertida: NULL <- ");
    displayReverseListRecursive(list->head, NULL);
}

int main()
{
    struct LinkedList *list = createLinkedList();

    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);

    displayList(list);
    displayReverseList(list);

    freeLinkedList(list);

    return 0;
}