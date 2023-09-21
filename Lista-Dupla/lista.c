#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Estrutura para a lista duplamente encadeada
struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Função para criar uma nova lista vazia
struct DoublyLinkedList* createDoublyLinkedList() {
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if (!list) {
        perror("Erro na alocação de memória para a lista");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Função para inserir um elemento no final da lista
void insertAtEnd(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
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
void displayList(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
void freeDoublyLinkedList(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    struct DoublyLinkedList* list = createDoublyLinkedList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);

    displayList(list);

    freeDoublyLinkedList(list);

    return 0;
}
