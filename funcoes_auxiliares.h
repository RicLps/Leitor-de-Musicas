#define MAX_MUSICAS 100
#define TAM_NOME 50
#define TAM_ARTISTA 100
#define TAM_GENERO 50
#define MAX_ALBUNS 15
#define NOME_ALBUM 50
#define MAX_MUSICAS_ALBUM 100
 
FILE *f; //Ponteiro para um arquivo
int total = 0;

//Struct que armazena os diferentes dados das músicas
typedef struct {
    int id;
    char nome[TAM_NOME];
    char artista[TAM_ARTISTA];
    char genero[TAM_GENERO];
    int duracao;
} Musica;

//Struct que armazena os dados referentes a albuns
typedef struct {
    char nome[NOME_ALBUM];
    int id_musica[MAX_MUSICAS_ALBUM];
    int total_musicas;
} Album;

//Declaração de todas as funções usadas no programa
void adicionar(Musica lista[], int *total);
void listar(Musica lista[], int total);
void eliminar(Musica lista[], int *total);
void editar(Musica lista[], int total);
void tocar_musica(Musica lista[], int total);
void criar_album(Album albuns[], int *total_albuns);
void adicionar_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas);
void listar_musicas_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas);
void remover_musica_album(Album albuns[], int total_albuns);
void validarDados(const char *entrada);
