#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define totalDeLivros 80
#define MAX_USUARIOS 100
#define TAMANHO_NOME 120
#define TAMANHO_ENDERECO 150

struct Livro
{
    char titulo[50], autor[40], codigoIsbn[15], estaEmprestado, estaAtivoNoSistema;
    int anoDePublicacao, id, emPosseDeUsuarioId;
};
struct Livro estoqueLivros[totalDeLivros];
int quantidadeLivrosEstoque = 0;
char nomeUsuario[MAX_USUARIOS][120];
char enderecoUsuario[MAX_USUARIOS][150];
int idUsuario[MAX_USUARIOS], quantidadeUsuariosAtuais = 0;

void printaLivroNaTela(struct Livro livro)
{
    printf("\n**************************************\n");
    printf("**************************************");
    printf("\nTitulo: %s", livro.titulo);
    printf("\nAutor: %s", livro.autor);
    printf("\nAno de publicacao: %d", livro.anoDePublicacao);
    printf("\nISBN: %s", livro.codigoIsbn);
    printf("\nID: %d", livro.id);
    printf("\nEmprestado: %c", livro.estaEmprestado);
    printf("\nAtivo no sistema: %c", livro.estaAtivoNoSistema);
    printf("\n**************************************\n");
    printf("**************************************\n\n");
    system("PAUSE");
}

void editarLivro(struct Livro livro)
{
    struct Livro livroEditado;

    printf("1 - Titulo:");
    scanf(" %[^\n]s\n", livroEditado.titulo);
    printf("2 - Autor:");
    scanf(" %[^\n]s\n", livroEditado.autor);
    printf("3 - ISBN:");
    scanf(" %[^\n]s\n", livroEditado.codigoIsbn);
    printf("4 - Ano de publicacao:");
    scanf("%d", &livroEditado.anoDePublicacao);

    strcpy(livro.titulo, livroEditado.titulo);
    strcpy(livro.autor, livroEditado.autor);
    strcpy(livro.codigoIsbn, livroEditado.codigoIsbn);
    livro.anoDePublicacao = livroEditado.anoDePublicacao;

    printf("Edicao concluida com sucesso!\n");
    printaLivroNaTela(livro);
}

void menuParaLivroEncontrado(struct Livro livro)
{
    int selecaoMenu;
    do
    {
        printf("\nDigite o numero correspondente a opcao desejada:");
        printf("\n1 - Emprestar livro.");
        printf("\n2 - Devolver livro.");
        printf("\n3 - Editar informacoes do livro.");
        printf("\n4 - Ativar livro no sistema.");
        printf("\n5 - Desativar livro no sistema.");
        printf("\n0 - Retornar ao menu anterior.\n");

        scanf("%d", &selecaoMenu);

        switch (selecaoMenu)
        {
        case 1:
            livro.estaEmprestado = 's'; 
            printaLivroNaTela(livro);
            break;
        case 2:
            livro.estaEmprestado = 'n'; 
            printaLivroNaTela(livro);
            break;
        case 3:
            editarLivro(livro);
            printaLivroNaTela(livro);
            break;
        case 4:
            livro.estaAtivoNoSistema = 's';
            printaLivroNaTela(livro);
            break;
        case 5:
            livro.estaAtivoNoSistema = 'n';
            printaLivroNaTela(livro);
            break;
        default:
            break;
        }
    } while (selecaoMenu != 0);
    return;
}

void buscaLivroPorId()
{
    int codigo = 0;
    printf("Insira o id:");
    scanf("%d", &codigo);
    for (int i = 0; i < quantidadeAtualEstoque; i++)
    {
        if (codigo == estoqueLivros[i].id)
        {
            printaLivroNaTela(estoqueLivros[i]);
            menuParaLivroEncontrado(estoqueLivros[i]);
            return;
        }
    }
    printf("=== Livro nao encontrado. ===");
    return;
}

void cadastrarLivro()
{
    if (quantidadeAtualEstoque == totalDeLivros)
    {
        printf("\nQuantidade maxima de livros no estoque atingida.");
        printf("\nPressione qualquer tecla para continuar.");
        system("PAUSE");
        return;
    }

    struct Livro novoLivro;

    printf("Por favor, insira os dados solicitados abaixo.\n\n");
    printf("\nTitulo do livro:");
    scanf(" %[^\n]s", novoLivro.titulo);

    printf("\nNome do autor:");
    scanf(" %[^\n]s", novoLivro.autor);

    printf("\nAno de publicacao:");
    scanf("%d", &novoLivro.anoDePublicacao);

    printf("\nISBN:");
    scanf(" %[^\n]s", novoLivro.codigoIsbn);

    novoLivro.id = quantidadeAtualEstoque;
    novoLivro.estaEmprestado = 'n';
    novoLivro.estaAtivoNoSistema = 's';

    estoqueLivros[quantidadeAtualEstoque] = novoLivro;
    quantidadeAtualEstoque++;
    printf("\n**** LIVRO SALVO COM SUCESSO ****");
    printaLivroNaTela(novoLivro);

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
        printf("2 - Buscar livro.\n");
        printf("0 - Retornar ao menu inicial.\n");
        scanf("%d", &selecao);
        switch (selecao)
        {
        case 1:
            cadastrarLivro();
            break;
        case 2:
            menuBuscaLivro();
            break;
        default:
            break;
        }
    } while (selecao != 0);
}

void printaUsuarioNaTela(int indice)
{
    printf("\n**************************************\n");
    printf("**************************************");
    printf("\nNome do usuario:");
    printf("%s", nomeUsuario[indice]);
    printf("\nEndereco:");
    printf("%s", enderecoUsuario[indice]);
    printf("\nId:");
    printf("%d\n", idUsuario[indice]);
    printf("\n**************************************\n");
    printf("**************************************");
    system("PAUSE");
}

void cadastrarUsuario()
{

    if (quantidadeUsuariosAtuais >= MAX_USUARIOS)
    {
        printf("Numero m%cximo de usuarios atingido.", 133);
        return;
    }

    printf("\nInsira os dados solicitados abaixo.");
    printf("\nNome completo:");
    scanf(" %[^\n]s", nomeUsuario[quantidadeUsuariosAtuais]);
    printf("\nEndereco completo:");
    scanf(" %[^\n]s", enderecoUsuario[quantidadeUsuariosAtuais]);
    idUsuario[quantidadeUsuariosAtuais] = quantidadeUsuariosAtuais + 1;
    printf("\n**** USUARIO SALVO COM SUCESSO ****");
    printaUsuarioNaTela(quantidadeUsuariosAtuais);
    quantidadeUsuariosAtuais++;
}

void buscarUsuario()
{
    int codigo = 0;
    printf("Insira o id:");
    scanf("%d", &codigo);
    for (int i = 0; i < quantidadeUsuariosAtuais; i++)
    {
        if (codigo == idUsuario[i])
        {
            codigo--;
            printaUsuarioNaTela(codigo);
            return;
        }
    }
    printf("Usuario nao encontrado");
    return;
}

void editarUsuario()
{
    int id = 0;
    printf("Digite o id de usuario:");
    scanf("%d", &id);
    for (int i = 0; i < quantidadeUsuariosAtuais; i++)
    {
        if (idUsuario[i] == id)
        {
            char novoEndereco[TAMANHO_ENDERECO];
            printf("Digite o novo endereco: ");
            scanf(" %[^\n]s", novoEndereco);
            strcpy(enderecoUsuario[i], novoEndereco);
            printf("\nEndereco alterado com sucesso.");
            return;
        }
    }
    printf("Id de usuario nao encontrado.");
    return;
}

void sessaoUsuarios()
{
    int selecao = 0;
    printf("\n******** Sessao usuarios ********");
    do
    {
        printf("\nDigite a opcao desejada:\n");
        printf("1 - Cadastrar usuario.\n");
        printf("2 - Buscar usuario.\n");
        printf("3 - Editar usuario.\n");
        printf("0 - Retornar ao menu inicial.\n");
        scanf("%d", &selecao);
        switch (selecao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            buscarUsuario();
            break;
        case 3:
            editarUsuario();
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
        sessaoUsuarios();
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