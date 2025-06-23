#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    #define PAUSE(x) Sleep(x)
#else
    #include <unistd.h>
    #define PAUSE(x) sleep((x)/1000)
#endif

void adicionar(Musica lista_musicas[], int *total) {
    int verificar_entrada;
    
    if (*total >= MAX_MUSICAS) {
        printf("A lista de musicas esta cheia.\n");
        return;
    }

    Musica musica_nova;
    musica_nova.id = *total + 1;
    musica_nova.vezes_ouvida = 0;

    getchar();
    do {
        printf("Insira o nome da musica: ");
        fgets(musica_nova.nome, TAM_NOME, stdin);
        musica_nova.nome[strcspn(musica_nova.nome, "\n")] = '\0';

        verificar_entrada = validarDados(musica_nova.nome);
        
        if(verificar_entrada == 0){
            printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
            getchar();
        } 
    } while(verificar_entrada == 0);

    do {
        printf("Insira o nome do artista: ");
        fgets(musica_nova.artista, TAM_ARTISTA, stdin);
        musica_nova.artista[strcspn(musica_nova.artista, "\n")] = '\0';

        verificar_entrada = validarDados(musica_nova.artista);
        
        if(verificar_entrada == 0){
            printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
            getchar();
        } 
    } while(verificar_entrada == 0);

    do {
        printf("Insira o Genero da musica: ");
        fgets(musica_nova.genero, TAM_GENERO, stdin);
        musica_nova.genero[strcspn(musica_nova.genero, "\n")] = '\0';

        verificar_entrada = validarDados(musica_nova.genero);
        
        if(verificar_entrada == 0){
            printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
            getchar();
        } 
    } while(verificar_entrada == 0);

    printf("Insira a duracao da musica (em segundos): ");
    scanf("%d", &musica_nova.duracao);
    getchar();

    lista_musicas[*total] = musica_nova;
    (*total)++;

    FILE *f = fopen("arquivo_musicas.txt", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo 'arquivo_musicas.txt' ");
        return;
    }

    fprintf(f, "Id da musica: %d\n", musica_nova.id);
    fprintf(f, "Nome: %s\n", musica_nova.nome);
    fprintf(f, "Artista: %s\n", musica_nova.artista);
    fprintf(f, "Genero: %s\n", musica_nova.genero);
    fprintf(f, "Duracao: %ds\n", musica_nova.duracao);
    fprintf(f, "------------------------------------------------------\n");

    fclose(f); 
    printf("Musica adicionada na lista de musicas e gravada no arquivo.\n");
}

void listar(Musica lista[], int total) {
    if (total == 0) {
        printf("Nenhuma musica inserida no sistema.\n");
        return;
    }
    printf("\nLista de Musicas:\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Artista: %s\n", lista[i].artista);
        printf("Genero: %s\n", lista[i].genero);
        printf("Duracao: %d segundos\n", lista[i].duracao);
        printf("----------------------\n");
    }
}

void criar_album(Album albuns[], int *total_albuns) {
    int verificar_entrada;
    
    if (*total_albuns >= MAX_ALBUNS) {
        printf("Nao e possível criar album porque voce excedeu o limite de criacao de albuns.\n");
        return;
    }
    
    Album novo_album;
    novo_album.total_musicas = 0;

    do {
        printf("Insira o nome do album a se criar (maximo 50 caracteres): ");
        fgets(novo_album.nome, NOME_ALBUM, stdin);
        novo_album.nome[strcspn(novo_album.nome, "\n")] = '\0';

        verificar_entrada = validarDados(novo_album.nome);

        if(verificar_entrada == 0){
            printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
            getchar();
        }
    } while(verificar_entrada == 0);

    albuns[*total_albuns] = novo_album;
    (*total_albuns)++;

    printf("\nAlbum '%s' foi criado com sucesso.\nLembre-se que um album aceita somente 100 musicas! \n", novo_album.nome);
}

// ... (outras funções permanecem iguais, exceto pelas correções abaixo)

void editar(Musica lista[], int total) {
    int verificar_entrada;
    int id, encontrada = 0;

    printf("Digite o ID da musica que deseja editar: \n");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            encontrada = 1;

            do {
                printf("Novo nome da musica: ");
                fgets(lista[i].nome, TAM_NOME, stdin);
                lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

                verificar_entrada = validarDados(lista[i].nome);

                if(verificar_entrada == 0){
                    printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
                    getchar();
                }
            } while(verificar_entrada == 0);
            
            do {
                printf("Novo nome do artista: ");
                fgets(lista[i].artista, TAM_ARTISTA, stdin);
                lista[i].artista[strcspn(lista[i].artista, "\n")] = '\0';

                verificar_entrada = validarDados(lista[i].artista);

                if(verificar_entrada == 0){
                    printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
                    getchar();
                }
            } while(verificar_entrada == 0);

            do {
                printf("Novo genero: ");
                fgets(lista[i].genero, TAM_GENERO, stdin);
                lista[i].genero[strcspn(lista[i].genero, "\n")] = '\0';

                verificar_entrada = validarDados(lista[i].genero);

                if(verificar_entrada == 0){
                    printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
                    getchar();
                }
            } while(verificar_entrada == 0);

            printf("Nova duracao (em segundos): ");
            scanf("%d", &lista[i].duracao);
            getchar();

            printf("Musica com ID %d editada com sucesso!\n", id);

            FILE *f_temp = fopen("temp.txt", "w");
            if (f_temp == NULL) {
                printf("Erro ao criar arquivo temporario (temp.txt). \n");
                return;
            }

            for (int j = 0; j < total; j++) {
                fprintf(f_temp, "Id da musica: %d\n", lista[j].id);
                fprintf(f_temp, "Nome: %s\n", lista[j].nome);
                fprintf(f_temp, "Artista: %s\n", lista[j].artista);
                fprintf(f_temp, "Genero: %s\n", lista[j].genero);
                fprintf(f_temp, "Duracao: %ds\n", lista[j].duracao);
                fprintf(f_temp, "------------------------------------------------------\n");
            }

            if (fclose(f_temp) != 0) {
                printf("Erro ao fechar arquivo temporario.\n");
                remove("temp.txt");
                return;
            }

            if (remove("arquivo_musicas.txt") != 0) {
                printf("Erro ao remover arquivo antigo.\n");
                remove("temp.txt");
                return;
            }

            if (rename("temp.txt", "arquivo_musicas.txt") != 0) {
                printf("Erro ao renomear arquivo temporario.\n");
                remove("temp.txt");
            }
            break;
        }
    }

    if (!encontrada) {
        printf("Musica com ID %d nao foi encontrada.\n", id);
    }
}

void carregar_musicas(Musica lista[], int *total) {
    FILE *f = fopen("arquivo_musicas.txt", "r");
    if (f == NULL) {
        printf("Arquivo de musicas não encontrado.\n");
        return;
    }

    char linha[256];
    Musica m;
    m.vezes_ouvida = 0;

    while (fgets(linha, sizeof(linha), f) != NULL) {
        if (sscanf(linha, "Id da musica: %d", &m.id) != 1)
            continue;

        if (fgets(m.nome, TAM_NOME, f) == NULL) break;
        m.nome[strcspn(m.nome, "\n")] = '\0';

        if (fgets(m.artista, TAM_ARTISTA, f) == NULL) break;
        m.artista[strcspn(m.artista, "\n")] = '\0';

        if (fgets(m.genero, TAM_GENERO, f) == NULL) break;
        m.genero[strcspn(m.genero, "\n")] = '\0';

        if (fgets(linha, sizeof(linha), f) == NULL) break;
        sscanf(linha, "Duracao: %ds", &m.duracao);

        fgets(linha, sizeof(linha), f);

        lista[*total] = m;
        (*total)++;

        if (*total >= MAX_MUSICAS)
            break;
    }

    fclose(f);
    printf("%d musicas carregadas do arquivo.\n", *total);
}
