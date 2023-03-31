#include "Produto.h"

namespace loja{
    Produto::Produto(string nome, string marca, string descricao, string cor, double preco, int qtd) : nome(nome), marca(marca), descricao(descricao), cor(cor), preco(preco), qtd(qtd){};
    Produto::~Produto(){};

    string Produto::getNome() const {
        return this->nome;
    };
    string Produto::getMarca() const{
        return this->marca;
    };
    string Produto::getDescricao() const {
        return this->descricao;
    };
    string Produto::getCor() const{
        return this->cor;
    };
    double Produto::getPreco() const{
        return this->preco;
    };
    int Produto::getQtd() const{
        return this->qtd;
    };


    void Produto::setNome(string nome) {
        this->nome = nome;
    };
    void Produto::setMarca(string marca){
        this->marca = marca;
    };
    void Produto::setDescricao(string descricao) {
        this->descricao = descricao;
    };
    void Produto::setCor(string cor){
        this->cor = cor;
    };
    void Produto::setPreco(double preco){
        this->preco = preco;
    };
    void Produto::setQtd(int qtd){
        this->qtd = qtd;
    };
}