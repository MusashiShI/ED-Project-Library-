#include "Texto.h"
#include "Livro.h"
#include "Pessoa.h"
int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{

   printf("Entrei na Função %s", __func__);
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
    printf("Sai da Função %s", __func__);
    return 1;
}
//----------------------------------------------------------------------------------------------
int LoadFicheiroBibliotecaPessoas(BIBLIOTECA *B)
{


   printf("Entrei na Função %s", __func__);
    FILE *F = fopen("requesitantes.txt","r"); // FILE *F = fopen(ficheiro,"r");
    if(!F) return 0;

    char BUFFER[1001];

    while(!feof(F))
    {

        fgets(BUFFER, 1000, F);
       // printf("Linha [%s] \n",BUFFER);
        int i = 0;
        char *CAMPOS[4];
        char *tokenp = strtok (BUFFER, "\t\n"); //Separa a string pelo '\t'
        while (tokenp != NULL)
        {

            CAMPOS[i] = tokenp;
            tokenp = strtok (NULL, "\t\n");
            i++;

        }

        PESSOA *P = CriarPessoa(CAMPOS[0], CAMPOS[1], CAMPOS[2], CAMPOS[3]);

        AddHashingp(B->HPessoas, P);


    }
    fclose(F);
    printf("Sai da Função %s", __func__);
    return 1;
}
