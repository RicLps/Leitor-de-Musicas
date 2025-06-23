#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarDados(const char *entrada) {
    if (entrada == NULL) return 0;
    
    int len = strlen(entrada);
    if (len < 3 || len > 50) {
        printf("Atenção: O nome deve ter entre 3 a 50 caracteres\n");
        return 0;
    }

    for (int i = 0; i < len; i++) {
        char c = entrada[i];
        if (!isalnum(c) && c != ' ' && c != '_' && c != '-' && c != '\'') {
            printf("Atenção: Caractere inválido encontrado: '%c'\n", c);
            return 0;
        }
    }

    if (strspn(entrada, " ") == len) {
        printf("Atenção: O campo não pode ser vazio\n");
        return 0;
    }

    return 1;
}
