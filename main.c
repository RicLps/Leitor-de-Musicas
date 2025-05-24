#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_MUSICAS 100

int main() {
    Musica lista[MAX_MUSICAS];
    int total = 0;
    int opcao, subopcao;

    do {
        system("cls");
        printf("\n+===============================+\n");
        printf("|      Leitor de Música em C    |\n");
        printf("+===============================+\n");
        printf("| 1. Gerenciar Músicas          |\n");
        printf("| 2. Tocar Música               |\n");
        printf("| 0. Sair                       |\n");
        printf("+===============================+\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                do {
                    system("cls");
                    printf("\n+===============================+\n");
                    printf("|        Gerenciar Músicas      |\n");
                    printf("+===============================+\n");
                    printf("| 1. Adicionar música           |\n");
                    printf("| 2. Listar músicas             |\n");
                    printf("| 3. Eliminar música            |\n");
                    printf("| 0. Voltar                     |\n");
                    printf("+===============================+\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &subopcao);

                    switch (subopcao) {
                        case 1: adicionar(lista, total); break;
                        case 2: listar(lista, total); break;
                        case 3: total = eliminar(lista, total); break;
                        case 0: break;
                        default: printf("Opção inválida.\n"); break;
                    }

                    if (subopcao != 0) {
                        printf("\nPressione Enter para continuar...");
                        getchar(); getchar();  // Captura Enter
                    }

                } while (subopcao != 0);
                break;

            case 2:
                system("cls");
                tocar_musica(lista, total);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                printf("Pressione Enter para continuar...");
                getchar(); getchar();
                break;
        }

    } while (opcao != 0);

    return 0;
}
