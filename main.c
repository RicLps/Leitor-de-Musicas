#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

printf("\n+===============================+\n");
printf("| A Tocar: %s\n", m.titulo);
printf("| Artista: %s\n", m.artista);
printf("| Duração: %d segundos\n", m.duracao);
printf("+===============================+\n");
printf("| p - Parar\n");
printf("+===============================+\n");

printf("\n+===============================+\n");
printf("|      Leitor de Música em C    |\n");
printf("+===============================+\n");
printf("| 1. Adicionar música           |\n");
printf("| 2. Listar músicas             |\n");
printf("| 3. Tocar música               |\n");
printf("| 4. Sair                       |\n");
printf("+===============================+\n");
printf("Escolha uma opção: ");
scanf("%d", &opcao);
