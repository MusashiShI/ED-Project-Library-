#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaL.h"
#include "ListaP.h"
#include "HashingL.h"
#include "HashingP.h"
#include "Biblioteca.h"
#include "Texto.h"


//----------------------------------------------------------------------------------------------------
int Menu()
{
    printf("\n");
    printf(" ---------------------------\n");
    printf("|        MENU GERAL         |\n");
    printf(" ---------------------------\n");
    printf("| 1- Administracao          |\n");
    printf("| 2- Cliente                |\n");
    printf("| 3- Biblioteca             |\n");
    printf("| 4- Livros                 |\n");
    printf("| 0- Sair                   |\n");
    printf(" ---------------------------\n");
    int op = 0;
    printf("Qual a opcao? ");
    scanf("%d", &op);
    return op;
}
//----------------------------------------------------------------------------------------------------
int MenuAdm()
{
    printf("\n");
    printf("   ---------------------------    \n");
    printf("  |       ADMINISTRACAO       |   \n");
    printf("   ---------------------------    \n");
    printf("| 1- Listar Livros               |\n");
    printf("| 2- Adicionar Livro             |\n");
    printf("| 3- Categoria com Mais Livros   |\n");
    printf("| 4- Listar Livros Requesitados  |\n");
    printf("| 5- Listar Clientes             |\n");
    printf("| 6- Pesquisar Clientes          |\n");
    printf("| 7- Adicionar Pessoa            |\n");
    printf("| 8- Mostrar Biblioteca          |\n");
    printf("| 9- Verificar Memoria           |\n");
    printf("| 10- Destruir Biblioteca        |\n");
    printf("| 0- Sair                        |\n");
    printf(" --------------------------------\n");

    int opadm = 0;
    printf("Qual a opcao? ");
    scanf("%d", &opadm);
    return opadm;
}
//----------------------------------------------------------------------------------------------------
int Menuclient()
{
    printf("\n");
    printf(" -------------------------------\n");
    printf("|             CLIENTE           |\n");
    printf(" -------------------------------\n");
    printf("| 1- Requesitar Livro           |\n");
    printf("| 2- Devolver Livro             |\n"); //NAO FEITA
    printf("| 3- Pesquisar Livro            |\n");
    printf("| 4- Listar Livros              |\n");
    printf("| 5- Listar Livros Requesitados |\n");
    printf("| 0- Sair                       |\n");
    printf(" -------------------------------\n");

    int opclient = 0;
    printf("Qual a opcao? ");
    scanf("%d", &opclient);
    return opclient;
}
//----------------------------------------------------------------------------------------------------
int MenuBiblio()
{
    printf("\n");
    printf("      ---------------------------            \n");
    printf("     |          BIBLIOTECA       |           \n");
    printf("      ---------------------------            \n");
    printf("| 1- Adicionar livro                         |\n");
    printf("| 2- Remover livro                           |\n");
    printf("| 3- Listar livros                           |\n");
    printf("| 4- Determinar area com mais livros         |\n");
    printf("| 5- Verificar existência de um livro        |\n");
    printf("| 6- Listar Livros Requesitados              |\n");
    printf("| 7- Livro mais recente                      |\n"); // FACIL
    printf("| 8- Pessoas com Livros Requesitados         |\n");
    printf("| 9- Media da idade das Pessoas              |\n");
    printf("| 0- Sair                                    |\n");
    printf(" --------------------------------------------\n");
    int opBiblio = 0;
    printf("Qual a opcao? ");
    scanf("%d", &opBiblio);
    return opBiblio;
}
//----------------------------------------------------------------------------------------------------
int MenuLivro()
{
    printf("\n");
    printf("     ---------------------------       \n");
    printf("    |           LIVRO           |      \n");
    printf("     ---------------------------       \n");
    printf("| 1- Pesquisar Livro                   |\n");
    printf("| 2- Registrar Livro                   |\n");
    printf("| 3- Verificar Existência de Livro     |\n");
    printf("| 0- Sair                              |\n");
    printf(" --------------------------------------\n");
    int opLivro = 0;
    printf("Qual a opcao? ");
    scanf("%d", &opLivro);
    return opLivro;
}
//----------------------------------------------------------------------------------------------------






int main()
{

    printf("Projeto-Biblioteca-Versão-Base!\n");


     BIBLIOTECA *Bib;
     Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
     LoadFicheiroBiblioteca(Bib);
     LoadFicheiroBibliotecaPessoas(Bib);


    int OP, OPB, OPL, OPA, OPC;
    char isbnProcurado[100];
    char _idproc[100];

    char idPessoa[100], isbnLivro[100];

    do
    {
        system("cls");
        OP = Menu();
        switch (OP)
        {
            case 1:
                system("cls");
                do
                {
                    OPA = MenuAdm();
                    switch (OPA)
                    {
                        case 1:
                            ShowLBiblioteca(Bib);
                            break;
                        case 2:
                            AddLivroBiblioteca(Bib);
                            break;
                        case 3:
                            CategoriaMaisLivros(Bib->HLivros);
                            break;
                        case 4:
                            printf("\nLista de requisitantes:");
                            ShowListaR(Bib->Req);
                            break;
                        case 5:
                            ShowPBiblioteca(Bib);
                            break;
                        case 6:
                                printf("\nColoque o ID da Pessoa que deseja pesquisar: ");
                                limparBuffer();
                                fgets(_idproc, sizeof(_idproc), stdin);
                                _idproc[strcspn(_idproc, "\n")] = '\0'; // Remove o newline no final
                                EncontrarPessoaPorID(Bib, _idproc);
                            break;
                        case 7:
                               AddRequisitante(Bib);
                            break;
                        case 8:
                                ShowBiblioteca(Bib);
                            break;
                        case 9:

                                printf("Tamanho da estrutura BIBLIOTECA: %lu bytes\n", sizeof(BIBLIOTECA));
                                printf("Tamanho da estrutura HASHING: %lu bytes\n", sizeof(HASHING));
                                printf("Tamanho da estrutura HASHINGP: %lu bytes\n", sizeof(HASHINGP));
                                printf("Tamanho da estrutura LISTAL: %lu bytes\n", sizeof(LISTAL));
                                printf("Tamanho da estrutura LISTARR: %lu bytes\n", sizeof(LISTARR));
                                printf("Tamanho da estrutura LIVRO: %lu bytes\n", sizeof(LIVRO));
                                printf("Tamanho da estrutura PESSOA: %lu bytes\n", sizeof(PESSOA));
                                printf("Tamanho da estrutura REQUISITANTE: %lu bytes\n", sizeof(REQUISITANTE));


                            break;
                        case 10:
                            DestruirBiblioteca(Bib);
                            break;
                    }
                } while (OPA != 0);
                break;

            case 2:
                system("cls");
                do
                {
                    OPC = Menuclient();
                    switch (OPC)
                    {
                        case 1:
                                    printf("Digite o ID da pessoa: ");
                                    scanf("%s", idPessoa);

                                    printf("Digite o ISBN do livro: ");
                                    scanf("%s", isbnLivro);


                                    // Buscando a pessoa e o livro
                                    PESSOA *pessoa = EncontrarPessoaPorID(Bib, idPessoa);
                                    LIVRO *livro = EncontrarLivroPorISBN(Bib, isbnLivro);

                                    if (pessoa == NULL) {
                                        printf("Pessoa com ID %s não encontrada.\n", idPessoa);
                                        return -1;
                                    }

                                    if (livro == NULL) {
                                        printf("Livro com ISBN %s não encontrado.\n", isbnLivro);
                                        return -1;
                                    }

                                        REQUISITANTE *requisitante = CriarRequisitante(pessoa, livro);
                                        if (!requisitante) {
                                            printf("Falha ao criar requisitante.\n");
                                        }

                                        // Adicionando o requisitante na lista da biblioteca
                                        AddInicioR(Bib->Req, requisitante);
                                        printf("Requisitante adicionado com sucesso.\n");

                                    printf("\nLista de requisitantes:");
                                    ShowListaR(Bib->Req);

                            break;
                        case 2:
                            // DevolverLivro(BIBLIOTECA *B, PESSOA *X);
                            break;
                        case 3:
                                printf("\nColoque o ISBN do livro que deseja pesquisar: ");
                                limparBuffer();
                                fgets(isbnProcurado, sizeof(isbnProcurado), stdin);
                                isbnProcurado[strcspn(isbnProcurado, "\n")] = '\0';
                                EncontrarLivroPorISBN(Bib, isbnProcurado);
                                limparBuffer();
                            break;
                        case 4:
                            ShowLBiblioteca(Bib);
                            break;
                        case 5:
                                printf("\nLista de requisitantes:");
                                ShowListaR(Bib->Req);
                            break;

                    }
                } while (OPC != 0);
                break;

            case 3:
                system("cls");
                do
                {
                    OPB = MenuBiblio();
                    switch (OPB)
                    {
                        case 1:
                            AddLivroBiblioteca(Bib);
                            break;
                        case 2:
                                printf("\nColoque o ISBN do livro que deseja pesquisar: ");
                                limparBuffer();
                                fgets(isbnProcurado, sizeof(isbnProcurado), stdin);
                                isbnProcurado[strcspn(isbnProcurado, "\n")] = '\0';
                                removerLivroPorISBN(Bib, isbnProcurado);
                                limparBuffer();

                            break;
                        case 3:
                            ShowLBiblioteca(Bib);
                            break;
                        case 4:
                            CategoriaMaisLivros(Bib->HLivros);
                            break;
                        case 5:
                                printf("\nColoque o ISBN do livro que deseja ver se existe: ");
                                limparBuffer();
                                fgets(isbnProcurado, sizeof(isbnProcurado), stdin);
                                isbnProcurado[strcspn(isbnProcurado, "\n")] = '\0'; // Remove o newline no final
                                ExistenciaDoLivroPorISBN(Bib, isbnProcurado);
                                limparBuffer();
                            break;
                        case 6:
                                    printf("\nLista de requisitantes:");
                                    ShowListaR(Bib->Req);
                            break;
                        case 7:
                                LivrosMaisRecentes(Bib->HLivros);
                            break;
                        case 8:
                                    limparBuffer();
                                    printf("Digite o ID da pessoa: ");
                                    scanf("%s", idPessoa);
                                    ExistenciadoRequesitante(Bib,idPessoa);

                            break;
                        case 9:
                            CalcularMediaIdadeRequisitantes(Bib);
                            break;
                    }
                } while (OPB != 0);
                break;

            case 4:
                system("cls");
                do
                {
                    OPL = MenuLivro();
                    switch (OPL)
                    {
                        case 1:
                                printf("\nColoque o ISBN do livro que deseja pesquisar: ");
                                limparBuffer();
                                fgets(isbnProcurado, sizeof(isbnProcurado), stdin);
                                isbnProcurado[strcspn(isbnProcurado, "\n")] = '\0'; // Remove o newline no final
                                EncontrarLivroPorISBN(Bib, isbnProcurado);
                                limparBuffer();


                        break;


                        case 2:
                            AddLivroBiblioteca(Bib);
                        break;
                        case 3:
                                printf("\nColoque o ISBN do livro que deseja ver se existe: ");
                                limparBuffer();
                                fgets(isbnProcurado, sizeof(isbnProcurado), stdin);
                                isbnProcurado[strcspn(isbnProcurado, "\n")] = '\0'; // Remove o newline no final
                                ExistenciaDoLivroPorISBN(Bib, isbnProcurado);
                                limparBuffer();
                        break;

                    }
                } while (OPL != 0);
                break;

            default:
                if (OP != 0)
                    printf("opcao não implementada\n");
                break;
        }
    } while (OP != 0);

    // DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
