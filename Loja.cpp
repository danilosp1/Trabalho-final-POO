#include "Loja.h"
#include "Notebook.h"
#include "Periferico.h"
#include <fstream>

using namespace std;

namespace loja{
    Loja::Loja(const string fileName) : fileName(fileName){
        leitura();
    };

    Loja::~Loja(){};

    void Loja::escrita(){
        int tipo, tam;
        string nome, marca, descricao, cor, processador;
        int preco, qtd, tamanho, tamTela, bateria;
        bool temBateria, temBluetooth, temRGB;
        Periferico *p;
        Notebook *n;
        
        ofstream file(this->fileName, ios::binary);
        
        if(!file.is_open()){
            cout << "Erro ao abrir arquivo." << endl;
            return;
        }

        for(long unsigned int i = 0; i < DB.size(); i++){
            {
                // Escrita do tipo
                tipo = DB[i]->getCategoria();
                file.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));

                // Escrita do tamanho do nome do nome
                nome = DB[i]->getNome();
                tam = nome.size();
                file.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                file.write(reinterpret_cast<char *>(&nome[0]), tam);

                // Escrita do tamanho da descrição e da descrição
                descricao = DB[i]->getDescricao();
                tam = descricao.size();
                file.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                file.write(reinterpret_cast<char *>(&descricao[0]), tam);

                // Escrita do tamanho da cor e da cor
                cor = DB[i]->getCor();
                tam = cor.size();
                file.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                file.write(reinterpret_cast<char *>(&cor[0]), tam);

                // Escrita do preço
                preco = DB[i]->getPreco();
                file.write(reinterpret_cast<char *>(&preco), sizeof(preco));

                // Escrita da quantidade
                qtd = DB[i]->getQtd();
                file.write(reinterpret_cast<char *>(&qtd), sizeof(qtd));

                switch (tipo)
                {
                case 1:
                    // Armazenar um Periferico
                    p = dynamic_cast<Periferico *>(DB[i]);

                    // Escrita do tamanho
                    tamanho = p->getTamanho();
                    file.write(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));

                    // Escrita se tem bateria
                    temBateria = p->getTemBateria();
                    file.write(reinterpret_cast<char *>(&temBateria), sizeof(temBateria));

                    // Escrita se tem conexão bluetooth
                    temBluetooth = p->getTemBluetooth();
                    file.write(reinterpret_cast<char *>(&temBluetooth), sizeof(temBluetooth));

                    // Escrita se tem iluminação RGB
                    temRGB = p->getTemRGB();
                    file.write(reinterpret_cast<char *>(&temRGB), sizeof(temRGB));

                    break;
                case 2:
                    // Armazenar um Notebook
                    n = dynamic_cast<Notebook *>(DB[i]);

                    // Escrita do tamanho da tela
                    tamTela = n->getTamTela();
                    file.write(reinterpret_cast<char *>(&tamTela), sizeof(tamTela));

                    // Escrita da quantidade de bateria
                    bateria = n->getBateria();
                    file.write(reinterpret_cast<char *>(&bateria), sizeof(bateria));

                    // Escrita do tamanho e do nome do processador
                    processador = n->getProcessador();
                    tam = processador.size();
                    file.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                    file.write(reinterpret_cast<char *>(&processador[0]), tam);

                    break;
                }
            }
        }
        
        file.close();
    }

    void Loja::leitura(){
        int tipo, tam;
        string nome, marca, descricao, cor, processador;
        int preco, qtd, tamanho, tamTela, bateria;
        bool temBateria, temBluetooth, temRGB;

        ifstream file(this->fileName, ios::binary);

        if(file.is_open()){
            // Leitura do tipo
            file.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

            
            while(file.good()){
                // Leitura do tamanho do nome e do nome
                file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                nome.resize(tam);
                file.read(reinterpret_cast<char *>(&nome[0]), sizeof(tam));

                // Leitura do tamanho da descrição e da descrição
                file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                descricao.resize(tam);
                file.read(reinterpret_cast<char *>(&descricao[0]), tam);

                // Leitura do tamanho da cor e da cor
                file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                cor.resize(tam);
                file.read(reinterpret_cast<char *>(&cor[0]), tam);

                // Leitura do preço
                file.read(reinterpret_cast<char *>(&preco), sizeof(preco));

                // Leitura da quantidade
                file.read(reinterpret_cast<char *>(&qtd), sizeof(qtd));
                
                switch (tipo)
                {
                case 1:
                    // Leitura de um Periferico

                    // Escrita do tamanho
                    file.read(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));

                    // Escrita se tem bateria
                    file.read(reinterpret_cast<char *>(&temBateria), sizeof(temBateria));

                    // Escrita se tem conexão bluetooth
                    file.read(reinterpret_cast<char *>(&temBluetooth), sizeof(temBluetooth));

                    // Escrita se tem iluminação RGB
                    file.read(reinterpret_cast<char *>(&temRGB), sizeof(temRGB));

                    DB.push_back(new Periferico(nome, marca, descricao, cor, preco, qtd, tamanho, temBateria, temBluetooth, temRGB));

                    break;
                case 2:
                    // Leitura de um Notebook

                    // Escrita do tamanho da tela
                    file.read(reinterpret_cast<char *>(&tamTela), sizeof(tamTela));

                    // Escrita da quantidade de bateria
                    file.read(reinterpret_cast<char *>(&bateria), sizeof(bateria));

                    // Escrita do tamanho e do nome do processador
                    file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    processador.resize(tam);
                    file.read(reinterpret_cast<char *>(&processador[0]), tam);

                    DB.push_back(new Notebook(nome, marca, descricao, cor, preco, qtd, tamTela, bateria, processador));

                    break;
                }

                file.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
            }
        }

        file.close();
    };

    void Loja::menu(Produto* Produto){
        cout << "--------------------------------------------" << endl;
        cout << "Produto a ser editado: \n" << endl;
        Produto->imprimir();
        cout << "\nSelecione uma opção (digite o número): " << endl;
        cout << "1. Editar descrição do produto" << endl;
        cout << "2. Editar preço do produto" << endl;
        cout << "3. Editar quantidade do produto em estoque" << endl;
        cout << "4. Sair da edição" << endl;
        cout << "--------------------------------------------" << endl;
    };

    bool Loja::adicionarProduto(Produto* Produto){
        DB.push_back(Produto);
        escrita();  
        
        return true;
    };

    bool Loja::editarProduto(string nome){
        int pos = -1;
        int opt = 0;
        string descricao;
        int preco, qtd;

        for(long unsigned int i = 0; i < DB.size(); i++){
            if(DB[i]->getNome() == nome) pos = i;
        }
        if(pos == -1){
            cout << "O produto não existe no banco de dados." << endl;
            return false;
        }

        while(opt != 4){
            menu(DB[pos]);
            cin >> opt;

            switch (opt)
            {
            case 1:
                cout << "Digite a nova descrição: " << endl;
                cin >> descricao;
                DB[pos]->setDescricao(descricao);
                break;
            case 2:
                cout << "Digite o novo preco: " << endl;
                cin >> preco;
                DB[pos]->setPreco(preco);
                break;

            case 3:
                cout << "Digite a nova quantidade em estoque: " << endl;
                cin >> qtd;
                DB[pos]->setQtd(qtd);
                break;

            case 4:
                cout << "Edição de produto finalizada..." << endl;
                break;
            
            default:
                cout << "Entrada inválida." << endl;
                break;
            }
        }

        escrita();
        return true;
    };

    bool Loja::removerProduto(string nome){
        int pos = -1;
        for(long unsigned int i = 0; i < DB.size(); i++){
            if(DB[i]->getNome() == nome) pos = i;
        }

        if(pos != -1) DB.erase(DB.begin() + pos);

        escrita();
        return (pos != -1);
    };

    void Loja::listarProdutos(){
        cout << "Listagem de Produtos: " << endl;
        for(long unsigned int i = 0; i < DB.size(); i++){
            DB[i]->imprimir();
        }
    };
}