# Leitor-de-Musicas
Programa em C que simula um leitor de música, em que o utilizador possa adicionar, listar, editar e eliminar os itens (músicas) armazenados e, por fim, simular o ato de tocar a música selecionada pelo utilizador

## Funcionalidades
### Músicas 
- Adicionar, editar e eliminar músicas
- Listar músicas registradas
- Estatísticas de músicas (quantidade total, mais tocadas, etc.)

### Álbuns
- Criar e apagar álbuns
- Adicionar/remover músicas em álbuns
- Listar músicas de um álbum
- Listar todos os álbuns criados

### Reprodução
- Listar músicas disponíveis
- Tocar música por ID (simulação)

## Estrutura de Arquivos
LEITOR-DE-MUSICAS
├── arquivo_estatisticas.txt        # Armazena dados estatísticos
├── arquivo_musicas.txt             # Armazena todas as músicas registradas
├── funcoes_auxiliares.c            # Funções de apoio
├── funcoes_auxiliares.h            # Cabeçalho das funções auxiliares
├── leitura-escrita.c               # Operações de leitura e gravação em ficheiros
├── main.c                          # Ponto de entrada do programa (menu principal)
├── validar_dados.c                 # Validações de entrada do utilizador 
├── programa.exe                    # Executável gerado após compilação 
├── README.md                       # Ficheiro de documentação 
