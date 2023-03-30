#include "Periferico.h"

namespace loja{
    Periferico::Periferico(string nome, string marca, string descricao, string cor, int preco, int qtd, int tamanho, bool temBateria, bool temBluetooth, bool temRGB) : Produto(nome, marca, descricao, cor, preco, qtd), tamanho(tamanho), temBateria(temBateria), temBluetooth(temBluetooth), temRGB(temRGB){};
    Periferico::~Periferico(){};
    
    int Periferico::getTamanho() const{
        return this->tamanho;
    };
    bool Periferico::getTemBateria() const{
        return this->temBateria;
    };
    bool Periferico::getTemBluetooth() const{
        return this->temBluetooth;
    };
    bool Periferico::getTemRGB() const{
        return this->temRGB;
    };

    void Periferico::setTamanho(int tamanho){
        this->tamanho = tamanho;
    };
    void Periferico::setTemBateria(bool temBateria){
        this->temBateria = temBateria;
    };
    void Periferico::setTemBluetooth(bool temBluetooth){
        this->temBluetooth = temBluetooth;
    };
    void Periferico::setTemRGB(bool temRGB){
        this->temRGB = temRGB;
    };

    int Periferico::getCategoria() const{
        return 1;
    }
    void Periferico::imprimir() const{
        cout << "--------------------------------------------" << endl;

        cout << "Nome do periférico: " << this->getNome() << endl;
        cout << "Marca do periférico: " << this->getMarca() << endl;
        cout << "Descrição: " << this->getDescricao() << endl;
        cout << "Quantidade em estoque: " << this->getQtd() << endl;
        cout << "Cor: " << this->getCor() << endl;
        cout << "Tamanho: " << this->tamanho << endl;
        cout << "Possui bateria?: " << this->temBateria << endl;
        cout << "Possui conexão bluetooth?: " << this->temBluetooth << endl;
        cout << "Possui iluminação RGB?: " << this->temRGB << endl;
        cout << "Preço: " << this->getPreco() << endl;
        
        cout << "--------------------------------------------" << endl;
    }
}