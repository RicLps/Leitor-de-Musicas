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
        printf("A lista de músicas está cheia.\n");
        return;
    }

Musica musica_nova; // crie uma 2 que contem todos os atributos de Musica2

musica_nova.id = *total + 1;  // adiciona o id da musica na lista de musicas (total) 

//Pede os dados da música ao utilizador
printf("Insira o nome da musica: \n");
fgets(musica_nova.nome, TAM_NOME, stdin);

printf("Insira o nome do artista da musica: \n");
fgets(musica_nova.artista, TAM_ARTISTA, stdin);

printf("Insira o gênero musical da música que está a inserir: \n");
fgets(musica_nova.genero, TAM_GENERO, stdin);

printf("Insira a duração da música (em segundos): \n");
scanf("%d", &musica_nova.duracao);

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
fprintf(f, "Id da música: %d\n", musica_nova.id);
fprintf(f, "Nome: %s", musica_nova.nome);
fprintf(f, "Artista: %s", musica_nova.artista);
fprintf(f, "Gênero: %s", musica_nova.genero);
fprintf(f, "Duração: %ds\n", musica_nova.duracao);
fprintf(f, "------------------------------------------------------\n");

//Fecha o arquivo
fclose(f); 
printf("Música adicionada na lista de músicas e gravada no arquivo.\n");
}




/*void listar(Musica lista[], int total) {
    if (total == 0) {
        printf("Nenhuma música cadastrada.\n");
        return;
    }

    printf("\n+========= Lista de Músicas =========+\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d\n", lista[i].id);
        printf("Nome: %s", lista[i].nome);
        printf("Artista: %s", lista[i].artista);
        printf("Gênero: %s", lista[i].genero);
        printf("Duração: %d segundos\n", lista[i].duracao);
        printf("-------------------------------------\n");
    }
}
*/



//Função que cria um novo album
void criar_album(Album albuns[], int *total_albuns) {

//Verifica se ultrapassou-se o número máximo de albuns
if (*total_albuns >= MAX_ALBUNS) {
        printf("Não é possível criar álbum porque você excedeu o limite de criação de albuns.\n");
        return;
}
 Album novo_album;
 novo_album.total_musicas = 0; // define o total_musicas = 0, já que não adicionamos músicas ainda.

printf("Insira o nome do álbum á se criar (máximo 20 caracteres): \n");
    fgets(novo_album.nome, NOME_ALBUM, stdin);

    albuns[*total_albuns] = novo_album; // vai adicionar um o álbum que criei na próxima posição livre do array albums.
    (*total_albuns)++; // aumenta o valor do *total_albuns para mostrar que um album foi criado dentor do *total_albuns

printf("Álbum %s foi criado com sucesso. Lembre-se que um álbum aceita somente 100 músicas! \n", novo_album.nome);
}
void adicionar_musica_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Ainda não foi criado nenhum álbum. \n");
        return;
    }

    int escolha_album;
    printf("Escolha o álbum para adicionar músicas:\n");
    for (int i = 0; i < total_albuns; i++) {
       printf("Id: %d - Álbum: %s\n", i, albuns[i].nome);  // nessa, indica o id do álbum e nome do álbum com o albuns[i].nome onde o albuns é um vetor de struct Albuns, que foi declarado em funcoes.auxiliares.h 
    }

    printf("Insira o id do álbum: \n");
    scanf("%d", &escolha_album);

    if (escolha_album < 0 || escolha_album >= total_albuns) { // verifique se o album escolhido pelo usuario esta entre 0 e o numero de albuns criados.
        printf("O álbum com id %d não existe.\n", escolha_album);
        return;
    }

//Verifica se o album já atingiu o limite máximo de músicas
    if (albuns[escolha_album].total_musicas >= MAX_MUSICAS_ALBUM) {
        printf("O álbum já atingiu o limite máximo de 100 músicas.\n");
        return;
    }

 printf("\ Músicas disponíveis: \n");
    for(int i = 0; i < total_musicas; i++) { // aqui vai listar todas as musicas ja adicionadas no sistema.
       printf("Id: %d - Nome: %s", lista_musicas[i].id, lista_musicas[i].nome);
    }

  int id_musica;
    printf("Insira o Id da música que deseja adicionar ao álbum: \n");
    scanf("%d", &id_musica);

 int pesquisa_musica = 0; // definimos uma variavel que vai nos indicar se o id da musica que o utilizador inseriu acima existe
    for (int i = 0; i < total_musicas; i++) { // percorre todos as musicas do sistema 
        if (lista_musicas[i].id == id_musica) { // e vê se o id inserido pelo utilizador existe.
            pesquisa_musica = 1; // serve como condição de paragem do for
albuns[escolha_album].id_musica[albuns[escolha_album].total_musicas] = id_musica; // aqui adiciona o Id da música selecionada pelo usuario na próxima posição livre da lista de musicas do álbum escolhido tambem pelo usuario

 albuns[escolha_album].total_musicas++; // aumenta o total de musicas  que o album escolhido tem

printf("A música com Id %d foi adicionada ao álbum %s.\n", id_musica, albuns[escolha_album].nome);
            break;
        }
    }
}

void listar_musicas_album(Album albuns[], int total_albuns, Musica lista_musicas[], int total_musicas) {
    if (total_albuns == 0) {
        printf("Nenhum álbum foi criado. \n");
        return;
    }

    int id_album;
    printf("Escolha o id do álbum: \n");
    for (int i = 0; i < total_albuns; i++) {
        printf("Id: %d - Álbum: %s", i, albuns[i].nome);
    }
  scanf("%d", &id_album);


    if (id_album < 0 || id_album >= total_albuns) {
        printf("Álbum inválido. \n");
        return;
}

if (albuns[id_album].total_musicas == 0) {
    printf("O álbum não tem nenhuma músicas. \n");
    return;
}

printf("Músicas do álbum %s: \n", albuns[id_album].nome);
for (int i = 0; i < albuns[id_album].total_musicas; i++) { //  Veja todas as músicas dentro do álbum escolhido pelo utilizador
    for (int j = 0; j < total_musicas; j++) { // Veja todas as musicas do sistema no total_musicas
        if (lista_musicas[j].id == albuns[id_album].id_musica[i]) { // compara o ID da música do álbum com os Ides da lista total de musicas do sistema
            printf("Id: %d - Nome: %s", lista_musicas[j].id, lista_musicas[j].nome); // caso a condição for verdadeira, imprime as o id e o nome da musica encontrada
            break;
        }
      }
   }
}

//Função que remove uma música de um album
void remover_musica_album(Album albuns[], int total_albuns) {
    //Verifica se há algum album
    if (total_albuns == 0) {
        printf("Nenhum álbum foi criado ainda.\n");
        return;
    }

    int id_album;
    printf("Escolha o id do álbum para remover a música: \n");
    for (int i = 0; i < total_albuns; i++) {
        printf("Id: %d - Álbum: %s", i, albuns[i].nome);
    }

    scanf("%d", &id_album);
    getchar(); 

    //Verifica se o id isnserido está correto
    if (id_album < 0 || id_album >= total_albuns) {
        printf("Album com id %d não existe.\n", id_album);
        return;
    }

    //Verifica se há músicas no album selecionado
    if (albuns[id_album].total_musicas == 0) {
        printf("O álbum não tem nenhuma música ainda.\n");
        return;
    }

    printf("Músicas do álbum %s:\n", albuns[id_album].nome);
    for (int i = 0; i < albuns[id_album].total_musicas; i++) {
        printf("Posiçao %d - Id da música: %d\n", i, albuns[id_album].id_musica[i]); // posição indica a ordem da música dentro do album
    }

    int id_musica_remover;
    printf("Insira o id da música que quer remover do álbum: \n");
    scanf("%d", &id_musica_remover);

    int encontrado = 0;

    for (int i = 0; i < albuns[id_album].total_musicas; i++) {
        if (albuns[id_album].id_musica[i] == id_musica_remover) {
            encontrado = 1;

        
            for (int j = i; j < albuns[id_album].total_musicas - 1; j++) {
                albuns[id_album].id_musica[j] = albuns[id_album].id_musica[j + 1];
            }

            albuns[id_album].total_musicas--;

            printf("Música com Id %d removida do álbum %s. \n", id_musica_remover, albuns[id_album].nome);
            break;
        }
    }

    //Caso a música não tenha sido encontrada no album
    if (!encontrado) {
        printf("A música com Id %d não foi encontrada dentro do álbum. \n", id_musica_remover);
    }
  }
}




//Função que elimina uma música do arquivo de registro
void eliminar(Musica lista_musicas[], int *total) {
      int id = 0;
      int musica_encontrada = 0;
      
      printf("Digite o ID da música que deseja eliminar: \n");
      scanf("%d", &id);
      
      for (int i = 0; i < *total; i++) { // Verifique todas as músicas do programa
            if (lista_musicas[i].id == id) {
                  musica_encontrada = 1; // mostra que a musica com o id que inserimos existe e foi encontrado e tambem serve como condição de paragem para que o prog não faça o if(musica_encontrada == 0){
            
                 
                  for (int j = i; j < *total - 1; j++) { 
                        lista_musicas[j] = lista_musicas[j + 1]; // após a musica ser removida, desloca o musica a seguir da música removida para o id da musica removida
                  }
            
                  (*total)--; // para descer o número de musicas da lista de musicas
                  printf("Música com id %d foi removida com sucesso \n", id); // msg que a musica que o utilizador queira remover foi removido
                  break;
            }
      }
      
      if(musica_encontrada == 0){ // caso a musica não for encontrada, ou seja, quando musica_encontrada for igual a zero, mostra msg que a musica que o utilizador quer remover não existe
            printf("A música com id %d não foi encontrada na lista de músicas.", id);
      }   

//Cria um arquivo temporário e adiciona todas as músicas, menos a que foi escolhida pelo utilizador para ser eliminada
FILE *f_temp = fopen("temp.txt", "w");
    if (f_temp == NULL) {
        printf("Erro ao criar arquivo temporário (temp.txt). \n");
        return;
    }

    for (int i = 0; i < *total; i++) {
        fprintf(f_temp, "Id da música: %d\n", lista_musicas[i].id);
        fprintf(f_temp, "Nome: %s", lista_musicas[i].nome);
        fprintf(f_temp, "Artista: %s", lista_musicas[i].artista);
        fprintf(f_temp, "Gênero: %s", lista_musicas[i].genero);
        fprintf(f_temp, "Duração: %ds\n", lista_musicas[i].duracao);
        fprintf(f_temp, "------------------------------------------------------ \n");
    }
    fclose(f_temp);

    //Remove o arquivo antigo desatualizado e renomeia o arquivo temporário para o nome antigo
    remove("arquivo_musicas.txt");
    rename("temp.txt", "arquivo_musicas.txt");
}




/*void tocar_musica(Musica lista[], int total) {
    if (total == 0) {
        printf("Nenhuma música disponível para tocar.\n");
        return;
    }

    int id_tocar;
    printf("Digite o ID da música que deseja tocar: ");
    scanf("%d", &id_tocar);

    for (int i = 0; i < total; i++) {
        if (lista[i].id == id_tocar) {
            printf("\n A tocar...\n");
            printf("Nome: %s", lista[i].nome);
            printf("Artista: %s", lista[i].artista);
            printf("Duração: %d segundos\n", lista[i].duracao);
            return;
        }
    }

    printf("Música com ID %d não encontrada.\n", id_tocar);
}
*/

//Função que edita as informações da música escolhida pelo utilizador
void editar(Musica lista[], int total) {
    int id, encontrada = 0;

    printf("Digite o ID da música que deseja editar: \n");
    scanf("%d", &id);
    getchar(); // limpar buffer

    //Pede ao utilizador as informações novas da música
    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            encontrada = 1;

            printf("Novo nome da música: ");
            fgets(lista[i].nome, TAM_NOME, stdin);

            printf("Novo artista: ");
            fgets(lista[i].artista, TAM_ARTISTA, stdin);

            printf("Nova duração (em segundos): ");
            scanf("%d", &lista[i].duracao);
            getchar(); // limpar buffer

            printf("Música com ID %d editada com sucesso!\n", id);
            break;
        }
    }

    if (!encontrada) {
        printf("Música com ID %d não foi encontrada.\n", id);
        return;
    }

    //Cria um arquivo temporário e adiciona todas as músicas, menos a que foi escolhida pelo utilizador para ser eliminada
    FILE *f_temp = fopen("temp.txt", "w");
    if (f_temp == NULL) {
        printf("Erro ao criar arquivo temporário (temp.txt). \n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f_temp, "Id da música: %d\n", lista[i].id);
        fprintf(f_temp, "Nome: %s", lista[i].nome);
        fprintf(f_temp, "Artista: %s", lista[i].artista);
        fprintf(f_temp, "Gênero: %s", lista[i].genero);
        fprintf(f_temp, "Duração: %ds\n", lista[i].duracao);
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
        printf("|           Tocar Música        |\n");
        printf("+===============================+\n");
        printf("| 1. Listar músicas             |\n");
        printf("| 2. Tocar música por ID        |\n");
        printf("| 0. Voltar                     |\n");
        printf("+===============================+\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // limpa o buffer

        switch (opcao) {
            case 1:
                if (total == 0) {
                    printf("Nenhuma música cadastrada.\n");
                } else {
                    printf("\n+========= Lista de Músicas =========+\n");
            //Lista  todas as músicas
            for (int i = 0; i < total; i++) {
                        printf("ID: %d\n", lista[i].id);
                        printf("Nome: %s", lista[i].nome);
                        printf("Artista: %s", lista[i].artista);
                        printf("Gênero: %s", lista[i].genero);
                        printf("Duração: %d segundos\n", lista[i].duracao);
                        printf("-------------------------------------\n");
                    }
                }
                break;

            case 2: {
                if (total == 0) {
                    printf("Nenhuma música disponível para tocar.\n");
                    break;
                }

                int id_tocar;
                printf("Digite o ID da música que deseja tocar: ");
                scanf("%d", &id_tocar);
                getchar(); // limpa buffer

                int encontrada = 0;

                //Simulação de tocar música
                for (int i = 0; i < total; i++) {
                    if (lista[i].id == id_tocar) {
                        printf("\nA tocar...\n");
                        printf("Nome: %s", lista[i].nome);
                        printf("Artista: %s", lista[i].artista);
                        printf("Duração: %d segundos\n\n", lista[i].duracao);

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
                    printf("Música com ID %d não encontrada.\n", id_tocar);
                break;
            }

            case 0:
                break;

            default:
                printf("Opção inválida.\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);
}
