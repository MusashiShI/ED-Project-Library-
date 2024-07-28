
#include "ListaR.h"



//--------------------------------------------------
/** \brief Permite alocar mem�ria para uma LISTAL
 *
 * \return LISTAL* : Retorna a LISTAL alocada
 * \date 10/04/2024
 * \author Docentes de ED
 */
LISTARR *CriarListaR()
{
    LISTARR *R = (LISTARR *)malloc(sizeof(LISTARR));
    R->NEL = 0;
    R->Inicio = NULL;
    return R;
}

//--------------------------------------------------
void AddInicioR(LISTARR *R, REQUISITANTE *X)
{
    if (!R) return;
    NOR *aux = (NOR *)malloc(sizeof(NOR));
    aux->Info = X;
    aux->Prox = R->Inicio;
    R->Inicio = aux;
    R->NEL++;
}

//--------------------------------------------------
void ShowListaR(LISTARR *R)
{
    if (!R) return;
    //printf("NEL = %d\n", L->NEL);
    NOR *P = R->Inicio;
    while (P != NULL)
    {
        MostrarRequisitante(P->Info);
        P = P->Prox;
    }
}

//--------------------------------------------------
void DestruirListaR(LISTARR *R)
{
    //printf("Implementar <%s>\n", __func__);
    if (!R) return;
    NOR *Martim;
    NOR *Helder = R->Inicio;
    while (Helder)
    {
        Martim = Helder->Prox;
        DestruirPessoa(Helder->Info);
        free (Helder);
        Helder = Martim;
    }
    free(R);
}

//--------------------------------------------------
//--------------------------------------------------
int SizeListaR(LISTARR *R)
{
    if (!R) return -1;
    return R->NEL;
}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
