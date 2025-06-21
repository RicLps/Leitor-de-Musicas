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


//Função que adiciona uma música ao arquivo de texto
void adicionar(Musica lista_musicas[], int *total) { //  total armazena a lista de músicas disponíveis

    if (*total >= MAX_MUSICAS) {
        printf("A lista de musicas esta cheia.\n");
        return;
    }

Musica musica_nova; // crie uma 2 que contem todos os atributos de Musica2

musica_nova.id = *total + 1;  // adiciona o id da musica na lista de musicas (total) 

getchar();
//Pede os dados da música ao utilizador

do{
    printf("Insira o nome da musica: ");
    fgets(musica_nova.nome, TAM_NOME, stdin);
    musica_nova.nome[strcspn(musica_nova.nome, "\n")] = 0;

    verificar_entrada = validarDados(musica_nova.nome);
    
    if(verificar_entrada == 1){
        printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
        getchar();
    } 
}while(verificar_entrada == 1);

do{
    printf("Insira o nome do artista: ");
    fgets(musica_nova.artista, TAM_ARTISTA, stdin);
    musica_nova.artista[strcspn(musica_nova.artista, "\n")] = 0;

    verificar_entrada = validarDados(musica_nova.artista);
    
    if(verificar_entrada == 1){
        printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
        getchar();
    } 
}while(verificar_entrada == 1);

do{
    printf("Insira o Genero da musica: ");
    fgets(musica_nova.genero, TAM_GENERO, stdin);
    musica_nova.genero[strcspn(musica_nova.genero, "\n")] = 0;

    verificar_entrada = validarDados(musica_nova.genero);
    
    if(verificar_entrada == 1){
        printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
        getchar();
    } 
}while(verificar_entrada == 1);

printf("Insira a duracao da musica (em segundos): ");
scanf("%d", &musica_nova.duracao);
getchar();


lista_musicas[*total] = musica_nova;
(*total)++;

//Abre o arquivo que guarda as músicas
FILE *f = fopen("arquivo_musicas.txt", "a");

//Verifica se deu erro ou não ao abrir o arquivo
if (f == NULL) {
    printf("Erro ao abrir o arquivo “arquivo_musicas.txt” ");
    return;
}

//Escreve os dados inseridos pelo utilizador no arquivo
fprintf(f, "Id da musica: %d\n", musica_nova.id);
fprintf(f, "Nome: %s\n", musica_nova.nome);
fprintf(f, "Artista: %s\n", musica_nova.artista);
fprintf(f, "Genero: %s\n", musica_nova.genero);
fprintf(f, "Duracao: %ds\n", musica_nova.duracao);
fprintf(f, "------------------------------------------------------\n");

//Fecha o arquivo
fclose(f); 
printf("Musica adicionada na lista de musicas e gravada no arquivo.\n");
}


// Função Listar musicas do programa
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



//Função que cria um novo album
void criar_album(Album albuns[], int *total_albuns) {

//Verifica se ultrapassou-se o número máximo de albuns
if (*total_albuns >= MAX_ALBUNS) {
        printf("Nao e possível criar album porque voce excedeu o limite de criacao de albuns.\n");
        return;
}
 Album novo_album;
 novo_album.total_musicas = 0; // define o total_musicas = 0, já que não adicionamos músicas ainda.

do{
    printf("Insira o nome do album a se criar (maximo 50 caracteres): ");
    fgets(novo_album.nome, NOME_ALBUM, stdin);

    verificar_entrada = validarDados(novo_album.nome);

    if(verificar_entrada == 1){
        printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
        getchar();
    }
}while(verificar_entrada == 1);

albuns[*total_albuns] = novo_album; // vai adicionar um o álbum que criei na próxima posição livre do array albums.
(*total_albuns)++; // aumenta o valor do *total_albuns para mostrar que um album foi criado dentor do *total_albuns

printf("\nAlbum '%s' foi criado com sucesso.\nLembre-se que um album aceita somente 100 musicas! \n", novo_album.nome);
}

void adicionar_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Ainda nao foi criado nenhum album.\n");
        getchar(); 
        return;
    }

    int escolha_album;
    printf("Escolha o album para adicionar musicas:\n");
    for (int i = 0; i < total_albuns; i++) {
        printf("Id: %d - Album: %s\n", i, albuns[i].nome);
    }

    printf("Insira o id do album: ");
    if (scanf("%d", &escolha_album) != 1) {
        printf("Album Invalido.\n");
        while (getchar() != '\n'); 
        getchar(); 
        return;
    }
    getchar(); 

    if (escolha_album < 0 || escolha_album >= total_albuns) {
        printf("O Album com id %d nao existe.\n", escolha_album);
        getchar(); 
        return;
    }

    if (albuns[escolha_album].total_musicas >= MAX_MUSICAS_ALBUM) {
        printf("O album ja atingiu o limite maximo de 100 musicas.\n");
        getchar(); 
        return;
    }

    printf("Musicas disponiveis:\n");
    for (int i = 0; i < total_musicas; i++) {
        printf("Id: %d - %s\n", lista_musicas[i].id, lista_musicas[i].nome);
    }

    int id_musica;
    printf("Insira o Id da musica que deseja adicionar ao album: ");
    if (scanf("%d", &id_musica) != 1) {
        printf("Id da musica Invalido.\n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    int pesquisa_musica = 0;
    for (int i = 0; i < total_musicas; i++) {
        if (lista_musicas[i].id == id_musica) {
            pesquisa_musica = 1;
            albuns[escolha_album].id_musica[albuns[escolha_album].total_musicas] = id_musica;
            albuns[escolha_album].total_musicas++;

            printf("\nA musica com Id '%d' foi adicionada ao album '%s'.\n", id_musica, albuns[escolha_album].nome);
            break;
        }
    }

    if (!pesquisa_musica) {
        printf("A musica com Id %d não foi encontrada.\n", id_musica);
    }

    printf("Pressione Enter para continuar...");
    getchar(); 
}


void listar_musicas_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Nenhum album foi criado.\n");
        getchar(); 
        return;
    }

    int id_album;

    printf("\nAlbuns Disponiveis:\n");
    for (int i = 0; i < total_albuns; i++) {
        printf("Id: %d - Album: %s\n", i, albuns[i].nome);
    }

    printf("Escolha o id do Album: ");
    if (scanf("%d", &id_album) != 1) {
        printf("Album Invalido.\n");
        while (getchar() != '\n'); 
        getchar(); 
    }

    if (id_album < 0 || id_album >= total_albuns) {
        printf("Album Invalido.\n");
        getchar(); 
        return;
    }

    if (albuns[id_album].total_musicas == 0) {
        printf("O album nao tem nenhuma musica.\n");
        getchar(); 
        return;
    }

    printf("\nMusicas do Album '%s': \n", albuns[id_album].nome);

    for (int i = 0; i < albuns[id_album].total_musicas; i++) {
        int id_musica = albuns[id_album].id_musica[i];
        int encontrada = 0;

        for (int j = 0; j < total_musicas; j++) {
            if (lista_musicas[j].id == id_musica) {
                printf("Id: %d - Nome: %s\n", lista_musicas[j].id, lista_musicas[j].nome);
                encontrada = 1;
                break;
            }
        }

        if (!encontrada) {
            printf("Musica com ID %d nao encontrada na lista de musicas.\n", id_musica);
        }
    }

    printf("\nPressione Enter para continuar...");
    getchar(); 
}


//Função que remove uma música de um album
void remover_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    // Verifica se há algum álbum
    if (total_albuns == 0) {
        printf("Nenhum album foi criado ainda.\n");
        return;
    }

    int id_album;
    printf("Escolha o id do album para remover a musica: \n");
    for (int i = 0; i < total_albuns; i++) {
        printf("Id: %d - Album: %s\n", i, albuns[i].nome);
    }

    scanf("%d", &id_album);
    getchar(); 

    // Verifica se o id inserido está correto
    if (id_album < 0 || id_album >= total_albuns) {
        printf("\nAlbum com id %d nao existe.\n", id_album);
        return;
    }

    // Verifica se há músicas no álbum selecionado
    if (albuns[id_album].total_musicas == 0) {
        printf("O Album nao tem nenhuma musica ainda.\n");
        return;
    }

    // Lista as músicas do álbum mostrando o id e nome na mesma linha
    printf("Musicas do album %s:\n", albuns[id_album].nome);
    for (int i = 0; i < albuns[id_album].total_musicas; i++) {
        int id_musica = albuns[id_album].id_musica[i];

        for (int j = 0; j < total_musicas; j++) {
            if (lista_musicas[j].id == id_musica) {
                printf("Posicao %d - Id da musica: %d - Nome: %s\n", i, id_musica, lista_musicas[j].nome);
                break;
            }
        }
    }

    int id_musica_remover;
    printf("Insira o id da musica que quer remover do álbum: \n");
    scanf("%d", &id_musica_remover);

    int encontrado = 0;

    // Procura a música para remover no álbum
    for (int i = 0; i < albuns[id_album].total_musicas; i++) {
        if (albuns[id_album].id_musica[i] == id_musica_remover) {
            encontrado = 1;

            // Remove a música do álbum deslocando as músicas seguintes para trás
            for (int j = i; j < albuns[id_album].total_musicas - 1; j++) {
                albuns[id_album].id_musica[j] = albuns[id_album].id_musica[j + 1];
            }

            albuns[id_album].total_musicas--;

            printf("Musica com Id %d removida do Album %s.\n", id_musica_remover, albuns[id_album].nome);
            getchar();
            break;
        }
    }

    // Caso a música não tenha sido encontrada no álbum
    if (!encontrado) {
        printf("A musica com Id %d nao foi encontrada dentro do album.\n", id_musica_remover);
    }
}

//Função que apaga um album
void apagar_album(Album albuns[], int *total_albuns) {
    if (*total_albuns == 0) {
        printf("Nenhum album foi criado ainda.\n");
        return;
    }

    int id_album;
    printf("Escolha o id do album para apagar: \n");
    for (int i = 0; i < *total_albuns; i++) {
        printf("Id: %d - Album: %s\n", i, albuns[i].nome);
    }

    scanf("%d", &id_album);
    getchar();

    if (id_album < 0 || id_album >= *total_albuns) {
        printf("Album com id %d não existe.\n", id_album);
        return;
    }

    // t desloca os albuns para uma posicao para tras
    for (int i = id_album; i < *total_albuns - 1; i++) {
        albuns[i] = albuns[i + 1];
    }

    (*total_albuns)--;  // reduz o total de albuns

    printf("O Album com id %d apagado com sucesso.\n", id_album);
}

//Função que lista os albuns criados
void listar_albuns(Album albuns[], int total_albuns) {
    if (total_albuns == 0) {
        printf("Nenhum album foi criado ainda.\n");
        return;
    }

    printf("Lista de albuns:\n"); 
    for (int i = 0; i < total_albuns; i++) {
        printf("Id: %d - Album: %s\n", i, albuns[i].nome);
    }
}


//Função que elimina uma música do arquivo de registro
void eliminar(Musica lista_musicas[], int *total) {
    int id = 0;
    int musica_encontrada = 0;
    
    printf("Digite o ID da musica que deseja eliminar: \n");
    scanf("%d", &id);
    
    for (int i = 0; i < *total; i++) { // Verifique todas as músicas do programa
        if(lista_musicas[i].id == id) {
            musica_encontrada = 1; // mostra que a musica com o id que inserimos existe e foi encontrado e tambem serve como condição de paragem para que o prog não faça o if(musica_encontrada == 0){
            
            // após a musica ser removida, desloca a música a seguir da música removida para o id da musica removida
            for (int j = i; j < *total - 1; j++) { 
                lista_musicas[j] = lista_musicas[j + 1]; 
            }

            (*total)--; // para descer o número de musicas da lista de musicas
            printf("Musica com id %d foi removida com sucesso \n", id); // msg que a musica que o utilizador queira remover foi removido
            break;
        }
    }
    
    if(musica_encontrada == 0){ // caso a musica não for encontrada, ou seja, quando musica_encontrada for igual a zero, mostra msg que a musica que o utilizador quer remover não existe
        printf("A musica com id %d nao foi encontrada na lista de musicas.", id);
        return;
    }

    // Atualiza os IDs de todas as músicas para garantir que ficam sequenciais (1, 2, 3...)
    for (int i = 0; i < *total; i++) {
        lista_musicas[i].id = i + 1; // define um novo id para cada música com base na sua posição
    }

    //Cria um arquivo temporário e adiciona todas as músicas, com os novos IDs reorganizados
    FILE *f_temp = fopen("temp.txt", "w");
    if (f_temp == NULL) {
        printf("Erro ao criar arquivo temporario (temp.txt). \n");
        return;
    }

    for (int i = 0; i < *total; i++) {
        fprintf(f_temp, "Id da música: %d\n", lista_musicas[i].id);
        fprintf(f_temp, "Nome: %s\n", lista_musicas[i].nome);
        fprintf(f_temp, "Artista: %s\n", lista_musicas[i].artista);
        fprintf(f_temp, "Genero: %s\n", lista_musicas[i].genero);
        fprintf(f_temp, "Duracao: %ds\n", lista_musicas[i].duracao);
        fprintf(f_temp, "------------------------------------------------------ \n");
    }

    fclose(f_temp);

    //Remove o arquivo antigo desatualizado e renomeia o arquivo temporário para o nome antigo
    remove("arquivo_musicas.txt");
    rename("temp.txt", "arquivo_musicas.txt");
}



void carregar_musicas(Musica lista[], int *total) {
    FILE *f = fopen("arquivo_musicas.txt", "r");
    if (f == NULL) {
        printf("Arquivo de musicas não encontrado.\n");
        return;
    }

    char linha[256];
    Musica m;

    while (fgets(linha, sizeof(linha), f) != NULL) {
        if (sscanf(linha, "Id da musica: %d", &m.id) != 1)
            continue;

        if (fgets(m.nome, TAM_NOME, f) == NULL) break;
        m.nome[strcspn(m.nome, "\n")] = 0;

        if (fgets(m.artista, TAM_ARTISTA, f) == NULL) break;
        m.artista[strcspn(m.artista, "\n")] = 0;

        if (fgets(m.genero, TAM_GENERO, f) == NULL) break;
        m.genero[strcspn(m.genero, "\n")] = 0;

        if (fgets(linha, sizeof(linha), f) == NULL) break;
        sscanf(linha, "Duração: %ds", &m.duracao);

        fgets(linha, sizeof(linha), f);

        lista[*total] = m;
        (*total)++;

        if (*total >= MAX_MUSICAS)
            break;
    }

    fclose(f);
    printf("%d musicas carregadas do arquivo.\n", *total);
}

//Função que edita as informações da música escolhida pelo utilizador
void editar(Musica lista[], int total) {
    int id, encontrada = 0;

    printf("Digite o ID da musica que deseja editar: \n");
    scanf("%d", &id);
    getchar(); // limpar buffer

    //Pede ao utilizador as informações novas da música
    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            encontrada = 1;

            do{
                printf("Novo nome da musica: ");
                fgets(lista[i].nome, TAM_NOME, stdin);
                lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;

                verificar_entrada = validarDados(lista[i].nome);

                if(verificar_entrada == 1){
                    printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
                }
            }while(verificar_entrada == 1);
            
            do{
                printf("Novo nome do artista: ");
                fgets(lista[i].nome, TAM_ARTISTA, stdin);
                lista[i].artista[strcspn(lista[i].artista, "\n")] = 0;

                verificar_entrada = validarDados(lista[i].artista);

                if(verificar_entrada == 1){
                    printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
                }
            }while(verificar_entrada == 1);

            do{
                printf("Novo genero: ");
                fgets(lista[i].genero, TAM_NOME, stdin);
                lista[i].genero[strcspn(lista[i].genero, "\n")] = 0;

                verificar_entrada = validarDados(lista[i].genero);

                if(verificar_entrada == 1){
                    printf("Entrada invalida!\n\nPressione Enter para continuar...\n");
                }
            }while(verificar_entrada == 1);

            printf("Nova duracao (em segundos): ");
            scanf("%d", &lista[i].duracao);
            getchar(); // limpar buffer

            printf("Musica com ID %d editada com sucesso!\n", id);
            break;
        }
    }

    if (!encontrada) {
        printf("Musica com ID %d nao foi encontrada.\n", id);
        return;
    }

    //Cria um arquivo temporário e adiciona todas as músicas, menos a que foi escolhida pelo utilizador para ser eliminada
    FILE *f_temp = fopen("temp.txt", "w");
    if (f_temp == NULL) {
        printf("Erro ao criar arquivo temporario (temp.txt). \n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f_temp, "Id da musica: %d\n", lista[i].id);
        fprintf(f_temp, "Nome: %s", lista[i].nome);
        fprintf(f_temp, "Artista: %s", lista[i].artista);
        fprintf(f_temp, "Genero: %s", lista[i].genero);
        fprintf(f_temp, "Duracao: %ds\n", lista[i].duracao);
        fprintf(f_temp, "------------------------------------------------------\n");
    }

    fclose(f_temp);

    //Remove o arquivo antigo desatualizado e renomeia o arquivo temporário para o nome antigo
    remove("arquivo_musicas.txt");
    rename("temp.txt", "arquivo_musicas.txt");
}

//Função que lista as músicas e simula a ação de tocar determinada música
void tocar_musica(Musica lista[], int total){
    int opcao;

    do {
        system("cls");
        printf("\n+===============================+\n");
        printf("|           Tocar Musica        |\n");
        printf("+===============================+\n");
        printf("| 1. Listar musicas             |\n");
        printf("| 2. Tocar musica por ID        |\n");
        printf("| 0. Voltar                     |\n");
        printf("+===============================+\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // limpa o buffer

        switch (opcao) {
            case 1:
                if (total == 0) {
                    printf("Nenhuma musica cadastrada.\n");
                } else {
                    printf("\n+========= Lista de Musicas =========+\n");
            //Lista  todas as músicas
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
                getchar(); // limpa buffer

                int encontrada = 0;

                //Simulação de tocar música
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

// Função que salva as estatísticas das músicas em um arquivo
void salvar_estatisticas(Musica lista[], int total) {
    if (total == 0) return;

    FILE *f = fopen("arquivo_estatisticas.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar/abrir o arquivo de estatisticas.\n");
        return;
    }

    int total_musicas = total;
    int tempo_total_ouvido = 0;
    int mais_ouvida_index = 0;
    int artistas_unicos = 0;
    char artistas[MAX_MUSICAS][TAM_ARTISTA];

    for (int i = 0; i < total; i++) {
        tempo_total_ouvido += lista[i].duracao * lista[i].vezes_ouvida;

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
            strcpy(artistas[artistas_unicos++], lista[i].artista);
        }
    }
    // Escreve as estatísticas no arquivo
    fprintf(f, "Total de musicas: %d\n", total_musicas);
    fprintf(f, "Musica mais ouvida: %s (%d vezes)\n", lista[mais_ouvida_index].nome, lista[mais_ouvida_index].vezes_ouvida);
    fprintf(f, "Tempo total ouvindo musicas: %d segundos\n", tempo_total_ouvido);
    fprintf(f, "Numero de artistas diferentes: %d\n", artistas_unicos);

    fclose(f);
}

void mostrar_estatisticas() {
    FILE *f = fopen("arquivo_estatisticas.txt", "r");
    if (f == NULL) {
        printf("Nenhuma estatistica disponivel ainda. Toque musicas para gerar estatisticas.\n");
        return;
    }

    char linha[256];

    printf("\n===== Estatisticas Salvas =====\n");

    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }

    fclose(f);

    printf("\nPressione Enter para continuar...");
    getchar();
}


