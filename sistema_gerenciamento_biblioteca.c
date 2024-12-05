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

void seedLivros()
{
    struct Livro livros[5] = {
        {"O Senhor dos Aneis", "J.R.R. Tolkien", "1234567890123", 'n', 's', 1954, 1, 0},
        {"1984", "George Orwell", "2345678901234", 'n', 's', 1949, 2, 0},
        {"Dom Casmurro", "Machado de Assis", "3456789012345", 'n', 's', 1899, 3, 0},
        {"Orgulho e Preconceito", "Jane Austen", "4567890123456", 'n', 's', 1813, 4, 0},
        {"O Pequeno Principe", "Antoine de Saint-Exupéry", "5678901234567", 'n', 's', 1943, 5, 0}};

    for (int i = 0; i < 5; i++)
    {
        estoqueLivros[quantidadeLivrosEstoque] = livros[i];
        quantidadeLivrosEstoque++;
    }

    printf("\n5 livros adicionados com sucesso!\n");
}

void seedUsuarios()
{
    const char nomes[5][TAMANHO_NOME] = {
        "Joao Silva",
        "Maria Oliveira",
        "Carlos Souza",
        "Ana Pereira",
        "Beatriz Santos"};
    const char enderecos[5][TAMANHO_ENDERECO] = {
        "Rua das Flores, 123",
        "Avenida Paulista, 456",
        "Praca da Liberdade, 789",
        "Rua dos Bobos, 0",
        "Estrada do Campo, 321"};

    for (int i = 0; i < 5; i++)
    {
        strcpy(nomeUsuario[quantidadeUsuariosAtuais], nomes[i]);
        strcpy(enderecoUsuario[quantidadeUsuariosAtuais], enderecos[i]);
        idUsuario[quantidadeUsuariosAtuais] = quantidadeUsuariosAtuais + 1;
        quantidadeUsuariosAtuais++;
    }

    printf("\n5 usuarios adicionados com sucesso!\n");
}

void printaLivroNaTela(struct Livro *livro)
{
    printf("\n**************************************\n");
    printf("**************************************");
    printf("\n*Titulo: %s", livro->titulo);
    printf("\n*Autor: %s", livro->autor);
    printf("\n*Ano de publicacao: %d", livro->anoDePublicacao);
    printf("\n*ISBN: %s", livro->codigoIsbn);
    printf("\n*ID: %d", livro->id);
    printf("\n*Ativo no sistema: %c", livro->estaAtivoNoSistema);
    if (livro->estaEmprestado == 's')
    {
        printf("\n*Esta em posse de usuario id: %d", livro->emPosseDeUsuarioId);
    }
    else
    {
        if (livro->estaAtivoNoSistema == 'n')
        {
            printf("\n*Livro inativo no sistema.");
        }
        else
        {
            printf("\n*Situacao: disponivel para emprestimo");
        }
    }
    printf("\n**************************************\n");
    printf("**************************************\n\n");
    system("PAUSE");
}

void printaUsuarioNaTela(int indice)
{
    printf("\n**************************************\n");
    printf("**************************************");
    printf("\n*Nome do usuario: %s", nomeUsuario[indice]);
    printf("\nEndereco: %s", enderecoUsuario[indice]);
    printf("\nId: %d", idUsuario[indice]);
    printf("\n**************************************\n");
    printf("**************************************\n");
    system("PAUSE");
}

void editarLivro(struct Livro *livro)
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

    strcpy(livro->titulo, livroEditado.titulo);
    strcpy(livro->autor, livroEditado.autor);
    strcpy(livro->codigoIsbn, livroEditado.codigoIsbn);
    livro->anoDePublicacao = livroEditado.anoDePublicacao;

    printf("\n=== Edicao concluida com sucesso! ===\n");
    printaLivroNaTela(livro);
}

void emprestarLivro(struct Livro *livro)
{
    if (livro->estaAtivoNoSistema == 'n')
    {
        printf("\n=== Livro inativo no sistema, impossivel realizar emprestimo ===.");
        system("PAUSE");
        return;
    }

    int id;
    printf("\nDigite o id do usuario para quem o livro sera emprestado:");
    scanf("%d", &id);
    for (int i = 0; i < quantidadeUsuariosAtuais; i++)
    {
        if (id == idUsuario[i])
        {
            printaUsuarioNaTela(i);
            int confirmacao;
            printf("O usuario esta correto? Digite 1 para sim; 2 para nao:\n");
            scanf("%d", &confirmacao);
            if (confirmacao == 2)
            {
                printf("=== Emprestimo cancelado ===.");
                system("PAUSE");
                return;
            }
            printf("\n=== Emprestimo registrado com sucesso ===.");
            printf("\nTitulo do livro: %s", livro->titulo);
            printf("\nEmprestado para usuario: %s\n", nomeUsuario[i]);
            livro->estaEmprestado = 's';
            livro->emPosseDeUsuarioId = id;
            system("PAUSE");
            return;
        }
    }
    printf("Usuario nao encontrado\n");
    system("PAUSE");
    return;
}

void devolverLivro(struct Livro *livro)
{
    livro->estaEmprestado = 'n';
    livro->emPosseDeUsuarioId = 0;
    printf("\n=== Devolucao do livro de id %d registrada com sucesso! ===", livro->id);
    return;
}

void ativarLivro(struct Livro *livro)
{
    livro->estaAtivoNoSistema = 's';
    printf("\n=== Livro ativado com sucesso ===.");
    printaLivroNaTela(livro);
    system("PAUSE");
    return;
}

void desativarLivro(struct Livro *livro)
{
    if (livro->estaEmprestado == 's')
    {
        printf("\n=== O livro esta emprestado, impossivel desativa-lo no momento. ===");
        return;
    }
    livro->estaAtivoNoSistema = 'n';
    printf("\n=== Livro desativado com sucesso ===.");
    printaLivroNaTela(livro);
    system("PAUSE");
    return;
}

void menuParaLivroEncontrado(struct Livro *livro)
{
    int selecaoMenu;
    do
    {
        printf("\nDigite o numero correspondente a opcao desejada:");
        livro->estaEmprestado == 's' ? printf("\n1 - Devolver livro") : printf("\n1 - Emprestar livro.");
        livro->estaAtivoNoSistema == 's' ? printf("\n2 - Desativar livro.") : printf("\n2 - Ativar livro.");
        printf("\n3 - Editar informacoes do livro.");
        printf("\n0 - Retornar ao menu anterior.\n");

        scanf("%d", &selecaoMenu);

        switch (selecaoMenu)
        {
        case 1:
            livro->estaEmprestado == 's' ? devolverLivro(livro) : emprestarLivro(livro);
            break;
        case 2:
            livro->estaAtivoNoSistema == 's' ? desativarLivro(livro) : ativarLivro(livro);
            break;
        case 3:
            editarLivro(livro);
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
    for (int i = 0; i < quantidadeLivrosEstoque; i++)
    {
        if (codigo == estoqueLivros[i].id)
        {
            struct Livro *plivro = &estoqueLivros[i];
            printaLivroNaTela(plivro);
            menuParaLivroEncontrado(plivro);
            return;
        }
    }
    printf("=== Livro nao encontrado. ===");
    return;
}

void cadastrarLivro()
{
    if (quantidadeLivrosEstoque == totalDeLivros)
    {
        printf("\n=== Quantidade maxima de livros no estoque atingida. ===");
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

    novoLivro.id = quantidadeLivrosEstoque + 1;
    novoLivro.estaEmprestado = 'n';
    novoLivro.estaAtivoNoSistema = 's';

    estoqueLivros[quantidadeLivrosEstoque] = novoLivro;
    struct Livro *plivro = &estoqueLivros[quantidadeLivrosEstoque];
    quantidadeLivrosEstoque++;
    printf("\n=== LIVRO SALVO COM SUCESSO. ===");
    printaLivroNaTela(plivro);

    return;
}

void sessaoLivros()
{
    int selecao = 0;
    printf("\n=== Sessao livros ===");
    do
    {
        printf("\nDigite a opcao desejada:\n");
        printf("1 - Cadastrar livro.\n");
        printf("2 - Buscar livro por ID.\n");
        printf("0 - Retornar ao menu inicial.\n");
        scanf("%d", &selecao);
        switch (selecao)
        {
        case 1:
            cadastrarLivro();
            break;
        case 2:
            buscaLivroPorId();
            break;
        default:
            break;
        }
    } while (selecao != 0);
}

void cadastrarUsuario()
{

    if (quantidadeUsuariosAtuais >= MAX_USUARIOS)
    {
        printf("=== Numero m%cximo de usuarios atingido. ===", 133);
        return;
    }

    printf("\nInsira os dados solicitados abaixo.");
    printf("\nNome completo:");
    scanf(" %[^\n]s", nomeUsuario[quantidadeUsuariosAtuais]);
    printf("\nEndereco completo:");
    scanf(" %[^\n]s", enderecoUsuario[quantidadeUsuariosAtuais]);
    idUsuario[quantidadeUsuariosAtuais] = quantidadeUsuariosAtuais + 1;
    printf("\n=== USUARIO SALVO COM SUCESSO. ===");
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
    printf("=== Usuario nao encontrado. ===");
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
            printf("\n=== Endereco alterado com sucesso. ===");
            return;
        }
    }
    printf("=== Usuario nao encontrado. ===");
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
    default:
        break;
    }
    return 0;
}

int main()
{
    seedLivros();
    seedUsuarios();
    int opcaoSelecionada = 0;

    printf("\nSeja bem vindo ao BiblioHub, seu sistema de gerenciamento de biblioteca.\n");
    do
    {
        printf("\n=== Digite o numero correspondente a opcao desejada: ===\n");
        printf("1 - Usuarios.\n");
        printf("2 - Livros.\n");
        printf("0 - Encerrar programa.\n");
        scanf("%d", &opcaoSelecionada);
        direcionamentoMenuInicial(opcaoSelecionada);
    } while (opcaoSelecionada != 0);
    printf("\nEncerando programa...");
    system("PAUSE");
    return 0;
}