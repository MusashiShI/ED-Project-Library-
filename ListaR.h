#ifndef LISTAR_H_INCLUDED
#define LISTAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Requesicao.h"

typedef struct nor
{
    REQUISITANTE *Info;
    struct nor *Prox;
}NOR;

typedef struct
{
    int NEL;
    NOR *Inicio;
}LISTARR;

LISTARR *CriarListaR();
//--------------------------------------------------
void AddInicioR(LISTARR *R, REQUISITANTE *X);
//--------------------------------------------------
void ShowListaR(LISTARR *R);
//--------------------------------------------------
void DestruirListaR(LISTARR *R);
//--------------------------------------------------
//--------------------------------------------------
int SizeListaR(LISTARR *R);
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

#endif // LISTAR_H_INCLUDED
