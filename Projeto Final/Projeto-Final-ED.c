#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definição da estrutura do nó da árvore
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Função para criar um novo nó da árvore
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para avaliar a expressão matemática usando a árvore
int evaluateExpression(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (isdigit(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            printf("Operador inválido: %c\n", root->data);
            exit(EXIT_FAILURE);
    }
}

// Função para imprimir a árvore na notação infix
void printInfix(TreeNode* root) {
    if (root != NULL) {
        if (root->left != NULL || root->right != NULL) {
            printf("(");
        }

        printInfix(root->left);
        printf("%c", root->data);
        printInfix(root->right);

        if (root->left != NULL || root->right != NULL) {
            printf(")");
        }
    }
}

// Função para liberar a memória alocada para a árvore
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Função para construir a árvore a partir da expressão fornecida
TreeNode* buildTree(char expression[], int* index) {
    char token = expression[*index];
    (*index)++;

    if (token == '(') {
        TreeNode* root = createNode(expression[*index]);
        (*index)++;  // Pular o espaço em branco após o operador
        root->left = buildTree(expression, index);
        (*index)++;  // Pular o espaço em branco antes do próximo operando
        root->right = buildTree(expression, index);
        (*index)++;  // Pular o ')' no final
        return root;
    } else {
        return createNode(token);
    }
}

int main() {
    char expression1[] = "(+(+53)(*24))";
    char expression2[] = "(+34)";
    char expression3[] = "(- (* 5 2) 3)";
    char expression4[] = "(/ (* (+ 2 3) 4) 2)";
    char expression5[] = "(+ (+ (+ 1 2) 3) 4)";
    char expression6[] = "(- (* 2 (+ 3 5)) (/ 8 2))";

    int index = 0;
    TreeNode* tree1 = buildTree(expression1, &index);
    index = 0;
    TreeNode* tree2 = buildTree(expression2, &index);
    index = 0;
    TreeNode* tree3 = buildTree(expression3, &index);
    index = 0;
    TreeNode* tree4 = buildTree(expression4, &index);
    index = 0;
    TreeNode* tree5 = buildTree(expression5, &index);
    index = 0;
    TreeNode* tree6 = buildTree(expression6, &index);

    // printf("Expressão 1: ");
    // printInfix(tree1);
    // printf("\nResultado 1: %d\n\n", evaluateExpression(tree1));

    printf("Expressão 2: ");
    printInfix(tree2);
    printf("\nResultado 2: %d\n\n", evaluateExpression(tree2));

    // printf("Expressão 3: ");
    // printInfix(tree3);
    // printf("\nResultado 3: %d\n\n", evaluateExpression(tree3));

    // printf("Expressão 4: ");
    // printInfix(tree4);
    // printf("\nResultado 4: %d\n\n", evaluateExpression(tree4));

    // printf("Expressão 5: ");
    // printInfix(tree5);
    // printf("\nResultado 5: %d\n\n", evaluateExpression(tree5));

    // printf("Expressão 6: ");
    // printInfix(tree6);
    // printf("\nResultado 6: %d\n\n", evaluateExpression(tree6));

    // Liberar memória alocada para as árvores
    freeTree(tree1);
    freeTree(tree2);
    freeTree(tree3);
    freeTree(tree4);
    freeTree(tree5);
    freeTree(tree6);

    return 0;
}
