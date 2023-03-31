Danilo da Silva Pinto - 811537 (Trabalho 4 de Programação Orientada a Objetos)

Como compilar: g++ Produto.cpp Periferico.cpp Notebook.cpp Loja.cpp main.cpp -o out

O sistema em questão representa uma loja que possui dois tipos de *Produtos*:
- Notebooks
- Periféricos eletrônicos

*Produto* é uma classe abstrata, enquanto *Notebook* e *Periferico* são classes concretas.

O sistema é feito de forma que os dados de classe existentes sejam armazenados em um arquivo binário,
que é carregado (ou criado, caso não exista) ao criar um novo objeto *Loja*. O objeto Loja recebe uma
string como parâmetro (nome do arquivo binário).

Na classe *Loja* existe um vector auxiliar DB, que representa o banco de dados. No construtor da classe,
DB é preenchido. Ao listar os produtos (método listarProdutos()), é carregado novamente os dados do arquivo
no vector. Adicionar produtos (método adicionarProduto(int tipo)) insere em DB o novo objeto, e carrega no
arquivo a lista atualizada. O mesmo acontece ao remover um produto (método removerProduto(string nome)).

Já existe um arquivo criado para testes (carregado com 2 notebooks e 1 periférico). O mesmo pode ser deletado
para criação de novos arquivos.

O arquivo "main.cpp" está feito para execução do programa de forma correta, chamando o método estático opcao(),
presente na classe *Loja*. Similar ao ensinado em sala de aula, ele faz um "menu" com diversas opções, para
facilitar a manipulação dos produtos armazenados, sendo possível listar o estoque, adicionar produtos de ambos
os tipo, atualizar um produto no estoque (por nome), remover um produto (por nome) e encerrar o programa.

Junto aos arquivos, também existem uma imagem com o Diagrama de Classes do trabalho.