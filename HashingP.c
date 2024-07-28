
#include "HashingP.h"


LISTA_CHAVESp *CriarListaCHAVESp()
{
    LISTA_CHAVESp *P = (LISTA_CHAVESp *)malloc(sizeof(LISTA_CHAVESp));
    P->NEL = 0;
    P->Inicio = NULL;
    return P;
}

//--------------------------------------------------
NO_CHAVEp *AddCHAVEp(LISTA_CHAVESp *L, char *key)
{
    if (!L) return NULL;
    NO_CHAVEp *aux = (NO_CHAVEp *)malloc(sizeof(NO_CHAVEp));
    aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(aux->KEY, key);
    aux->DADOS = CriarListaP();
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
    return aux;
}
HASHINGP *CriarHashingp()
{
    HASHINGP *H = (HASHINGP *)malloc(sizeof(HASHINGP));
    H->PChaves = CriarListaP();
    return H;
}
void DestruirHashingp(HASHINGP *H)
{
    if (!H) return;
    NO_CHAVEp *Seguinte;
    NO_CHAVEp *P = H->PChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirListaP(P->DADOS);
        free (P->KEY);
        free (P);
        P = Seguinte;
    }
    free(H);
}
void AddHashingp(HASHINGP *H, PESSOA *P)
{
    if (!H) return;
    if (!H->PChaves) return;
    NO_CHAVEp *Key_colocar = FuncaoHashingp(H, P);
    if (!Key_colocar)
    {
        Key_colocar = AddCHAVEp(H->PChaves, P->idfreg);
    }
    AddInicioP(Key_colocar->DADOS, P);
}

void ShowHashingp(HASHINGP *H)
{
    if (!H) return;
    if (!H->PChaves) return;
    NO_CHAVEp *P = H->PChaves->Inicio;
    while (P)
    {
        printf("Key: [%s]\n", P->KEY);
        ShowListaP(P->DADOS);
        P = P->Prox;
    }
}
NO_CHAVEp *FuncaoHashingp(HASHINGP *H, PESSOA *X)
{
    if (!H) return NULL;
    if (!H->PChaves) return NULL;

    NO_CHAVEp *P = H->PChaves->Inicio;
    while (P)
    {
        if (stricmp(P->KEY, X->idfreg) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}
