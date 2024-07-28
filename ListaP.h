#ifndef LISTAP_H_INCLUDED
#define LISTAP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"

typedef struct nop
{
    PESSOA *Info;
    struct nop *Prox;
}NOp;

typedef struct
{
    int NEL;
    NOp *Inicio;
}LISTAP;

LISTAP *CriarListaP();
//--------------------------------------------------
void AddInicioP(LISTAP *P, PESSOA *X);
//--------------------------------------------------
void ShowListaP(LISTAP *P);
//--------------------------------------------------
void DestruirListaP(LISTAP *P);
//--------------------------------------------------
//--------------------------------------------------
int SizeListaP(LISTAP *P);
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

#endif // LISTAP_H_INCLUDED
