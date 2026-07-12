# SLOC (Source Lines Of Code)

## Introduction

Contador de linhas de código, com interface command-line.
Processa e conta linhas em branco, linhas de comentário, linhas de documentação doxygen e linhas de código.

## Author(s)

- Álvaro Barbosa Filho
  [alvaro.filho.111@ufrn.edu.br]
- Luiz Renan da Silva Pontes
  [luizrenanpontes@gmail.com]

## Problems found or limitations

O maior problema que o projeto _teve_, de fato, foi a parte do parser, que era um pouco confuso como iriámos administrar os estados e os inputs dentro do programa, além da formulação da lógica por trás dele. Assim como corrigir os casos especiais que o código tinha, envolvendo os blocos de comentário.

## Grading

Preencha os itens que você implementou, indicando qual a nota esperada para cada item.

| Item                                                | Valor máximo | Valor esperado |
| --------------------------------------------------- | :----------: | :------------: |
| Read one or multiple source file                    |      10      |       10       |
| Read a list of files from a directory               |      10      |       10       |
| Read a list of files recursively from a directory   |      8       |       8        |
| Show help as requested `-h`                         |      4       |       4        |
| Treat error situations                              |      10      |       10       |
| Show correct number of blank lines                  |      5       |       5        |
| Show correct number of comment lines                |      10      |       10       |
| Show correct number of doc comment lines            |      10      |       10       |
| Show correct number of code lines                   |      10      |       10       |
| Show correct number of total lines                  |      5       |       5        |
| Show the type of source file                        |      5       |       5        |
| Show percentages as requested                       |      10      |       10       |
| Show consolidation at the bottom of a table         |      5       |       5        |
| Table is formatted as requested                     |      8       |       8        |
| The project contains at least one struct or classes |      5       |       5        |
| Overall evaluation of the program                   |      5       |       5        |

## Compiling and Running

1. Crie uma pasta no diretório do projeto, chamada `build`, caso não tenha;
2. No terminal e dentro da pasta `build`, execute `cmake ..` para configurar sua pasta `build`;
3. Fora da pasta build, execute `cmake --build build`, após compilar, entre na pasta `build` e execute o programa usando `./sloc` dentro do terminal;
