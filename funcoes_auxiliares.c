#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares.h"
#include <stdio.h>

void adicionar(Musica lista_musicas[ ], int *total) { //  total armazena a lista de músicas disponíveis

    if (*total >= MAX_MUSICAS) {
        printf("A lista de músicas está cheia.\n");
        return;
    }

Musica musica_nova; // crie uma 2 que contem todos os atributos de Musica2

musica_nova.id = *total + 1;  // adiciona o id da musica na lista de musicas (total) 

printf(“Insira o nome da musica: \n”);
fgets(musica_nova.nome, TAM_NOME, stdin);

 printf("Insira o nome do artista da musica: \n");
fgets(musica_nova.artista, TAM_ARTISTA, stdin);

printf("Insira o gênero musical da música que está a inserir: \n");
fgets(musica_nova.genero, TAM_GENERO, stdin);

printf("Insira a duração da música (em segundos): \n");
scanf("%d", &musica_nova.duracao);

lista_musicas[*total] = musica_nova;
(*total)++;

FILE *f = fopen("arquivo_musicas.txt", "a");
if (f == NULL) {
    printf("Erro ao abrir o arquivo “arquivo_musicas.txt” ");
    return;
}

fprintf(f, "Id da música: %d\n", musica_nova.id);
fprintf(f, "Nome: %s", musica_nova.nome);
fprintf(f, "Artista: %s", musica_nova.artista);
fprintf(f, "Gênero: %s", musica_nova.genero);
fprintf(f, "Duração: %ds\n", musica_nova.duracao);
fprintf(f, "------------------------------------------------------\n");

fclose(f); 
printf("Música adicionada na lista de músicas e gravada no arquivo.\n");
}


void listar(){
    
}

void criar_album(Album albuns[], int *total_albuns) {
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
}

