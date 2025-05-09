#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>

void adicionar(Musica lista[], int *total) {
    if (*total >= MAX_MUSICAS) {
        printf("Limite de músicas atingido.\n");
        return;
    }

    Musica m;
    m.id = *total + 1;

    printf("Título da música: ");
    fgets(m.nome, TAM_NOME, stdin);
    strtok(m.nome, "\n");

    printf("Artista: ");
    fgets(m.artista, TAM_ARTISTA, stdin);
    strtok(m.artista, "\n");

    printf("Gênero: ");
    fgets(m.genero, TAM_GENERO, stdin);
    strtok(m.genero, "\n");

    printf("Duração (em segundos): ");
    scanf("%d", &m.duracao);
    getchar();

    lista[*total] = m;
    (*total)++;
    printf("Música adicionada com sucesso.\n");
}

void listar(Musica lista[], int total) {
    if (total == 0) {
        printf("Nenhuma música cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("ID: %d | %s - %s (%s) [%ds]\n",
               lista[i].id, lista[i].nome, lista[i].artista,
               lista[i].genero, lista[i].duracao);
    }
}

void eliminar(Musica lista[], int *total, int id) {
    int i, encontrado = 0;
    for (i = 0; i < *total; i++) {
        if (lista[i].id == id) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Música não encontrada.\n");
        return;
    }

    for (int j = i; j < *total - 1; j++) {
        lista[j] = lista[j + 1];
        lista[j].id = j + 1;
    }

    (*total)--;
    printf("Música eliminada.\n");
}

void editar(Musica lista[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            printf("Novo título: ");
            fgets(lista[i].nome, TAM_NOME, stdin);
            strtok(lista[i].nome, "\n");

            printf("Novo artista: ");
            fgets(lista[i].artista, TAM_ARTISTA, stdin);
            strtok(lista[i].artista, "\n");

            printf("Novo gênero: ");
            fgets(lista[i].genero, TAM_GENERO, stdin);
            strtok(lista[i].genero, "\n");

            printf("Nova duração: ");
            scanf("%d", &lista[i].duracao);
            getchar();

            printf("Música editada.\n");
            return;
        }
    }

    printf("Música com ID %d não encontrada.\n", id);
}

void tocar_musica(Musica lista[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            printf("\n+===============================+\n");
            printf("| A Tocar: %s\n", lista[i].nome);
            printf("| Artista: %s\n", lista[i].artista);
            printf("| Duração: %d segundos\n", lista[i].duracao);
            printf("+===============================+\n");
            printf("| p - Parar\n");
            printf("+===============================+\n");

            char comando;
            do {
                printf("Comando: ");
                comando = getchar();
            } while (comando != 'p');
            return;
        }
    }
    printf("Música não encontrada.\n");
}

