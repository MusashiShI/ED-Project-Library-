
#include "ListaP.h"


//--------------------------------------------------
/** \brief Permite alocar mem�ria para uma LISTAL
 *
 * \return LISTAL* : Retorna a LISTAL alocada
 * \date 10/04/2024
 * \author Docentes de ED
 */
LISTAP *CriarListaP()
{
    LISTAP *P = (LISTAP *)malloc(sizeof(LISTAP));
    P->NEL = 0;
    P->Inicio = NULL;
    return P;
}

//--------------------------------------------------
void AddInicioP(LISTAP *P, PESSOA *X)
{
    if (!P) return;
    NOp *aux = (NOp *)malloc(sizeof(NOp));
    aux->Info = X;
    aux->Prox = P->Inicio;
    P->Inicio = aux;
    P->NEL++;
}

//--------------------------------------------------
void ShowListaP(LISTAP *Pe)
{
    if (!Pe) return;
    //printf("NEL = %d\n", L->NEL);
    NOp *P = Pe->Inicio;
    while (P != NULL)
    {
        MostrarPessoa(P->Info);
        P = P->Prox;
    }
}

//--------------------------------------------------
void DestruirListaP(LISTAP *P)
{
    //printf("Implementar <%s>\n", __func__);
    if (!P) return;
    NOp *Martim;
    NOp *Helder = P->Inicio;
    while (Helder)
    {
        Martim = Helder->Prox;
        DestruirPessoa(Helder->Info);
        free (Helder);
        Helder = Martim;
    }
    free(P);
}

//--------------------------------------------------
//--------------------------------------------------
int SizeListaP(LISTAP *p)
{
    if (!p) return -1;
    return p->NEL;
}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
