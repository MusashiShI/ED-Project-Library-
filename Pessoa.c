

#include "Pessoa.h"

/** \brief Permite Alocar e inicializar uma estrutura Pessoa
 *
 * \param _id int
 * \param _nome char*
 * \param _categoria char*
 * \return PESSOA*
 *
 */
PESSOA *CriarPessoa(char *_id, char *_nome, char *_datan, char *_idfreg)
{
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    P->nome = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(P->nome, _nome);
    P->datan = (char *)malloc((strlen(_datan) + 1)*sizeof(char));
    strcpy(P->datan, _datan);
    P->ID = (char *)malloc((strlen(_id) + 1)*sizeof(char));
    strcpy(P->ID, _id);
    P->idfreg = (char *)malloc((strlen(_idfreg) + 1)*sizeof(char));
    strcpy(P->idfreg, _idfreg);

    return P;
}
void MostrarPessoa(PESSOA *P)
{
    printf("\tID: [%s] | PESSOA: [%s] | DATA DE NASCIMENTO: [%s] | ID Freguesia: [%s]\n", P->ID, P->nome, P->datan, P->idfreg);
}
void DestruirPessoa(PESSOA *P)
{
    free (P->ID);
    free (P->nome);
    free (P->datan);
    free (P->idfreg);
    free (P);
}
