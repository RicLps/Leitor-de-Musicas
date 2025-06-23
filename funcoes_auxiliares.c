#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define PAUSE(x) Sleep(x)
#else
    #include <unistd.h>
    #define PAUSE(x) sleep((x)/1000)
#endif

void adicionar(Musica lista_musicas[], int *total) {
    if (*total >= MAX_MUSICAS) {
        printf("A lista de musicas esta cheia.\n");
        return;
    }

    Musica musica_nova;
    musica_nova.id = *total + 1;
    musica_nova.vezes_ouvida = 0;

    getchar();
    printf("Insira o nome da musica: ");
    fgets(musica_nova.nome, TAM_NOME, stdin);
    musica_nova.nome[strcspn(musica_nova.nome, "\n")] = 0;

    printf("Insira o nome do artista da musica: ");
    fgets(musica_nova.artista, TAM_ARTISTA, stdin);
    musica_nova.artista[strcspn(musica_nova.artista, "\n")] = 0;

    printf("Insira o genero musical da musica: ");
    fgets(musica_nova.genero, TAM_GENERO, stdin);
    musica_nova.genero[strcspn(musica_nova.genero, "\n")] = 0;

    printf("Insira a duracao da musica (em segundos): ");
    scanf("%d", &musica_nova.duracao);
    getchar();

    lista_musicas[*total] = musica_nova;
    (*total)++;

    FILE *f = fopen("arquivo_musicas.txt", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(f, "Id da musica: %d\n", musica_nova.id);
    fprintf(f, "Nome: %s\n", musica_nova.nome);
    fprintf(f, "Artista: %s\n", musica_nova.artista);
    fprintf(f, "Genero: %s\n", musica_nova.genero);
    fprintf(f, "Duracao: %ds\n", musica_nova.duracao);
    fprintf(f, "------------------------------------------------------\n");

    fclose(f);
    printf("Musica adicionada com sucesso.\n");
}

void listar(Musica lista[], int total) {
    if (total == 0) {
        printf("Nenhuma musica cadastrada.\n");
        return;
    }
    printf("\nLista de Musicas:\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Artista: %s\n", lista[i].artista);
        printf("Genero: %s\n", lista[i].genero);
        printf("Duracao: %d segundos\n", lista[i].duracao);
        printf("Vezes ouvida: %d\n", lista[i].vezes_ouvida);
        printf("----------------------\n");
    }
}

void carregar_musicas(Musica lista[], int *total) {
    FILE *f = fopen("arquivo_musicas.txt", "r");
    if (f == NULL) {
        printf("Arquivo de musicas nao encontrado. Criando novo arquivo.\n");
        return;
    }

    char linha[256];
    Musica m;
    m.vezes_ouvida = 0;

    while (fgets(linha, sizeof(linha), f) {
        if (sscanf(linha, "Id da musica: %d", &m.id) == 1) {
            if (fgets(m.nome, TAM_NOME, f) == NULL) break;
            m.nome[strcspn(m.nome, "\n")] = 0;

            if (fgets(m.artista, TAM_ARTISTA, f) == NULL) break;
            m.artista[strcspn(m.artista, "\n")] = 0;

            if (fgets(m.genero, TAM_GENERO, f) == NULL) break;
            m.genero[strcspn(m.genero, "\n")] = 0;

            if (fgets(linha, sizeof(linha), f) == NULL) break;
            sscanf(linha, "Duracao: %ds", &m.duracao);

            fgets(linha, sizeof(linha), f); // Pular linha de separação

            lista[*total] = m;
            (*total)++;

            if (*total >= MAX_MUSICAS) break;
        }
    }
    fclose(f);
    printf("%d musicas carregadas do arquivo.\n", *total);
}

void eliminar(Musica lista_musicas[], int *total) {
    int id = 0;
    int musica_encontrada = 0;
    
    printf("Digite o ID da musica que deseja eliminar: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *total; i++) {
        if(lista_musicas[i].id == id) {
            musica_encontrada = 1;
            
            for (int j = i; j < *total - 1; j++) {
                lista_musicas[j] = lista_musicas[j + 1];
            }

            (*total)--;
            printf("Musica com id %d removida com sucesso.\n", id);
            break;
        }
    }
    
    if(!musica_encontrada) {
        printf("Musica com id %d nao encontrada.\n", id);
        return;
    }

    for (int i = 0; i < *total; i++) {
        lista_musicas[i].id = i + 1;
    }

    FILE *f_temp = fopen("temp.txt", "w");
    if (f_temp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        return;
    }

    for (int i = 0; i < *total; i++) {
        fprintf(f_temp, "Id da musica: %d\n", lista_musicas[i].id);
        fprintf(f_temp, "Nome: %s\n", lista_musicas[i].nome);
        fprintf(f_temp, "Artista: %s\n", lista_musicas[i].artista);
        fprintf(f_temp, "Genero: %s\n", lista_musicas[i].genero);
        fprintf(f_temp, "Duracao: %ds\n", lista_musicas[i].duracao);
        fprintf(f_temp, "------------------------------------------------------\n");
    }

    fclose(f_temp);
    remove("arquivo_musicas.txt");
    rename("temp.txt", "arquivo_musicas.txt");
}

void editar(Musica lista[], int total) {
    int id, encontrada = 0;

    printf("Digite o ID da musica que deseja editar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            encontrada = 1;

            printf("Novo nome da musica: ");
            fgets(lista[i].nome, TAM_NOME, stdin);
            lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;

            printf("Novo artista: ");
            fgets(lista[i].artista, TAM_ARTISTA, stdin);
            lista[i].artista[strcspn(lista[i].artista, "\n")] = 0;

            printf("Novo genero: ");
            fgets(lista[i].genero, TAM_GENERO, stdin);
            lista[i].genero[strcspn(lista[i].genero, "\n")] = 0;

            printf("Nova duracao (em segundos): ");
            scanf("%d", &lista[i].duracao);
            getchar();

            printf("Musica editada com sucesso!\n");
            break;
        }
    }

    if (!encontrada) {
        printf("Musica nao encontrada.\n");
        return;
    }

    FILE *f_temp = fopen("temp.txt", "w");
    if (f_temp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f_temp, "Id da musica: %d\n", lista[i].id);
        fprintf(f_temp, "Nome: %s\n", lista[i].nome);
        fprintf(f_temp, "Artista: %s\n", lista[i].artista);
        fprintf(f_temp, "Genero: %s\n", lista[i].genero);
        fprintf(f_temp, "Duracao: %ds\n", lista[i].duracao);
        fprintf(f_temp, "------------------------------------------------------\n");
    }

    fclose(f_temp);
    remove("arquivo_musicas.txt");
    rename("temp.txt", "arquivo_musicas.txt");
}

void salvar_estatisticas(Musica lista[], int total) {
    if (total == 0) return;

    FILE *f = fopen("arquivo_estatisticas.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar arquivo de estatisticas.\n");
        return;
    }

    int total_musicas = total;
    unsigned int tempo_total_ouvido = 0;
    int mais_ouvida_index = 0;
    int artistas_unicos = 0;
    char artistas[MAX_MUSICAS][TAM_ARTISTA];

    for (int i = 0; i < total; i++) {
        if (lista[i].duracao > 0 && lista[i].vezes_ouvida > 0) {
            unsigned int tempo_musica = lista[i].duracao * lista[i].vezes_ouvida;
            if (tempo_total_ouvido + tempo_musica > tempo_total_ouvido) {
                tempo_total_ouvido += tempo_musica;
            }
        }

        if (lista[i].vezes_ouvida > lista[mais_ouvida_index].vezes_ouvida) {
            mais_ouvida_index = i;
        }

        int encontrado = 0;
        for (int j = 0; j < artistas_unicos; j++) {
            if (strcmp(artistas[j], lista[i].artista) == 0) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strncpy(artistas[artistas_unicos], lista[i].artista, TAM_ARTISTA-1);
            artistas[artistas_unicos][TAM_ARTISTA-1] = '\0';
            artistas_unicos++;
        }
    }

    fprintf(f, "Total de musicas: %d\n", total_musicas);
    fprintf(f, "Musica mais ouvida: %s (%d vezes)\n", 
            lista[mais_ouvida_index].nome, 
            lista[mais_ouvida_index].vezes_ouvida);
    fprintf(f, "Tempo total ouvindo musicas: %u segundos\n", tempo_total_ouvido);
    fprintf(f, "Numero de artistas diferentes: %d\n", artistas_unicos);

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
    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }
    printf("=======================\n");

    fclose(f);
}

void tocar_musica(Musica lista[], int total){
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
        scanf("%d", &opcao);
        getchar();

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
                scanf("%d", &id_tocar);
                getchar();

                int encontrada = 0;

                for (int i = 0; i < total; i++) {
                    if (lista[i].id == id_tocar) {
                        lista[i].vezes_ouvida++;
                        salvar_estatisticas(lista, total);
                        printf("\nA tocar...\n");
                        printf("Nome: %s\n", lista[i].nome);
                        printf("Artista: %s\n", lista[i].artista);
                        printf("Duracao: %d segundos\n\n", lista[i].duracao);

                        for (int j = 0; j < lista[i].duracao && j < 10; j++) {
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
            getchar();
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
