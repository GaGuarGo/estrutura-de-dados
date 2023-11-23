#include <stdio.h>
#include <stdlib.h>


// Definindo a estrutura do nó da árvore
struct TreeNode {
    int data;
    int count;  // Contador para controlar a duplicação de valores
    int height; // Altura do nó
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para obter a altura de um nó
int getHeight(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Função para atualizar a altura de um nó
void updateHeight(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Função para calcular o fator de equilíbrio de um nó
int getBalanceFactor(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Função para criar um novo nó
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->count = 1;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para realizar a rotação simples à direita
struct TreeNode* rotateRight(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    // Realizando a rotação
    x->right = y;
    y->left = T2;

    // Atualizando as alturas
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Função para realizar a rotação simples à esquerda
struct TreeNode* rotateLeft(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    // Realizando a rotação
    y->left = x;
    x->right = T2;

    // Atualizando as alturas
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Função para inserir um valor na árvore AVL
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value == root->data) {
        // Incrementa o contador se o valor já existe na árvore
        root->count++;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    // Atualizando a altura do nó atual
    updateHeight(root);

    // Obtendo o fator de equilíbrio do nó
    int balance = getBalanceFactor(root);

    printf("\nNode: %i e Balance: %i \n", root->data, balance);

    // Caso de desbalanceamento à esquerda
    if (balance > 1) {
        if (value < root->left->data) {
            // Rotação simples à direita
            printf("\nRotacao simples direita");
            return rotateRight(root);
        } else {
            // Rotação dupla à direita (rotação à esquerda seguida de rotação à direita)
            printf("\nRotacao dupla esquerda e direita");
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    // Caso de desbalanceamento à direita
    if (balance < -1) {
        if (value > root->right->data) {
            // Rotação simples à esquerda
             printf("\nRotacao simples esquerda");
            return rotateLeft(root);
        } else {
            // Rotação dupla à esquerda (rotação à direita seguida de rotação à esquerda)
            printf("\nRotacao dupla direita e esquerda");
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}


void printTree(struct TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, level + 1);

    int i;
    for (i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%i-%i\n", root->data,root->height);

    printTree(root->left, level + 1);
}


int main() {
    struct TreeNode* root = NULL;

    // Inserindo valores na árvore
    int i;
    for(i=0; i < 11; i ++){
        printf("\n\n\n*************Insert:  %i **********************\n\n", i);
        root = insert(root, i);
        printf("\n\n\n************* Tree: **********************\n\n");
        printTree(root,0);   
        printf("\n\n\n"); 
    }

    return 0;
}
