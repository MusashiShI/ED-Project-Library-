

#include "Biblioteca.h"

/** \brief Aloca Memoria para uma Biblioteca
 *
 * \param _nome char* : Nome da Biblioteca
 * \param _logs char* : Ficheiro dos Logs
 * \return BIBLIOTECA* : Retorna o ponteiro para a biblioteca
 * \author Docentes & Alunos
 * \date   11/04/2024
 *
 */
BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs)
{
    BIBLIOTECA *Bib = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    Bib->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(Bib->NOME, _nome);
    strcpy(Bib->FICHEIRO_LOGS, _logs);
    Bib->HLivros = CriarHashing();
    //Bib->LRequisicoes = CriarListaRequisicoes();
    //Bib->LRequisitantes = CriarListaPessoas();
    return Bib;
}
//------------------------------------------------------------------------------
/** \brief Funcao para Mostrar toda a Biblioteca
 *
 * \param B BIBLIOTECA* : Pnteiro para a Biblioteca
 * \return void
 * \author : Docentes e Alunos
 * \date   : 11/04/2024
 */
void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);

    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
//------------------------------------------------------------------------------
void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Vosso Codigo.....
    free (B->NOME);
    //------
    free(B);

    fclose(F_Logs);
}
//------------------------------------------------------------------------------
int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{

   printf("Entrei na Fun��o %s", __func__);
    FILE *F = fopen("livros.txt","r"); // FILE *F = fopen(ficheiro,"r");
    if(!F) return 0;

    char BUFFER[1001];
    while(!feof(F))
    {

        fgets(BUFFER, 1000, F);
       // printf("Linha [%s] \n",BUFFER);
        int i = 0;
        char *CAMPOS[8];
        char *token = strtok (BUFFER, "\t\n"); //Separa a string pelo '\t'
        while (token != NULL)
        {

            CAMPOS[i] = token;
            token = strtok (NULL, "\t\n");
            i++;
        }

        LIVRO *L = CriarLivro(CAMPOS[0], CAMPOS[1], CAMPOS[2], CAMPOS[3], atoi(CAMPOS[4]), atoi(CAMPOS[5]), atoi(CAMPOS[6]), atoi(CAMPOS[7])); //atof usa-se em float
        AddHashing(B->HLivros, L);

    }
    fclose(F);
    printf("Sai da Fun��o %s", __func__);
    return 1;
}
//------------------------------------------------------------------------------
/*
int AddLivroBiblioteca(BIBLIOTECA *B, LIVRO *L)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
*/
//------------------------------------------------------------------------------
LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------
char *ApelidoMaisComum(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------
char *AreaMaisComum(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------
/*
int AddRequisitante(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int RequeitarLivro(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int DevolverLivro(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------
*/
int ListarLivrosRequesitados(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int ListarClientes(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
   fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("Entrei em %s na data %s\n", __func__, ctime(&now));






   fprintf(F_Logs, "Sai de %s na data %s\n", __func__, ctime(&now));
    printf("Sai de %s na data %s\n", __func__, ctime(&now));
    fclose(F_Logs);
    return 0;

}
//------------------------------------------------------------------------------
int ListarRequesitantes(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
   fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("Entrei em %s na data %s\n", __func__, ctime(&now));






   fprintf(F_Logs, "Sai de %s na data %s\n", __func__, ctime(&now));
    printf("Sai de %s na data %s\n", __func__, ctime(&now));
    fclose(F_Logs);

    return 0;

}
//------------------------------------------------------------------------------
