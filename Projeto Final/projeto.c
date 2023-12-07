#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
typedef struct Node
{
    char data; // Pode ser um operador (+, -, *, /) ou um número
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para avaliar a expressão usando a árvore binária
int evaluateExpression(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // Se o nó for um número, retorna esse número
    if (root->data >= '0' && root->data <= '9')
    {
        return root->data - '0';
    }

    // Avalia as subárvores esquerda e direita
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    // Realiza a operação com base no operador
    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        return 0;
    }
}

//Função para Criar uma árvore binária a partir de uma equação com 
//Notação Polonesa Invertida
struct Node *createTreeFromExpression(const char *expression, int *pos)
{
    struct Node *root = NULL;

    // Ignorar espaços em branco
    while (expression[*pos] == ' ')
    {
        (*pos)++;
    }

  
    if (expression[*pos] == '(')
    {
        (*pos)++; 

       
        root = createNode(expression[*pos]);
        (*pos)++; 

     
        root->left = createTreeFromExpression(expression, pos);
        root->right = createTreeFromExpression(expression, pos);

       
        (*pos)++;

      
        if (expression[*pos] == ')')
        {
            (*pos)++;
        }
    }
    else
    {
     
        root = createNode(expression[*pos]);
        (*pos)++; 
    }

    return root;
}

// Função para imprimir a expressão na notação infixada
void printInfix(Node *root)
{
    if (root != NULL)
    {
        if (root->data >= '0' && root->data <= '9')
        {
            printf("%c", root->data);
        }
        else
        {
            printf("(");
            printInfix(root->left);
            printf(" %c ", root->data);
            printInfix(root->right);
            printf(")");
        }
    }
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(Node *root)
{
    if (root != NULL)
    {

        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
   
    const char *expression1 = "(- (* 2 (+ 3 5)) (/ 8 2))";

    int pos = 0;
    struct Node *root = createTreeFromExpression(expression1, &pos);

    // Avaliando e imprimindo a expressão
    printf("Expressao Infixada: ");
    printInfix(root);
    printf("\nResultado: %d\n", evaluateExpression(root));

    freeTree(root);

    return 0;
}
