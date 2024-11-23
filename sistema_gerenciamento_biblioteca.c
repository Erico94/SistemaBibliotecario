#include <stdio.h>
#include <stdlib.h>
#define totalDeLivros 81

struct Livro
{
    char titulo[50];
    char autor[40];
    int anoDePublicacao;
    int codigoIsbn;
    int id;
    char estaEmprestado;
    char estaAtivoNoSistema;
};
char usuario[20][3];
struct Livro estoqueLivros[totalDeLivros];
int quantidadeAtualEstoque;

void buscaLivro()
{
    int codigo = 0;
    printf("Insira o id ou codigo ISBN:");
    scanf("%d", &codigo);
    for (int i = 0; i < quantidadeAtualEstoque; i++)
    {
        if (codigo == estoqueLivros[i].codigoIsbn || codigo == estoqueLivros[i].id)
        {
            printf("\nNome: %s", estoqueLivros[i].titulo);
            printf("\nAutor: %s", estoqueLivros[i].autor);
            printf("\nAno de publicacao: %d", estoqueLivros[i].anoDePublicacao);
            printf("\nISBN: %d", estoqueLivros[i].codigoIsbn);
            printf("\nID: %d", estoqueLivros[i].id);
            printf("\nEmprestado: %c", estoqueLivros[i].estaEmprestado);
            printf("\nAtivo no sistema: %c", estoqueLivros[i].estaAtivoNoSistema);
            /*Posso dar as seguintes opções: registrar emprestimo/devolução; editar; desativar*/
            return;
        }
        printf("Livro nao encontrado");
        /*Posso dar as seguintes opções: cadastrar novo livro*/
        return;
    }
}

void sessaoLivros()
{
    int selecao = 0;
    printf("\n******** Sessao livros ********");
    do
    {
        printf("\nDigite a opcao desejada:\n");
        printf("1 - Cadastrar livro.\n");
        printf("2 - Buscar livro por id.\n");
        printf("3 - Inativar livro.\n");
        printf("0 - Retornar ao menu inicial.\n");
        scanf("%d", &selecao);
        switch (selecao)
        {
        case 1:
            printf("Cadastrar livro.\n");
            break;
        case 2:
            printf("Buscar livro.\n");
            break;
        case 3:
            printf("Inativar livro.\n");
            break;
        default:
            break;
        }
    } while (selecao != 0);
}

int direcionamentoMenuInicial(int selecao)
{
    switch (selecao)
    {
    case 1:
        printf("\nSessao usuarios.\n");
        // sessaoLivros();
        break;
    case 2:
        sessaoLivros();
        break;
    default:
        break;
    }
    return 0;
}

int main()
{
    int opcaoSelecionada = 0;

    printf("\nSeja bem vindo ao BiblioHub, seu sistema de gerenciamento de biblioteca.\n");
    do
    {
        printf("\nDigite o numero correspondente a opcao desejada:\n");
        printf("1 - Usuarios.\n");
        printf("2 - Livros.\n");
        printf("3 - Registrar emprestimo.\n");
        printf("4 - Registrar devolucao.\n");
        printf("0 - Encerrar programa.\n");
        scanf("%d", &opcaoSelecionada);
        direcionamentoMenuInicial(opcaoSelecionada);
    } while (opcaoSelecionada != 0);
    printf("\nEncerando programa.");
    system("PAUSE");
    return 0;
}