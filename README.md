# Leitor-de-Musicas
Este programa, desenvolvido em linguagem C, simula um leitor de músicas em ambiente de linha de comandos, permitindo ao utilizador gerir uma biblioteca de músicas (adicionar, listar, editar, eliminar) e simular a reprodução das musicas armazenadas.

## Funcionalidades
### Músicas 
- Adicionar, editar e eliminar músicas
- Listar músicas registradas
- Estatísticas de músicas

### Álbuns
- Criar e apagar álbuns
- Adicionar/remover músicas dos álbuns
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
- Visual Studio Code instalado no seu sistema
- Compilador GCC (MinGW no Windows ou GCC no Linux/macOS)
- Extensão C/C++ da Microsoft (ou Code Runner) 

  ### Passos:

1. **Abrir o projeto no VS Code**
   - `Ficheiro > Abrir Pasta` → Selecionar a pasta do projeto

2. **Abrir o terminal integrado**
   - `cntrl+shift+ç` ou `Terminal > Novo Terminal`
  
3. **Compilar o programa**
  - No terminal para compilar o comando, execute: `gcc main.c funcoes_auxiliares.c leitura-escrita.c validar_dados.c -o programa.exe`

4. **Executar o programa**
  - No mesmo terminal, execute: `.\programa.exe`
