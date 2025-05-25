#include "funcoes_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>

//Qntd máxima de músicas a serem armazenadas
#define MAX_MUSICAS 100

int main() {
    //Array que armazena todas as musicas inseridas
    Musica lista[MAX_MUSICAS];
    int total = 0;
    int opcao, subopcao;

    //Menu principal
    do {
        system("cls");
        printf("\n+===============================+\n");
        printf("|      Leitor de Música em C    |\n");
        printf("+===============================+\n");
        printf("| 1. Gerenciar Músicas          |\n");
        printf("| 2. Tocar Música               |\n");
        printf("| 3. Gerenciar Albuns           |\n");
        printf("| 0. Sair                       |\n");
        printf("+===============================+\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        //Sistema de sub-menus para cada uma das opções acima
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
                    printf("| 4. Editar música              |\n");
                    printf("| 0. Voltar                     |\n");
                    printf("+===============================+\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &subopcao);

                    //Opções que chamam as diferentes funções do sistema
                    switch (subopcao) {
                        case 1: adicionar(lista, &total); break;    
                        case 2: listar(lista, total); break;
                        case 3: eliminar(lista, &total); break; 
                        case 4: editar(lista, total); break;
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
            //Sistema de sub-menus que lidam com a manipulação de albuns
            case 3:
             do {
                    system("cls");
                    printf("\n+===============================+\n");
                    printf("|         Gerenciar Álbuns      |\n");
                    printf("+===============================+\n");
                    printf("| 1. Criar álbum                |\n");
                    printf("| 2. Adicionar música ao álbum  |\n");
                    printf("| 3. Listar músicas de álbum    |\n");
                    printf("| 4. Remover música do álbum    |\n");
                    printf("| 0. Voltar                     |\n");
                    printf("+===============================+\n");
                    printf("Escolha uma opção: \n");
                    scanf("%d", &subopcao);
                    getchar();
                         //Switch case que apresenta as funções relacionadas a manipulação de albuns
                        switch (subopcao) {
                        case 1: criar_album(albuns, &total_albuns); break;
                        case 2: adicionar_musica_album(albuns, total_albuns, lista, total); break;
                        case 3: listar_musicas_album(albuns, total_albuns, lista, total); break;
                        case 4: remover_musica_album(albuns, total_albuns); break;
                        case 0: break;
                        default: printf("Opção inválida.\n"); break;
                    }
//Volta para o menu anterior
 if (subopcao != 0) {
                        printf("\nPressione Enter para continuar...");
                        getchar();
                    }

                } while (subopcao != 0);
                break;


            case 0:
                printf("Saindo...\n");
                break;
            //Verifica se a opção inserida for inválida
            default:
                printf("Opção inválida.\n");
                printf("Pressione Enter para continuar...");
                getchar(); getchar();
                break;
        }

    } while (opcao != 0);

    return 0;
}
