typedef struct no
{
    int valor;
    struct no *direita, *esquerda;
} NoArv;

NoArv *inserir_versao_1(NoArv *raiz, int num)
{
    if (raiz == NULL)
    {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else
    {
        if (num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num)
{
    if (*raiz == NULL)
    {
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else
    {
        if (num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num)
{
    NoArv *aux = *raiz;
    while (aux)
    {
        if (num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv *buscar_versao_1(NoArv *raiz, int num)
{
    if (raiz)
    {
        if (num == raiz->valor)
            return raiz;
        else if (num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv *buscar_versao_2(NoArv *raiz, int num)
{
    while (raiz)
    {
        if (num < raiz->valor)
            raiz = raiz->esquerda;
        else if (num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternÃ¡rio
    // return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

// função para remover nós da Árvore binária
NoArv *remover(NoArv *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else
    { // procura o nó a remover
        if (raiz->valor == chave)
        {
            // remove nós folhas (nós sem filhos)
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else
            {
                // remover nós que possuem 1 ou 2 filhos
            }
        }
        else
        {
            if (chave < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_versao_1(NoArv *raiz)
{
    if (raiz)
    {
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz)
{
    if (raiz)
    {
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main()
{

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            // raiz = inserir_versao_1(raiz, valor);
            // inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            // busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if (busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir_versao_2(raiz);
            printf("\n\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if (opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    } while (opcao != 0);

    return 0;
}