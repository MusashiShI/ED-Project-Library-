#ifndef HASHINGP_H_INCLUDED
#define HASHINGP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaP.h"

typedef struct no_chavep
{
    char *KEY; // Assim nao temos tamanho fixo!, Bem melhor!, mas depois ser� necess�rio fazer o free!
    LISTAP *DADOS;
    struct no_chavep *Prox;
}NO_CHAVEp;

typedef struct
{
    int NEL;
    NO_CHAVEp *Inicio;
}LISTA_CHAVESp;

typedef struct
{
    LISTA_CHAVESp *PChaves;
}HASHINGP;
//--------------------------------------------------------
//--------------------------------------------------------

//--------------------------------------------------------
HASHINGP *CriarHashingp();
//--------------------------------------------------------
void DestruirHashingp(HASHINGP *H);
//--------------------------------------------------------
void AddHashingp(HASHINGP *H, PESSOA *P);
//--------------------------------------------------------
void ShowHashingp(HASHINGP *H);
//--------------------------------------------------------
NO_CHAVEp *FuncaoHashingp(HASHINGP *H, PESSOA *X);
//--------------------------------------------------------
//--------------------------------------------------------
//--------------------------------------------------------



#endif // HASHINGP_H_INCLUDED
