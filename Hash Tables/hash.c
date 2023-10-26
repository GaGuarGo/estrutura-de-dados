#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct HashNode
{
    char *key;
    int value;
    struct HashNode *next;
};

struct HashNode *table[TABLE_SIZE] = {NULL};

int hash(char *key)
{
    int hash = 0;
    while (*key)
    {
        hash = (hash + *key) % TABLE_SIZE;
        key++;
    }
    return hash;
}

// insere no começo
void insert(char *key, int value)
{
    int index = hash(key);
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    // aponta para o próximo que ja está na lista dentro da table
    newNode->next = table[index];
    // Entra na na posição que o primeiro da lista
    table[index] = newNode;
}

void deleteItemHashTable(char *key)
{

    int index = hash(key);
    struct HashNode *current = table[index];

    if (current->next != NULL)

    {

        struct HashNode *ant;

        // Pegar o Valor Anterior do Valor a ser excluído
        while (strcmp(ant->key, key) == 1)
        {
            ant = ant->next;
        }

        ant->next = current->next;
    }

    printf("\n\nCHAVE A SER REMOVIDA: %s VALOR A SER REMOVIDO: %d", current->key, current->value);

    table[index] = NULL;
    // free(current);
}

void displayHashTable()
{

    struct HashNode *current;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        current = table[i];
        if (current != NULL)
        {
            printf(" \n Chave: %s , Valor: %d", current->key, current->value);
            if (current->next != NULL)
            {
                while (current != NULL)
                {
                    printf(" \n Chave: %s , Valor: %d", current->key, current->value);
                }
            }
        }
    }
}

int search(char *key)
{
    int index = hash(key);
    struct HashNode *current = table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int main()
{
    insert("apple", 42);
    insert("air", 56);
    insert("a", 89);
    insert("airplane", 100);
    

    insert("banana", 17);
    insert("cherry", 73);

    printf("HASH TABLE INICIAL:");
    displayHashTable();

    deleteItemHashTable("a");

    printf("\n\nHASH TABLE MODIFICADA:");
    displayHashTable();

    // printf("Value for 'apple': %d\n", search("apple"));
    // printf("Value for 'banana': %d\n", search("banana"));
    // printf("Value for 'cherry': %d\n", search("cherry"));

    return 0;
}
