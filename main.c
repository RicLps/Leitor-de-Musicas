#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <stlib.h>


    
int main() {
    Musica lista[MAX_MUSICAS];
    int total = 0;

    do {
        printf("\n+===============================+\n");
        printf("|      Leitor de Música em C    |\n");
        printf("+===============================+\n");
        printf("| 1. Adicionar música           |\n");
        printf("| 2. Listar músicas             |\n");
        printf("| 3. Tocar música               |\n");
        printf("| 4. Editar música              |\n");
        printf("| 5. Eliminar música            |\n");
        printf("| 0. Sair                       |\n");
        printf("+===============================+\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionar(); break;
            case 2: listar(); break;
            case 3: tocar_musica(); break;
            case 4: editar(); break;
            case 5: eliminar(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
