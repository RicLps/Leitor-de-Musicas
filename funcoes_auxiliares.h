#define MAX_MUSICAS 100
#define TAM_NOME 100
#define TAM_ARTISTA 100
#define TAM_GENERO 50

typedef struct {
    int id;
    char nome[TAM_NOME];
    char artista[TAM_ARTISTA];
    char genero[TAM_GENERO];
    int duracao;
} Musica;

void adicionar(Musica lista[], int *total);
void listar(Musica lista[], int total);
void eliminar(Musica lista[], int *total, int id);
void tocar_musica(Musica lista[], int total, int id);


