


#include "Biblioteca.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
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
    Bib->HPessoas = CriarHashingp();
    Bib->Req = CriarListaR();
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
void ShowLBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);

    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
void ShowPBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);

    ShowHashingp(B->HPessoas);

    fclose(F_Logs);
}
void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);
    printf("Quantidade de Categorias na Biblioteca = %d\n", B->HLivros->LChaves->NEL);
   // printf("Quantidade de Pessoas = %d\n",);

    // FUNÇÃO ADD: Mostrar Pessoas, Requesitantes, Livros requesitados (só o numero )
    printf("\n");
    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
//------------------------------------------------------------------------------
void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    DestruirListaR(B->Req);
    DestruirHashing(B->HLivros);
    DestruirHashingp(B->HPessoas);
    free (B->NOME);
    //------
    free(B);

    fclose(F_Logs);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

int AddLivroBiblioteca(BIBLIOTECA *B)
{
    LIVRO *L;
    int ano, mes, dia, ID;
    char isbn[20];
    char Autor[100];
    char titulo[100];
    char AREA[100];
    char buffer[100];

    FILE *F_Logs = fopen("logfile.txt", "a");// Exemplo de arquivo de log
    if (F_Logs == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de log.\n");
        return 1;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    printf("\nColoque as Informações do Novo Livro:\n");
    limparBuffer();
    printf("ISBN ( Ex:978-0-7432-7356-5 ) : ");
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';  // Remove o newline no final


    printf("\nAutor: ");
    fgets(Autor, sizeof(Autor), stdin);
    Autor[strcspn(Autor, "\n")] = '\0';  // Remove o newline no final

    printf("\nTitulo do Livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';  // Remove o newline no final

    printf("\nArea: ");
    fgets(AREA, sizeof(AREA), stdin);
    AREA[strcspn(AREA, "\n")] = '\0';  // Remove o newline no final

    do {
        printf("\nID: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &ID);
        if (IDExiste(B->HLivros, ID)) {
            printf("ID ja existe! Por favor, insira um ID unico.\n");
        }
    } while (IDExiste(B->HLivros, ID));

    // Verificação da data
    do {
        printf("\nData Da Criacao\nAno: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &ano);

        printf("\nMes: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &mes);

        printf("\nDia: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &dia);

        if (!DataValida(ano, mes, dia)) {
            printf("Data invalida! Por favor, insira uma data valida.\n");
        }
    } while (!DataValida(ano, mes, dia));


    L = CriarLivro(isbn,Autor, titulo, AREA, ID, ano, mes, dia);
    AddHashing(B->HLivros, L);
    FILE *FR = fopen("livros.txt", "a"); // Abrir o arquivo em modo de escrita, adicionando ao final
    if (FR == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fprintf(FR,"\n%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d",isbn, Autor, titulo, AREA, ID, dia, mes, ano);

    fclose(F_Logs);
    fclose(FR);
    return 1;
}
//------------------------------------------------------------------------------
/*
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

//------------------------------------------------------------------------------

int AddRequisitante(BIBLIOTECA *B)
{

    PESSOA *P;
    char id[20];
    char nome[100];
    char data[100];
    char idfreg[100];
    char buffer[100];

    FILE *F_Logs = fopen("logfile.txt", "a");// Exemplo de arquivo de log
    if (F_Logs == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de log.\n");
        return 1;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    printf("\nColoque as Informações do Novo Requesitante:\n");
    limparBuffer();
    printf("ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';  // Remove o newline no final


    printf("\nNome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  // Remove o newline no final

    printf("\nData (xx-yy-zzzz): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';  // Remove o newline no final

    printf("\nId Freguesia: ");
    fgets(idfreg, sizeof(idfreg), stdin);
    idfreg[strcspn(idfreg, "\n")] = '\0';  // Remove o newline no final



    P = CriarPessoa(id,nome,data,idfreg);
    AddHashingp(B->HPessoas, P);
    FILE *FR = fopen("requesitantes.txt", "a"); // Abrir o arquivo em modo de escrita, adicionando ao final
    if (FR == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fprintf(FR,"\n%s\t%s\t%s\t%s",id, nome, data, idfreg);

    fclose(F_Logs);
    fclose(FR);
    return 1;
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
int ContarLivros(LISTAL *L) {
    int count = 0;
    NO *p = L->Inicio;
    while (p != NULL) {
        count++;
        p = p->Prox;
    }
    return count;
}

// Função para encontrar a categoria com mais livros
void CategoriaMaisLivros(HASHING *H) {

    if (!H || !H->LChaves) return;

    NO_CHAVE *P = H->LChaves->Inicio;
    NO_CHAVE *categoriaMaisLivros = NULL;
    int maxLivros = 0;

    while (P) {
        int numLivros = ContarLivros(P->DADOS);
        if (numLivros > maxLivros) {
            maxLivros = numLivros;
            categoriaMaisLivros = P;
        }
        P = P->Prox;
    }

    if (categoriaMaisLivros) {
        printf("A categoria com mais livros: [%s] com [%d] livros.\n", categoriaMaisLivros->KEY, maxLivros);
    } else {
        printf("Nenhuma categoria encontrada.\n");
    }
}


void LivrosMaisRecentes(HASHING *H) {
    if (!H || !H->LChaves) return;

    NO_CHAVE *P = H->LChaves->Inicio;
    int anoMaisRecente = 0;
    LISTAL *livrosRecentes = CriarListaL();  // Lista para armazenar os livros mais recentes

    // Encontrar o ano mais recente
    while (P) {
        NO *L = P->DADOS->Inicio;
        while (L) {
            if (L->Info->data.ano > anoMaisRecente) {
                anoMaisRecente = L->Info->data.ano;
            }
            L = L->Prox;
        }
        P = P->Prox;
    }

    // Encontrar os livros com o ano mais recente
    P = H->LChaves->Inicio;
    while (P) {
        NO *L = P->DADOS->Inicio;
        while (L) {
            if (L->Info->data.ano == anoMaisRecente) {
                AddInicioL(livrosRecentes, L->Info);
            }
            L = L->Prox;
        }
        P = P->Prox;
    }

    // Mostrar os livros mais recentes
    printf("Livros mais recentes (Ano: %d):\n", anoMaisRecente);
    ShowListaL(livrosRecentes);

    // Liberar a memória alocada para a lista temporária de livros recentes
    DestruirListaL(livrosRecentes);
}

//---------------------------------------------------------------------------------------

LIVRO* EncontrarLivroPorISBN(BIBLIOTECA *Bib, char *_isbn) {
    if (Bib == NULL || Bib->HLivros == NULL || Bib->HLivros->LChaves == NULL || Bib->HLivros->LChaves->Inicio == NULL)
        return NULL;

    NO_CHAVE *chaveAtual = Bib->HLivros->LChaves->Inicio;
    while (chaveAtual) {
        NO *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->isbn, _isbn) == 0) {
                MostrarLivro(P->Info);
                return P->Info; // Saímos da função porque encontramos o ISBN
            }
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    printf("Livro com ISBN '%s' não encontrado.\n", _isbn);
    return NULL;
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
LIVRO* ExistenciaDoLivroPorISBN(BIBLIOTECA *Bib, char *_isbn) {
    if (Bib == NULL || Bib->HLivros == NULL || Bib->HLivros->LChaves == NULL || Bib->HLivros->LChaves->Inicio == NULL)
        return NULL;

    NO_CHAVE *chaveAtual = Bib->HLivros->LChaves->Inicio;
    while (chaveAtual) {
        NO *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->isbn, _isbn) == 0) {
                printf("\n Livro Existe: ");
                MostrarLivro(P->Info);
                return P->Info;
            }
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    printf("Livro com ISBN '%s' não encontrado.\n", _isbn);
    return NULL;
}

//---------------------------------------------------------------------------------------
PESSOA* EncontrarPessoaPorID(BIBLIOTECA *Bib, char *_id) {
    if (Bib == NULL || Bib->HPessoas == NULL || Bib->HPessoas->PChaves == NULL || Bib->HPessoas->PChaves->Inicio == NULL)
        return NULL;

    NO_CHAVEp *chaveAtual = Bib->HPessoas->PChaves->Inicio;
    while (chaveAtual) {
        NOp *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->ID, _id) == 0) {
                MostrarPessoa(P->Info);
                return P->Info; // Saímos da função porque encontramos o ISBN
            }
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    printf("ID '%s' não encontrado.\n", _id);
    return NULL;
}
//----------------------------------------------------------------------------------------
int ExistenciadoRequesitante(BIBLIOTECA *Bib, char *_id) {
    if (Bib == NULL || _id == NULL) {
        printf("Dados inválidos fornecidos.\n");
        return 0; // Retorna 0 indicando falha na pesquisa
    }

    if (Bib->Req == NULL || Bib->Req->Inicio == NULL) {
        printf("Lista de requesitantes vazia.\n");
        return 0; // Retorna 0 indicando falha na pesquisa
    }

    NOR *atual = Bib->Req->Inicio;
    while (atual != NULL) {
        if (strcmp(atual->Info->Ptr_Req->ID, _id) == 0) {
            printf("Requesitante com ID %s Tem Livros Requesitados.\n", _id);
            return 1; // Retorna 1 indicando sucesso na pesquisa
        }
        atual = atual->Prox;
    }

    printf("Requesitante com ID %s não encontrado.\n", _id);
    return 0; // Retorna 0 indicando falha na pesquisa
}

//-----------------------------------------------------------------------------------------
int IDExiste(HASHING *H, int ID) {
    NO_CHAVE *P = H->LChaves->Inicio;
    while (P) {
        NO *L = P->DADOS->Inicio;
        while (L) {
            if (L->Info->ID == ID) {
                return 1; // ID já existe
            }
            L = L->Prox;
        }
        P = P->Prox;
    }
    return 0; // ID não existe
}

int DataValida(int ano, int mes, int dia) {
    if (mes < 1 || mes > 12) {
        return 0;
    }

    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        diasNoMes[1] = 29;
    }
    if (dia < 1 || dia > diasNoMes[mes - 1]) {
        return 0;
    }

    return 1;
}
int removerLivroPorISBN(BIBLIOTECA *bib, char *_isbn) {
    if (bib == NULL || _isbn == NULL || bib->HLivros == NULL || bib->HLivros->LChaves == NULL) return 0;

    LISTA_CHAVES *listaChaves = bib->HLivros->LChaves;
    NO_CHAVE *chaveAtual = listaChaves->Inicio;

    while (chaveAtual != NULL) {
        LISTAL *lista = chaveAtual->DADOS;
        NO *atual = lista->Inicio;
        NO *anterior = NULL;

        while (atual != NULL) {
            if (strcmp(atual->Info->isbn, _isbn) == 0) {
                if (anterior == NULL) {
                    // Remover o primeiro nó
                    lista->Inicio = atual->Prox;
                } else {
                    // Remover nó do meio ou final
                    anterior->Prox = atual->Prox;
                }
                free(atual->Info->isbn);
                free(atual->Info->Autor);
                free(atual->Info->titulo);
                free(atual->Info->AREA);
                free(atual->Info);
                free(atual);
                lista->NEL--;
                return 1; // Sucesso
            }
            anterior = atual;
            atual = atual->Prox;
        }

        chaveAtual = chaveAtual->Prox;
    }

    return 0; // Livro não encontrado
}

//---------------------------------------------------------------
int CalcularIdade(char *datan) {
    int dia, mes, ano;
    sscanf(datan, "%d-%d-%d", &dia, &mes, &ano);  // Corrigido para o formato "dd-mm-yyyy"

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int idade = tm.tm_year + 1900 - ano;

    if (tm.tm_mon + 1 < mes || (tm.tm_mon + 1 == mes && tm.tm_mday < dia)) {
        idade--;
    }

    return idade;
}

void CalcularMediaIdadeRequisitantes(BIBLIOTECA *B) {
    if (B == NULL || B->HPessoas == NULL || B->HPessoas->PChaves->Inicio == NULL) {
        printf("0.0");
    }

    NO_CHAVEp *chaveAtual = B->HPessoas->PChaves->Inicio;
    int somaIdades = 0;
    int contagem = 0;

    while (chaveAtual != NULL) {
        NOp *pessoaAtual = chaveAtual->DADOS->Inicio;
        while (pessoaAtual != NULL) {
            int idade = CalcularIdade(pessoaAtual->Info->datan);
            somaIdades += idade;
            contagem++;
            pessoaAtual = pessoaAtual->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    if (contagem == 0) {
        printf("0.0");
    }
    float media = somaIdades / contagem;
    printf("A media e %.1f:",media); // Corrigido o cálculo da média
}



