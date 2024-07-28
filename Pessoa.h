#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *ID;
    char *nome;
    char *datan;
    char *idfreg;
}PESSOA;

PESSOA *CriarPessoa(char *_id, char *_nome, char *_datan, char *_idfreg);
void MostrarPessoa(PESSOA *P);
void DestruirPessoa(PESSOA *P);

#endif // PESSOA_H_INCLUDED
