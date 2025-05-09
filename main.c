#include "funcoes_auxiliares.h"
#include <stdio.h>

int main() {
    Musica lista[MAX_MUSICAS];
    int total = 0;
    int opcao, id;

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
        getchar(); // limpar o '\n'

        switch (opcao) {
            case 1: adicionar(lista, &total); break;
            case 2: listar(lista, total); break;
            case 3:
                printf("ID da música: "); scanf("%d", &id); getchar();
                tocar_musica(lista, total, id); break;
            case 4:
                printf("ID da música: "); scanf("%d", &id); getchar();
                editar(lista, total, id); break;
            case 5:
                printf("ID da música: "); scanf("%d", &id); getchar();
                eliminar(lista, &total, id); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
