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

// pegar tamanho da lista
int lenghtList(struct LinkedList *list)
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

// inserir no final da lista

void insertAtEnding(struct LinkedList *list, int data)
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
        list->head = newNode;
    }

    else
    {
        struct Node *current = list->head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}

// inserir em uma posição aleatória da lista
void insertAtRandom(struct LinkedList *list, int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = list->head;

    int length = lenghtList(list);
    length++;

    if (!newNode)
    {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;

    // verifica se a lista está vazia
    if (current == NULL)
    {
        list->head = newNode;
    }
    else
    {
        // verificar se é uma posição válida
        if (position > length + 2)
        {
            perror("POSIÇÃO INVÁLIDA");
            exit(EXIT_FAILURE);
        }
        else
        {
            // verifica se quer inserir no último lugar da lista
            if (position == length + 2)
            {
                insertAtEnding(list, data);
            }
            // verificar se quer inserir no primeiro lugar da lista
            else if (position == 0)
            {
                insertAtBeginning(list, data);
            }
            // insere um valor qualquer em uma posição qualquer
            else
            {

                // acha a posição do elemento onde quer inserir o valor
                int pos = 1;
                while (pos < position)
                {
                    pos++;
                    current = current->next;
                }

                // pegando próximo valor do valor da posição escolhida
                struct Node *proximoAtual = current->next;

                // definindo que o proximo do valor da posição escolhida e o novo valor
                current->next = newNode;
                // definindo o proximo valor do valor escolhido
                newNode->next = proximoAtual;
            }
        }
    }
}

// remove o primeiro elemento da lista

void removeFirst(
    struct LinkedList *list)
{

    if (list->head == NULL)
    {
        perror("LISTA INEXISTENTE");
        exit(EXIT_FAILURE);
    }
    else
    {
        struct Node *current = list->head;
        list->head = current->next;
        current = NULL;
        free(current);
    }
}

// reove o último elemento da lista

void removeLast(
    struct LinkedList *list)
{

    struct Node *current = list->head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);

    current->next = NULL;
}

void removeAtRandom(struct LinkedList *list, int position)
{

    // O position considera o zero, como em um vetor normal
    //  ou seja, o index do número inicial é 0

    struct Node *current = list->head;

    if (current == NULL)
    {
        perror("LISTA VAZIA");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (position == 0)
        {
            removeFirst(list);
        }
        else if (position == lenghtList(list))
        {
            removeLast(list);
        }
        else
        {

            struct Node *valorAnterior = list->head;

            // pegar numero a ser removido
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }

            // printf(" Termo a ser removido: %d", current->data);

            // pegar o anterior
            while (valorAnterior->next != current)
            {
                valorAnterior = valorAnterior->next;
            }

            //   printf(" \nTermo anterior: %d", valorAnterior->data);

            valorAnterior->next = current->next;
            current = NULL;
            free(current);
        }
    }
}

// remove elementos iguais de uma lista
void removeEqualElements(struct LinkedList *list, int data)
{

    struct Node *current = list->head;
    int quantiItems = 0;

    if (current == NULL)
    {
        perror("LISTA VAZIA");
        exit(EXIT_FAILURE);
    }
    else
    {
        // pega a quantidade de elementos iguais
        while (current->next != NULL)
        {

            if (current->data == data)
            {

                quantiItems++;
            }

            current = current->next;
        }
        // remove a os itens iguais

        // percorre a lista X vezes, sendo X a quantidade de termos repetidos
        while (quantiItems >= 0)
        {
            // restarta a variável para poder percorrer a lista novamente
            current = list->head;
            int position = 0;
            for (int i = 0; i < lenghtList(list); i++)
            {

                // remove o item igual;
                if (current->data == data)
                {
                    removeAtRandom(list, position);
                    // displayList(list);
                    // printf("\nPosição do termo deletado: %d\n", position);
                    position--;
                }

                current = current->next;
                position++;
            }
            quantiItems--;
        }
    }
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

// Mostra a Posição da primeira ocorrência de um termo
int showPosition(struct LinkedList *list, int data)
{

    struct Node *current = list->head;
    int position = 0;

    while (current->next != NULL)
    {

        if (current->data == data)
        {
            return position;
        }
        current = current->next;
        position++;
    }
    return 0;
}

// Mostra todas as ocorrências de um elemento na lista e suas posições
void showPositions(struct LinkedList *list, int data)
{

    struct Node *current = list->head;
    if (current == NULL)
    {
        perror("LISTA VAZIA");
        exit(EXIT_FAILURE);
    }
    else
    {

        for (int i = 0; i < lenghtList(list); i++)
        {

            if (current->data == data)
            {
                printf("Termo: %d, Posição: %d \n", current->data, i);
            }

            current = current->next;
        }
    }
}
    int main()
    {
        struct LinkedList *list = createLinkedList();

        insertAtEnding(list, 10);
        insertAtEnding(list, 20);
        insertAtEnding(list, 20);
        insertAtEnding(list, 40);
        insertAtEnding(list, 50);
        insertAtEnding(list, 60);
        insertAtEnding(list, 70);
        insertAtEnding(list, 80);

        displayList(list);

        showPositions(list, 20);

        // printf("Posiçao do termo %d: %d", 40,
        //        showPosition(list, 40));

        // removeEqualElements(list, 20);

        // removeAtRandom(list, 4);

        // removeLast(list);

        // insertAtRandom(list, 80, 2);

        // displayList(list);

        freeLinkedList(list);

        return 0;
    }
