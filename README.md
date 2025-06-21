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
- ├── arquivo_estatisticas.txt      
- ├── arquivo_musicas.txt           
- ├── funcoes_auxiliares.c         
- ├── funcoes_auxiliares.h            
- ├── leitura-escrita.c              
- ├── main.c                        
- ├── validar_dados.c                 
- ├── programa.exe                    
- ├── README.md                       

## Como Executar no Visual Studio Code

### Pré-requisitos
- Visual Studio Code instalado no seu sistema;
- Compilador GCC (MinGW no Windows ou GCC no Linux/macOS)
- Extensão C/C++ da Microsoft (ou Code Runner)

  ### Passos:

1. **Abrir o projeto no VS Code**
   - `Ficheiro > Abrir Pasta` → Selecionar a pasta do projeto

2. **Abrir o terminal integrado**
   - `Terminal > Novo Terminal`
  
3. **Compilar o projeto**
  - No terminal, execute: `gcc main.c funcoes_auxiliares.c leitura-escrita.c validar_dados.c -o programa.exe`
