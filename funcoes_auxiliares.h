#define MAX_MUSICAS 100
#define TAM_NOME 100
#define TAM_ARTISTA 100
#define TAM_GENERO 50
#define MAX_ALBUNS 15
#define NOME_ALBUM 21
#define MAX_MUSICAS_ALBUM 100

FILE *f;
int total = 0;

typedef struct {
    int id;
    char nome[TAM_NOME];
    char artista[TAM_ARTISTA];
    char genero[TAM_GENERO];
    int duracao;
} Musica;

typedef struct {
    char nome[NOME_ALBUM];
    int id_musica[MAX_MUSICAS_ALBUM];
    int total_musicas;
} Album;

void adicionar(Musica lista[], int total);
void listar(Musica lista[], int total);
void eliminar(Musica lista[], int total);
void tocar_musica();
