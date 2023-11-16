#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Função para criar um novo nó
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore
// Não Deixa Inserir Valores Duplicados
struct Node *insert(struct Node *root, int value)
{

    if (root == NULL)
    {
        return createNode(value);
    }

    if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// Função para inserir um novo nó na árvore
struct Node *createTree(int value)
{
    return createNode(value);
}

// Função para percorrer a árvore em ordem crescente
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        // Preferencia por nós da Esquerda
        // Começa com o "Galho" Da Esquerda e depois vai para a direita se existir
        // Vai para esquerda, se não tiver vai para a direita
        // Vai e Volta
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Pesquisa se há um valor Correspondente
struct Node *searchNode(int value, struct Node *root)
{

    if (value >= root->data)
    {

        if (value == root->data)
        {
            // printf("\nVALOR ENCONTRADO!!!");
            return root;
        }

        return searchNode(value, root->right);
    }
    else
    {

        if (value == root->data)
        {
            // printf("\nVALOR ENCONTRADO!!!");
            return root;
        }
        return searchNode(value, root->left);
    }
}

struct Node *searchBeforeNode(int value, struct Node *root)
{
    if (value >= root->data)
    {
        if (value == root->left->data || value == root->right->data)
        {
            return root;
        }

        return searchBeforeNode(value, root->right);
    }
    else
    {
        if (value == root->left->data || value == root->right->data)
        {
            return root;
        }
        return searchBeforeNode(value, root->left);
    }
}

struct Node *menorValor(struct Node *current)
{

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Remover um nó da árvore pela primeira ocorrência
void remover(struct Node *root, int value)
{

    struct Node *deletedNode = searchNode(value, root);
    struct Node *antDeletedNode = searchBeforeNode(value, root);

    struct Node *left = deletedNode->left;
    struct Node *right = deletedNode->right;

    // Pega o menor valor a partir do antecessor
    struct Node *aux = menorValor(antDeletedNode);

    if (root == NULL)
    {
        printf("ÁRVORE INEXISTENTE");
        return;
    }

    // remove o valor do nó pai
    if (antDeletedNode->right == deletedNode)
    {
        antDeletedNode->right = NULL;
    }
    else
    {
        antDeletedNode->left = NULL;
    }

    // Nós Folhas
    if (left == NULL && right == NULL)
    {
        deletedNode = NULL;
        free(deletedNode);
    }
    // Nós com apenas um filho
    else if (left == NULL || right == NULL)
    {

        if (left == NULL)
        {
            aux->left = right;
        }
        else
        {
            aux->left = left;
        }

        deletedNode = NULL;
        free(deletedNode);
    }
    // Nós com dois filhos
    else
    {

        aux->left = left;
        left->right = right;

        deletedNode = NULL;
        free(deletedNode);
    }
}

// Verifica tamanho da Árvore
int altura(struct Node *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int esq = altura(raiz->left);
        int dir = altura(raiz->right);
        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}


//Procura um Nó e lista seu Pai e Filhos
void searchNodeAndChild(struct Node *root, int value)
{

    struct Node *current = searchNode(value, root);
    struct Node *dadCurrent = searchBeforeNode(value, root);

    if (dadCurrent == NULL)
    {
        printf("Esse nó não possui um pai");
    }
    else
    {
        printf("No Pai: %d\n", dadCurrent->data);
    }

    printf("Nos Filhos: ");
    inorderTraversal(current);
}

//Lista todos os Nós Folhas
void searchAllLeafNodes(struct Node *root)
{

    if (root != NULL)
    {

        searchAllLeafNodes(root->right);

        if (root->right == NULL && root->left == NULL)
        {
            printf("No Folha %d ", root->data);
        }

        searchAllLeafNodes(root->left);
    }
}

//Lista todos os Nós Pais
void searchAllDadNodes(struct Node *root)
{

    if (root != NULL)
    {

        searchAllDadNodes(root->right);

        if (root->right != NULL || root->left != NULL)
        {
            printf("No Pai %d ", root->data);
        }

        searchAllDadNodes(root->left);
    }
}

int main()
{
    // Criando a raiz da árvore
    struct Node *root;

    // Inserindo elementos na árvore
    root = createTree(50);

    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);

    insert(root, 60);
    insert(root, 80);
    insert(root, 10);

    // Imprimindo a árvore em ordem
    printf("Arvore em ordem: ");
    inorderTraversal(root);

    // printf("\nAltura da Arvore: %d", altura(root));

    // remover(root, 10);
    // printf("\n");
    // printf("Arvore Alterada: ");
    // inorderTraversal(root);

    // searchNodeAndChild(root, 70);

    searchAllDadNodes(root);
    return 0;
}
