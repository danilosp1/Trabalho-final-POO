#ifndef PERIFERICO_H
#define PERIFERICO_H

#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

namespace loja{
    class Periferico : public Produto{
        public:
            Periferico(string nome, string marca, string descricao, string cor, double preco, int qtd, double tamanho, bool temBateria, bool temBluetooth, bool temRGB);
            virtual ~Periferico();
            
            double getTamanho() const;
            bool getTemBateria() const;
            bool getTemBluetooth() const;
            bool getTemRGB() const;

            void setTamanho(double tamanho);
            void setTemBateria(bool temBateria);
            void setTemBluetooth(bool temBluetooth);
            void setTemRGB(bool temRGB);

            int getCategoria() const;
            void imprimir() const;
        private:
            double tamanho;
            bool temBateria;
            bool temBluetooth;
            bool temRGB;
    };
};

#endif