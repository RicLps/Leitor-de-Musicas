#include <stdio.h>
#define MAX_MUSICAS 100
#define TAM_NOME 50
#define TAM_ARTISTA 100
#define TAM_GENERO 50
#define MAX_ALBUNS 15
#define NOME_ALBUM 50
#define MAX_MUSICAS_ALBUM 100

typedef struct {
    int id;
    char nome[TAM_NOME];
    char artista[TAM_ARTISTA];
    char genero[TAM_GENERO];
    int duracao;
    int vezes_ouvida;
} Musica;

typedef struct {
    char nome[NOME_ALBUM];
    int id_musica[MAX_MUSICAS_ALBUM];
    int total_musicas;
} Album;

// Protótipos das funções
void adicionar(Musica lista[], int *total);
void listar(Musica lista[], int total);
void eliminar(Musica lista[], int *total);
void editar(Musica lista[], int total);
void tocar_musica(Musica lista[], int total);
void criar_album(Album albuns[], int *total_albuns);
void adicionar_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas);
void listar_musicas_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas);
void remover_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas);
void apagar_album(Album albuns[], int *total_albuns);
void listar_albuns(Album albuns[], int total_albuns);
void carregar_musicas(Musica lista[], int *total);
void mostrar_estatisticas(Musica lista[], int total);
void salvar_estatisticas(Musica lista[], int total);
void leitura(const char *nome);
void escrever(const char *nome, const char *conteudo);
