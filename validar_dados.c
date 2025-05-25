#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void validarDados(const char *entrada){
	int len = strlen(entrada);


	//Verificar a qntd de caracteres
	if(len < 3 || len > 50){
		printf("Atenção: O nome deve ter entre 3 a 50 caracteres");
		return 0;
	}

	//Para verificar os carcteres invalidos
	for (int i = 0; i < len; i++){
	     char c = entrada[i];
	 
	     if(!isalnum(c) && c != ' ' && c != '_' && c != '-' ){
	     	printf("Atenção: Nome inválido, use soente letras, números, espaço, underscore e hífens.");
	     	return 0;
	     }
		return 1;
	}

 	//Não deixar texto em branco / vazio
	if (strspn(entrada, " ") == len){
	   printf("Atenção: Insira algum caracter válido");
		return 0;
	}
	
}
