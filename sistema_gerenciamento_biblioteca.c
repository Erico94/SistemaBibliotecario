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
int direcionamentoMenuInicial(int selecao){
    switch (selecao)
    {
    case 1:
        printf("\nSessao usuarios.\n");
        // sessaoLivros();
        break;
    case 2:
        printf("\nSessao livros.\n");
        // sessaoUsuarios();
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
        scanf("%d", &opcaoSelecionada);
        direcionamentoMenuInicial(opcaoSelecionada);
    } while (opcaoSelecionada != 0);
    printf("\nEncerando programa.");
    system("PAUSE");
    return 0;
}