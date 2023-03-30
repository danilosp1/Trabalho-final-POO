#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

using namespace std;

namespace loja{
    class Produto{
        public:
            Produto(string nome, string marca, string descricao, string cor, int preco, int qtd);
            virtual ~Produto();
            virtual int getCategoria() const = 0;
            virtual void imprimir() const = 0;
            
            string getNome() const;
            string getMarca() const;
            string getDescricao() const;
            string getCor() const;
            int getPreco() const;
            int getQtd() const;
            
            void setNome(string nome);
            void setMarca(string marca);
            void setDescricao(string descricao);
            void setCor(string cor);
            void setPreco(int preco);
            void setQtd(int qtd);
 
        private:
            string nome;
            string marca;
            string descricao;
            string cor;
            int preco;
            int qtd;
    };
}


#endif