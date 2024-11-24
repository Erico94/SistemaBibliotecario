#include <stdio.h>
#include <stdlib.h>
#define totalDeLivros 81

struct Livro
{
    char titulo[50], autor[40], estaEmprestado, estaAtivoNoSistema;
    int anoDePublicacao, codigoIsbn, id;
};
char usuario[20][3];
struct Livro estoqueLivros[totalDeLivros];
void cadastrarLivro()
{
    struct Livro novoLivro;

    printf("Por favor, insira os dados solicitados abaixo.\n\n");
    printf("\nTitulo do livro:");
    scanf(" %[^\n]s", novoLivro.titulo);

    printf("\nNome do autor:");
    scanf(" %[^\n]s", novoLivro.autor);

    printf("\nAno de publicacao:");
    scanf("%d", &novoLivro.anoDePublicacao);

    printf("\nISBN:");
    scanf("%d", &novoLivro.codigoIsbn);

    novoLivro.id = quantidadeAtualEstoque;
    novoLivro.estaEmprestado = 'n';
    novoLivro.estaAtivoNoSistema = 's';

    estoqueLivros[quantidadeAtualEstoque] = novoLivro;
    quantidadeAtualEstoque++;
    printf("\n**** LIVRO SALVO COM SUCESSO ****");
    printaLivroNaTela(novoLivro);

    return;
}

void buscaLivro()
{
    int codigo = 0;
    printf("Insira o id ou codigo ISBN:");
    scanf("%d", &codigo);
    for (int i = 0; i < quantidadeAtualEstoque; i++)
    {
        if (codigo == estoqueLivros[i].codigoIsbn || codigo == estoqueLivros[i].id)
        {
            printaLivroNaTela(estoqueLivros[i]);
            /*Posso dar as seguintes opções: registrar emprestimo/devolução; editar; desativar*/
            return;
        }
    }
    printf("Livro nao encontrado");
    /*Posso dar as seguintes opções: cadastrar novo livro*/
    return;
}

void sessaoLivros()
{
    int selecao = 0;
    printf("\n******** Sessao livros ********");
    do
    {
        printf("\nDigite a opcao desejada:\n");
        printf("1 - Cadastrar livro.\n");
        printf("2 - Buscar livro por id ou ISBN.\n");
        printf("3 - Editar informacoes do livro.\n");
        printf("4 - Inativar livro.\n");
        printf("0 - Retornar ao menu inicial.\n");
        scanf("%d", &selecao);
        switch (selecao)
        {
        case 1:
            printf("Cadastrar livro.\n");
            break;
        case 2:
            buscaLivro();
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
    case 3:
        printf("\nRegistrar emprestimo.\n");
        // sessaoLivros();
        break;
    case 4:
        printf("\nRegistrar devolucao.\n");
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