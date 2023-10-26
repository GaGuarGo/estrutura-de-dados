#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashNode
{
    char *key;
    int value;
    struct HashNode *next;
};

#define TABLE_SIZE 100

struct HashNode *table[TABLE_SIZE] = {NULL};

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        // << Desloca 5 bits para esquerda, ou seja aumenta 5 zeros a esquerda
        /*

            int x = 1; // 0000 0001

            int x0 = (x << 0); // 0000 0001 Não deslocado
            int x1 = (x << 1); // 0000 0010
            int x2 = (x << 2); // 0000 0100
            int x3 = (x << 3); // 0000 1000
            int x4 = (x << 4); // 0001 0000
            int x5 = (x << 5); // 0010 0000
            int x6 = (x << 6); // 0100 0000
            int x7 = (x << 7); // 1000 0000

        */
        // >> Descola Bits para a direita
        /*
        int x = 128; // 1000 0000

        int x0 = (x >> 0); // 1000 0000 Não deslocado
        int x1 = (x >> 1); // 0100 0000
        int x2 = (x >> 2); // 0010 0000
        int x3 = (x >> 3); // 0001 0000
        int x4 = (x >> 4); // 0000 1000
        int x5 = (x >> 5); // 0000 0100
        int x6 = (x >> 6); // 0000 0010
        int x7 = (x >> 7); // 0000 0001
        */
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

// Insere um HashNode no final da lista dentro da Tabala HashTable
void insert(char *key, int value)
{
    int index = hash(key);
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        struct HashNode *current = table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
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
    insert("banana", 17);
    insert("cherry", 73);
    insert("dog", 28);
    insert("elephant", 99);
    insert("cat", 64);
    insert("bat", 7);
    insert("rat", 33);

    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'cherry': %d\n", search("cherry"));

    return 0;
}
