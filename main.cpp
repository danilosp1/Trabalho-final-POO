#include <iostream>
#include "Produto.h"
#include "Notebook.h"
#include "Periferico.h"
#include "Loja.h"

using namespace std;
using namespace loja;

void teste(){
    Produto *f1 = new Notebook("Aspire 5", "Acer", "Grande, bonito e legal", "Azul", 10000, 10, 15, 2500, "Intel core I5");
    Produto *f2 = new Notebook("Aspire 3", "Acer", "Grande, bonito e legal", "Cinza", 14000, 2, 15, 2500, "Intel core I3");

    Loja listagem("Arquivo.dat");
    listagem.adicionarProduto(f1);
    listagem.adicionarProduto(f2);
    listagem.listarProdutos();

    delete f1;
    delete f2;
}

int main(){
    teste();

    return 0;
}