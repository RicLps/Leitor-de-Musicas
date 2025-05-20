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

printf("Música adicionada na lista de músicas com sucesso! \n");
}


void listar(){
    
}

void eliminar(){
   
}

void tocar_musica(){
    
}

