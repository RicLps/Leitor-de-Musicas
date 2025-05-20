#define MAX_MUSICAS 100
#define TAM_NOME 100
#define TAM_ARTISTA 100
#define TAM_GENERO 50

int total = 0;

typedef struct {
    int id;
    char nome[TAM_NOME];
    char artista[TAM_ARTISTA];
    char genero[TAM_GENERO];
    int duracao;
} Musica;

int adicionar(Musica lista[], int total);
void listar(Musica lista[], int total);
int eliminar(Musica lista[], int total);
void tocar_musica();
