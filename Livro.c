
#include "Livro.h"


LIVRO *CriarLivro(char *_isbn, char *_autor, char *_titulo, char *_area, int _id, int _ano, int _mes, int _dia)
{

    LIVRO *L = (LIVRO *)malloc(sizeof(LIVRO));
    L->isbn = (char *)malloc((strlen(_isbn) + 1)*sizeof(char));
    strcpy(L->isbn, _isbn);

    L->Autor = (char *)malloc((strlen(_autor) + 1)*sizeof(char));
    strcpy(L->Autor, _autor);

    L->titulo = (char *)malloc((strlen(_titulo) + 1)*sizeof(char));
    strcpy(L->titulo, _titulo);

    L->AREA = (char *)malloc((strlen(_area) + 1)*sizeof(char));
    strcpy(L->AREA, _area);

    L->ID = _id;

    L->data.ano = _ano;
    L->data.mes = _mes;
    L->data.dia = _dia;

    return L;
}

void MostrarLivro(LIVRO *L)
{
    printf("\t ISBN: [%s] | AUTOR: [%s] | TITULO: [%s] | AREA: [%s] | ID: %d | DATA %d/%d/%d  \n", L->isbn, L->Autor, L->titulo, L->AREA, L->ID, L->data.dia, L->data.mes, L->data.ano);
}


void DestruirLivro(LIVRO *L)
{
    free (L->isbn);
    free (L->Autor);
    free (L->titulo);
    free (L->AREA);
    free (L);
}

