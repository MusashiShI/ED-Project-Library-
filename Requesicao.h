#ifndef REQUISICAO_H_INCLUDED
#define REQUISICAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pessoa.h"
#include "Livro.h"
typedef struct
{
    PESSOA *Ptr_Req;
    LIVRO *Ptr_Livro;
} REQUISITANTE;

REQUISITANTE *CriarRequisitante(PESSOA *P, LIVRO *L);
void MostrarRequisitante(REQUISITANTE *P);
void DestruirRequisitante(REQUISITANTE *P);


#endif // REQUISICAO_H_INCLUDED
