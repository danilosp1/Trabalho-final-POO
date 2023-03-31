#ifndef LOJA_H
#define LOJA_H

#include <iostream>
#include <string>
#include <vector>
#include "Produto.h"
    
using namespace std;

namespace loja{
    class Loja{
        public:
            Loja(const string fileName);
            virtual ~Loja();

            bool adicionarProduto(int tipo);
            bool editarProduto(string nome);
            bool removerProduto(string nome);
            void listarProdutos();
            static int opcao();

        private:
            void escrita();
            void leitura();
            void menu(Produto* Produto);

            const string fileName;
            vector<Produto*> DB;
    };
}

#endif