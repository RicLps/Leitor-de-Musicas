#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>

void leitura(const char *nome) {
    if (nome == NULL) {
        printf("Nome de arquivo inválido.\n");
        return;
    }

    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nome);
        return;
    }

    char conteudo[256];
    printf("\nConteúdo do arquivo %s:\n", nome);
    while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) {
        printf("%s", conteudo);
    }
    fclose(arquivo);
}

void escrever(const char *nome, const char *conteudo) {
    if (nome == NULL || conteudo == NULL) {
        printf("Parâmetros inválidos.\n");
        return;
    }

    FILE *arquivo = fopen(nome, "w");
    if (arquivo == NULL) {
        printf("Não foi possível criar o arquivo %s\n", nome);
        return;
    }

    if (fprintf(arquivo, "%s", conteudo) < 0) {
        printf("Erro ao escrever no arquivo\n");
    }
    fclose(arquivo);
}
