#include <stdio.h>
#include <stdlib.h>

struct Livro
{
    char titulo[50];
    char autor[40];
    int anoDePublicacao;
    int codigoIsbn;
    char statusDeEmprestimo;
};
char usuario[20][3];

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