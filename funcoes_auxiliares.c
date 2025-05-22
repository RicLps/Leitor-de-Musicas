#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>

void adicionar(Musica lista_musicas[], int *total) { //  o *total armazena a lista de músicas disponíveis;

      if (*total >= MAX_MUSICAS) { // verifica se a lista de musicas está cheia;
              printf("A lista de músicas está cheia.\n");
              return;
      }

      Musica musica_nova; // crie uma "Variavel" musica_ nova (dentro do struct Musica) que contem todos os atributos de Musica por exemplo id;
      
      musica_nova.id = *total + 1;  // adiciona o id da musica na lista de musicas (*total) 
      
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

      f = fopen("arquivo_musicas.txt", "w") as file;


      fclose(file);
      printf("Música adicionada na lista de músicas com sucesso! \n");
      
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

printf("Álbum ‘%s’ foi criado com sucesso. Lembre-se que um álbum aceita somente 100 músicas! \n", novo_album.nome);
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
            printf(“A música com id %d não foi encontrada na lista de músicas.”, id);
      }   
}

