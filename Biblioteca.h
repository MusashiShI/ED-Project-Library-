#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Livro.h"
#include "Lista.h"
#include "Hashing.h"
typedef struct
{
    char *NOME;
    char FICHEIRO_LOGS[50];
    LIVRO *livros;

    //  HASHING *HLivros;
   // LISTA   *LRequisitantes;
   // LISTA_Requisicoes *LRequisicoes;
}BIBLIOTECA;

//adicionar uma quantidade de clientes e detalhes dos mesmos para poderem ser listados.


BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs);
void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);
int AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L);
int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
int ListarLivrosDaBiblioteca(BIBLIOTECA *B);
LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B);
char *ApelidoMaisComum(BIBLIOTECA *B);
char *AreaMaisComum(BIBLIOTECA *B);
int AddRequisitante(BIBLIOTECA *B, PESSOA *X);
int RequeitarLivro(BIBLIOTECA *B, PESSOA *X);
int DevolverLivro(BIBLIOTECA *B, PESSOA *X);
PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod);
int ListarLivrosRequesitados(BIBLIOTECA *B);
int ListarClientes(BIBLIOTECA *B);
int ListarRequesitantes(BIBLIOTECA *B);
#endif // BIBLIOTECA_H_INCLUDED
