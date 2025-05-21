#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarDados(const char *entrada){
	int len = strlen(entrada);


	//Verificar a qntd de caracteres
	if(len < 3 || len > 100){
		printf("Atenção: O nome deve ter entre 3 a 100 caracteres");
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

 	//Não deixar nome em branco / vazio
	if (strspn(entrada, " ") == len){
	   printf("Atenção: Insira algum caracter válido");
		return 0;
	}
	
}


int main(){
	char nome[100];

	printf("Digite o nome da música e o artista:\n");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';

	if(validarDados(nome)){
		}else{
			printf("\nPor Favor, Insira Um Nome Válido!\n");
		}
	
		return 0;
	}
