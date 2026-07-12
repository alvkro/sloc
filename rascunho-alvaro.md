### 👨‍💻 Frente B: O Parser e a Máquina de Estados (Lógica de Contagem)
*Foco:* Abrir cada arquivo válido e varrer linha por linha, lidando com todos os "casos especiais" malucos do compilador.
 * *1. Estrutura de Dados Base:*
   * Definir a struct/class FileInfo para armazenar filename, type, n_blank, n_comments, n_docblocks, n_loc, e n_lines. [X]
 * *2. Lógica de Contagem Simples:*
   * Ler o arquivo linha por linha contando o total de linhas. [x]
   * Identificar linhas em branco, linhas de código simples (SLOC) e comentários de linha única (//). [x]
   * Identificar Doxygen comments (/// ou /**) separando-os dos comentários normais. [x]
   -> Criar uma big função para exatamente isso e criar mini funções para //, doxygen, /* */ e etc.
 * *3. Blocos Multilinhas e Conflitos (O Desafio Real):*
   * Implementar o rastreamento de bloco de comentário (/* ... */). [x] (?)
   * Tratar o *Caso Especial 1: Ignorar // dentro de / / e ignorar / dentro de //.
   * Tratar o *Caso Especial 3*: Linhas que contém tanto código quanto comentário (ex: int x = 0; // init) devem contar como 1 SLOC e 1 Comentário. [x]
 * *4. Tratamento de *String Literals:**
   * Tratar o *Caso Especial 2*: Ignorar marcações de comentário que estejam dentro de aspas duplas " ". [x]
   * Tratar o *Caso Especial 5: Lidar com strings multilinhas (concatenação implícita, \ no final da linha e *raw strings R"(...)") considerando todas como SLOC. [x]
### 🤝 Tarefas Conjuntas (A Integração)
 * Unir a lista de arquivos gerada pela *Frente A* com a função de parsing da *Frente B*.
 * Implementar a lógica de *Ordenação (Sorting)* da lista de FileInfo baseada nos argumentos da CLI (ascendente/descendente por diferentes campos).
 * Revisar o código em busca de vazamentos de memória (Valgrind) e preencher o arquivo author.md.
 * (Extra) Adicionar suporte a outras linguagens de programação, garantindo até 10 pontos extras.
Como o parser (Frente B) costuma exigir um pouco mais de cuidado com a lógica condicional ("estou dentro de uma string?", "estou dentro de um bloco de comentário?"), e a infraestrutura (Frente A) exige ler bastante a documentação da STL (<filesystem> e manipulação de std::cout), qual das frentes te atrai mais para começarmos a rascunhar no Neovim?