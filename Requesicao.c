#include "Requesicao.h"

REQUISITANTE *CriarRequisitante(PESSOA *P, LIVRO *L) {
    REQUISITANTE *R = (REQUISITANTE *)malloc(sizeof(REQUISITANTE));
    if (!R) return NULL;
    R->Ptr_Req = P;
    R->Ptr_Livro = L;
    return R;
}

void MostrarRequisitante(REQUISITANTE *R) {
    if (!R) return;
    printf("\n");
    printf("---------------------------------------------------------------------");
    printf("\nRequisitante: %s\n", R->Ptr_Req->nome);
    printf("Livro: %s\n", R->Ptr_Livro->titulo);
    printf("---------------------------------------------------------------------");
}

void DestruirRequisitante(REQUISITANTE *R) {
    if (R) free(R);
}
