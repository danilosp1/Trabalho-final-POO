#include "Notebook.h"

namespace loja{
    Notebook::Notebook(string nome, string marca, string descricao, string cor, int preco, int qtd, int tamTela, int bateria , string processador) : Produto(nome, marca, descricao, cor, preco, qtd), tamTela(tamTela), bateria(bateria), processador(processador){};
    Notebook::~Notebook(){};

    int Notebook::getTamTela() const{
        return this->tamTela;
    };
    int Notebook::getBateria() const{
        return this->bateria;
    };
    string Notebook::getProcessador() const{
        return this->processador;
    };

    void Notebook::setTamTela(int tamTela){
        this->tamTela = tamTela;
    };
    void Notebook::setBateria(int bateria){
        this->bateria = bateria;
    };
    void Notebook::setProcessador(string processador){
        this->processador = processador;
    }
    int Notebook::getCategoria() const{
        return 2;
    };

    void Notebook::imprimir() const{
        cout << "--------------------------------------------" << endl;

        cout << "Nome do Notebook: " << this->getNome() << endl;
        cout << "Marca do Notebook: " << this->getMarca() << endl;
        cout << "Descrição: " << this->getDescricao() << endl;
        cout << "Quantidade em estoque: " << this->getQtd() << endl;
        cout << "Cor: " << this->getCor() << endl;
        cout << "Tamanho da tela (polegadas): " << this->tamTela << endl;
        cout << "Bateria (mAh): " << this->bateria << endl;
        cout << "Processador: " << this->processador << endl;
        cout << "Preço: " << this->getPreco() << endl;

        cout << "--------------------------------------------" << endl;
    }
}