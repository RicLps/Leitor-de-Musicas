#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarDados(const char *entrada) {
    int len = strlen(entrada);

    if(len < 3 || len >= TAM_NOME) {
        printf("Atencao: O nome deve ter entre 3 a %d caracteres\n", TAM_NOME-1);
        return 0;
    }

    for (int i = 0; i < len; i++) {
        char c = entrada[i];
     
        if(!isalnum(c) && c != ' ' && c != '_' && c != '-' ) {
            printf("Atencao: Nome invalido, use somente letras, numeros, espaco, underscore e hifens.\n");
            return 0;
        }
    }

    if (strspn(entrada, " ") == len) {
        printf("Atencao: Insira algum caracter valido\n");
        return 0;
    }

    return 1;
}
