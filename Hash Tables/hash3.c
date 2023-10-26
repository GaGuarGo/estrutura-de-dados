#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashNode {
    char *key;
    int value;
    struct HashNode *next; 
};

#define TABLE_SIZE 100

struct HashNode *table[TABLE_SIZE] = { NULL };

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}


//Insere um HashNode no final da lista dentro da Tabala HashTable
void insert(char *key, int value) {
    int index = hash(key);
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        struct HashNode *current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int search(char *key) {
    int index = hash(key);
    struct HashNode *current = table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; 
}

int main() {
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
