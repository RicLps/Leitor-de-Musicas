#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Musica lista[MAX_MUSICAS] = {0};
    Album albuns[MAX_ALBUNS] = {0};
    int total_albuns = 0;
    int total_musicas = 0;
    int opcao, subopcao;

    // Carrega músicas verificando erro
    printf("Carregando músicas...\n");
    carregar_musicas(lista, &total_musicas);
    if (total_musicas < 0) {
        printf("Erro ao carregar músicas. Continuando com lista vazia.\n");
        total_musicas = 0;
    }

    do {
        system("cls");
        printf("\n+===============================+\n");
        printf("|      Leitor de Musica em C    |\n");
        printf("+===============================+\n");
        printf("| 1. Gerenciar Musicas          |\n");
        printf("| 2. Tocar Musica               |\n");
        printf("| 3. Gerenciar Albuns           |\n");
        printf("| 0. Sair                       |\n");
        printf("+===============================+\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        switch (opcao) {
            case 1:
                do {
                    system("cls");
                    printf("\n+===============================+\n");
                    printf("|        Gerenciar Musicas      |\n");
                    printf("+===============================+\n");
                    printf("| 1. Adicionar musica           |\n");
                    printf("| 2. Listar musicas             |\n");
                    printf("| 3. Eliminar musica            |\n");
                    printf("| 4. Editar musica              |\n");
                    printf("| 5. Estatisticas das musicas   |\n");
                    printf("| 0. Voltar                     |\n");
                    printf("+===============================+\n");
                    printf("Escolha uma opcao: ");
                    
                    if (scanf("%d", &subopcao) != 1) {
                        printf("Entrada inválida.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    while(getchar() != '\n');

                    switch (subopcao) {
                        case 1: adicionar(lista, &total_musicas); break;    
                        case 2: listar(lista, total_musicas); break;
                        case 3: eliminar(lista, &total_musicas); break; 
                        case 4: editar(lista, total_musicas); break;
                        case 5: mostrar_estatisticas(lista, total_musicas); break;
                        case 0: break;
                        default: printf("Opção inválida.\n"); break;
                    }

                    if (subopcao != 0) {
                        printf("\nPressione Enter para continuar...");
                        while(getchar() != '\n');
                    }
                } while (subopcao != 0);
                break;

            case 2:
                tocar_musica(lista, total_musicas);
                break;

            case 3:
                do {
                    system("cls");
                    printf("\n+==================================+\n");
                    printf("|         Gerenciar Albuns         |\n");
                    printf("+==================================+\n");
                    printf("| 1. Criar Album                   |\n");
                    printf("| 2. Adicionar Musica a um Album   |\n");
                    printf("| 3. Listar Musicas de um Album    |\n");
                    printf("| 4. Remover Musica do Album       |\n");
                    printf("| 5. Apagar Album                  |\n");
                    printf("| 6. Listar Albuns Criados         |\n");
                    printf("| 0. Voltar                        |\n");
                    printf("+==================================+\n");
                    printf("Escolha uma opcao: ");
                    
                    if (scanf("%d", &subopcao) != 1) {
                        printf("Entrada inválida.\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    while(getchar() != '\n');

                    switch (subopcao) {
                        case 1: criar_album(albuns, &total_albuns); break;
                        case 2: adicionar_musica_album(albuns, total_albuns, lista, total_musicas); break;
                        case 3: listar_musicas_album(albuns, total_albuns, lista, total_musicas); break;
                        case 4: remover_musica_album(albuns, total_albuns, lista, total_musicas); break;
                        case 5: apagar_album(albuns, &total_albuns); break;
                        case 6: listar_albuns(albuns, total_albuns); break;
                        case 0: break;
                        default: printf("Opção inválida.\n"); break;
                    }

                    if (subopcao != 0) {
                        printf("\nPressione Enter para continuar...");
                        while(getchar() != '\n');
                    }
                } while (subopcao != 0);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                printf("Pressione Enter para continuar...");
                while(getchar() != '\n');
                break;
        }
    } while (opcao != 0);

    return 0;
}
