#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

namespace loja{
    class Notebook : public Produto{
        public:
            Notebook(string nome, string marca, string descricao, string cor, int preco,int qtd, int tamTela, int bateria, string processador);
            virtual ~Notebook();

            int getTamTela() const;
            int getBateria() const;
            string getProcessador() const;

            void setTamTela(int tamTela);
            void setBateria(int bateria);
            void setProcessador(string processador);

            int getCategoria() const;  
            void imprimir() const;      
        private:
            int tamTela;
            int bateria;
            string processador;
    };
};


#endif