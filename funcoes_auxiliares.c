#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #define PAUSE(x) Sleep(x)
#else
    #include <unistd.h>
    #define PAUSE(x) sleep((x)/1000)
#endif

void salvar_estatisticas(Musica lista[], int total) {
    if (lista == NULL) {
        printf("Lista de músicas inválida.\n");
        return;
    }

    if (total == 0) {
        printf("Nenhuma música cadastrada para gerar estatísticas.\n");
        return;
    }

    FILE *f = fopen("arquivo_estatisticas.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar arquivo de estatísticas.\n");
        return;
    }

    unsigned int tempo_total_ouvido = 0;
    int mais_ouvida_index = 0;
    int artistas_unicos = 0;
    char artistas[MAX_MUSICAS][TAM_ARTISTA];

    for (int i = 0; i < total; i++) {
        // Calcula tempo total ouvido
        if (lista[i].duracao > 0 && lista[i].vezes_ouvida >= 0) {
            tempo_total_ouvido += (unsigned int)(lista[i].duracao * lista[i].vezes_ouvida);
        }

        // Encontra música mais ouvida
        if (lista[i].vezes_ouvida > lista[mais_ouvida_index].vezes_ouvida) {
            mais_ouvida_index = i;
        }

        // Conta artistas únicos
        int artista_novo = 1;
        for (int j = 0; j < artistas_unicos; j++) {
            if (strcmp(artistas[j], lista[i].artista) == 0) {
                artista_novo = 0;
                break;
            }
        }
        if (artista_novo) {
            strncpy(artistas[artistas_unicos], lista[i].artista, TAM_ARTISTA-1);
            artistas[artistas_unicos][TAM_ARTISTA-1] = '\0';
            artistas_unicos++;
        }
    }

    // Escreve estatísticas no arquivo
    fprintf(f, "=== Estatísticas de Músicas ===\n");
    fprintf(f, "Total de músicas: %d\n", total);
    fprintf(f, "Música mais ouvida: %s (%d vezes)\n", 
            lista[mais_ouvida_index].nome, 
            lista[mais_ouvida_index].vezes_ouvida);
    fprintf(f, "Tempo total ouvindo músicas: %u segundos\n", tempo_total_ouvido);
    fprintf(f, "Número de artistas diferentes: %d\n", artistas_unicos);

    fclose(f);
}

void mostrar_estatisticas(Musica lista[], int total) {
    FILE *f = fopen("arquivo_estatisticas.txt", "r");
    if (f == NULL) {
        printf("Nenhuma estatistica disponivel.\n");
        return;
    }

    char linha[256];
    printf("\n===== Estatisticas =====\n");
    while (fgets(linha, sizeof(linha), f) {
        printf("%s", linha);
    }
    printf("=======================\n");

    fclose(f);
}

void tocar_musica(Musica lista[], int total) {
    if (lista == NULL) {
        printf("Lista de músicas inválida.\n");
        printf("\nPressione Enter para continuar...");
        while(getchar() != '\n');
        return;
    }

    int opcao;

    do {
        system("cls");
        printf("\n+===============================+\n");
        printf("|           Tocar Música        |\n");
        printf("+===============================+\n");
        printf("| 1. Listar musicas             |\n");
        printf("| 2. Tocar musica por ID        |\n");
        printf("| 0. Voltar                     |\n");
        printf("+===============================+\n\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while(getchar() != '\n');
            printf("Entrada inválida.\n");
            continue;
        }
        while(getchar() != '\n');

        switch (opcao) {
            case 1:
                if (total == 0) {
                    printf("Nenhuma musica cadastrada.\n");
                } else {
                    printf("\n+========= Lista de Musicas =========+\n");
                    for (int i = 0; i < total; i++) {
                        printf("ID: %d\n", lista[i].id);
                        printf("Nome: %s\n", lista[i].nome);
                        printf("Artista: %s\n", lista[i].artista);
                        printf("Genero: %s\n", lista[i].genero);
                        printf("Duracao: %d segundos\n", lista[i].duracao);
                        printf("-------------------------------------\n");
                    }
                }
                break;

            case 2: {
                if (total == 0) {
                    printf("Nenhuma musica disponivel para tocar.\n");
                    break;
                }

                int id_tocar;
                printf("Digite o ID da musica que deseja tocar: ");
                if (scanf("%d", &id_tocar) != 1) {
                    printf("ID inválido.\n");
                    while(getchar() != '\n');
                    break;
                }
                while(getchar() != '\n');

                int encontrada = 0;

                for (int i = 0; i < total; i++) {
                    if (lista[i].id == id_tocar) {
                        lista[i].vezes_ouvida++;
                        salvar_estatisticas(lista, total);
                        printf("\nA tocar...\n");
                        printf("Nome: %s\n", lista[i].nome);
                        printf("Artista: %s\n", lista[i].artista);
                        printf("Duracao: %d segundos\n\n", lista[i].duracao);

                        // Animação de tocar música por toda a duração
                        for (int j = 0; j < lista[i].duracao; j++) {
                            if (j % 2 == 0) printf("\r/");
                            else printf("\r\\");
                            fflush(stdout);
                            PAUSE(1000);
                        }

                        printf("\rMúsica finalizada!\n");
                        encontrada = 1;
                        break;
                    }
                }

                if (!encontrada)
                    printf("Musica com ID %d nao encontrada.\n", id_tocar);
                break;
            }

            case 0:
                break;

            default:
                printf("Opção invalida.\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            while(getchar() != '\n');
        }

    } while (opcao != 0);
}

void criar_album(Album albuns[], int *total_albuns) {
    if (*total_albuns >= MAX_ALBUNS) {
        printf("Limite de albuns atingido.\n");
        return;
    }

    Album novo_album;
    novo_album.total_musicas = 0;

    printf("Insira o nome do album: ");
    fgets(novo_album.nome, NOME_ALBUM, stdin);
    novo_album.nome[strcspn(novo_album.nome, "\n")] = 0;

    albuns[*total_albuns] = novo_album;
    (*total_albuns)++;

    printf("Album '%s' criado com sucesso.\n", novo_album.nome);
}

void adicionar_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Nenhum album criado ainda.\n");
        return;
    }

    printf("Albuns disponiveis:\n");
    for (int i = 0; i < total_albuns; i++) {
        printf("%d. %s\n", i, albuns[i].nome);
    }

    int escolha_album;
    printf("Escolha o album: ");
    scanf("%d", &escolha_album);
    getchar();

    if (escolha_album < 0 || escolha_album >= total_albuns) {
        printf("Album invalido.\n");
        return;
    }

    if (albuns[escolha_album].total_musicas >= MAX_MUSICAS_ALBUM) {
        printf("Album cheio.\n");
        return;
    }

    printf("Musicas disponiveis:\n");
    for (int i = 0; i < total_musicas; i++) {
        printf("%d. %s\n", lista_musicas[i].id, lista_musicas[i].nome);
    }

    int id_musica;
    printf("Escolha o ID da musica: ");
    scanf("%d", &id_musica);
    getchar();

    int musica_encontrada = 0;
    for (int i = 0; i < total_musicas; i++) {
        if (lista_musicas[i].id == id_musica) {
            albuns[escolha_album].id_musica[albuns[escolha_album].total_musicas] = id_musica;
            albuns[escolha_album].total_musicas++;
            musica_encontrada = 1;
            printf("Musica adicionada ao album.\n");
            break;
        }
    }

    if (!musica_encontrada) {
        printf("Musica nao encontrada.\n");
    }
}

void listar_musicas_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Nenhum album criado ainda.\n");
        return;
    }

    printf("Albuns disponiveis:\n");
    for (int i = 0; i < total_albuns; i++) {
        printf("%d. %s\n", i, albuns[i].nome);
    }

    int escolha_album;
    printf("Escolha o album: ");
    scanf("%d", &escolha_album);
    getchar();

    if (escolha_album < 0 || escolha_album >= total_albuns) {
        printf("Album invalido.\n");
        return;
    }

    if (albuns[escolha_album].total_musicas == 0) {
        printf("Album vazio.\n");
        return;
    }

    printf("Musicas no album %s:\n", albuns[escolha_album].nome);
    for (int i = 0; i < albuns[escolha_album].total_musicas; i++) {
        for (int j = 0; j < total_musicas; j++) {
            if (lista_musicas[j].id == albuns[escolha_album].id_musica[i]) {
                printf("%d. %s\n", lista_musicas[j].id, lista_musicas[j].nome);
                break;
            }
        }
    }
}

void remover_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Nenhum album criado ainda.\n");
        return;
    }

    printf("Albuns disponiveis:\n");
    for (int i = 0; i < total_albuns; i++) {
        printf("%d. %s\n", i, albuns[i].nome);
    }

    int escolha_album;
    printf("Escolha o album: ");
    scanf("%d", &escolha_album);
    getchar();

    if (escolha_album < 0 || escolha_album >= total_albuns) {
        printf("Album invalido.\n");
        return;
    }

    if (albuns[escolha_album].total_musicas == 0) {
        printf("Album vazio.\n");
        return;
    }

    printf("Musicas no album:\n");
    for (int i = 0; i < albuns[escolha_album].total_musicas; i++) {
        for (int j = 0; j < total_musicas; j++) {
            if (lista_musicas[j].id == albuns[escolha_album].id_musica[i]) {
                printf("%d. %s\n", lista_musicas[j].id, lista_musicas[j].nome);
                break;
            }
        }
    }

    int id_musica;
    printf("Escolha o ID da musica para remover: ");
    scanf("%d", &id_musica);
    getchar();

    int encontrada = 0;
    for (int i = 0; i < albuns[escolha_album].total_musicas; i++) {
        if (albuns[escolha_album].id_musica[i] == id_musica) {
            for (int j = i; j < albuns[escolha_album].total_musicas - 1; j++) {
                albuns[escolha_album].id_musica[j] = albuns[escolha_album].id_musica[j + 1];
            }
            albuns[escolha_album].total_musicas--;
            encontrada = 1;
            printf("Musica removida do album.\n");
            break;
        }
    }

    if (!encontrada) {
        printf("Musica nao encontrada no album.\n");
    }
}

void apagar_album(Album albuns[], int *total_albuns) {
    if (*total_albuns == 0) {
        printf("Nenhum album criado ainda.\n");
        return;
    }

    printf("Albuns disponiveis:\n");
    for (int i = 0; i < *total_albuns; i++) {
        printf("%d. %s\n", i, albuns[i].nome);
    }

    int escolha_album;
    printf("Escolha o album para apagar: ");
    scanf("%d", &escolha_album);
    getchar();

    if (escolha_album < 0 || escolha_album >= *total_albuns) {
        printf("Album invalido.\n");
        return;
    }

    for (int i = escolha_album; i < *total_albuns - 1; i++) {
        albuns[i] = albuns[i + 1];
    }
    (*total_albuns)--;

    printf("Album removido com sucesso.\n");
}

void listar_albuns(Album albuns[], int total_albuns) {
    if (total_albuns == 0) {
        printf("Nenhum album criado ainda.\n");
        return;
    }

    printf("Lista de albuns:\n");
    for (int i = 0; i < total_albuns; i++) {
        printf("%d. %s (%d musicas)\n", i, albuns[i].nome, albuns[i].total_musicas);
    }
}

int validarDados(const char *entrada) {
    int len = strlen(entrada);

    if(len < 3 || len > 50) {
        printf("Atencao: O nome deve ter entre 3 a 50 caracteres");
        return 0;
    }

    for (int i = 0; i < len; i++) {
        char c = entrada[i];
        if(!isalnum(c) && c != ' ' && c != '_' && c != '-') {
            printf("Atencao: Nome invalido, use somente letras, numeros, espaco, underscore e hifens.");
            return 0;
        }
    }

    if (strspn(entrada, " ") == len) {
        printf("Atencao: Insira algum caracter valido");
        return 0;
    }

    return 1;
}
