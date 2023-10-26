#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
};

struct HashNode *table[TABLE_SIZE] = { NULL };

//Outro código gerador de HashCode mais eficiente, pois espalha mais os dados
unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

void insert(char *key, int value) {
    int index = hash(key);
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
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

    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'cherry': %d\n", search("cherry"));


    return 0;
}
