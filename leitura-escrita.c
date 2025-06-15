#include <stdio.h>
#include <stdlib.h>


//leitura
void leitura(const char *nome){
	FILE *arquivo = fopen(nome, "r");
	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo\n");
		return;
	
	}

	char conteudo[200];
	printf("%s:\n", nome);
	while (fgets(conteudo, sizeof(conteudo), arquivo));
	printf("%s",conteudo);
}

	

//Escrever
void escrever(const char *nome){
	FILE *arquivo = fopen(nome, "w");
	if(arquivo == NULL){
		printf("Não foi possivel abrir o arquivo");
		return;
}

	fprintf(arquivo, "%s");
}


	// int main(){
	//	escrever("musica");
	// leitura("musica");
	// return 0;
	// }
	
	
