#include "Loja.h"
#include "Notebook.h"
#include "Periferico.h"
#include <fstream>

using namespace std;

namespace loja{
    Loja::Loja(const string fileName) : fileName(fileName){
        // Leitura inicial do arquivo
        leitura();
    };

    Loja::~Loja(){};

    void Loja::escrita(){
        int tipo, tam;
        string nome, marca, descricao, cor, processador;
        int qtd, tamTela, bateria;
        double preco, tamanho;
        bool temBateria, temBluetooth, temRGB;
        Periferico *p;
        Notebook *n;
        
        ofstream file(this->fileName, ios::binary);
        
        // Verificação se o arquivo foi aberto/criado corretamente
        if(!file.is_open()){
            cout << "Erro ao abrir arquivo." << endl;
            return;
        }

        // Percorre o vector para escrita dos Produtos no arquivo de saida
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

                // Escrita do tamanho da marca e da marca
                marca = DB[i]->getMarca();
                tam = marca.size();
                file.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                file.write(reinterpret_cast<char *>(&marca[0]), tam);

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
                case 0:
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
        int qtd, tamTela, bateria;
        double preco, tamanho;
        bool temBateria, temBluetooth, temRGB;

        ifstream file(this->fileName, ios::binary);

        if(file.is_open()){
            // Leitura do tipo
            file.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

            
            while(file.good()){
                // Leitura do tamanho do nome e do nome
                file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                nome.resize(tam);
                file.read(reinterpret_cast<char *>(&nome[0]), tam);

                // Leitura do tamanho da descrição e da descrição
                file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                descricao.resize(tam);
                file.read(reinterpret_cast<char *>(&descricao[0]), tam);

                // Leitura do tamanho da marca e da marca
                file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                marca.resize(tam);
                file.read(reinterpret_cast<char *>(&marca[0]), tam);

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

                    // Adicionar novo periférico ao DB
                    DB.push_back(new Periferico(nome, marca, descricao, cor, preco, qtd, tamanho, temBateria, temBluetooth, temRGB));

                    break;
                case 0:
                    // Leitura de um Notebook

                    // Escrita do tamanho da tela
                    file.read(reinterpret_cast<char *>(&tamTela), sizeof(tamTela));

                    // Escrita da quantidade de bateria
                    file.read(reinterpret_cast<char *>(&bateria), sizeof(bateria));

                    // Escrita do tamanho e do nome do processador
                    file.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    processador.resize(tam);
                    file.read(reinterpret_cast<char *>(&processador[0]), tam);

                    // Adicionar novo notebook ao DB
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
        cout << "> ";
    };

    bool Loja::adicionarProduto(int tipo){
        string nome, marca, descricao, cor, processador, aux1, aux2;
        char hasBatery, hasBluetooth, hasRGB;
        int qtd, tamTela, bateria;
        double preco, tamanho;
        bool temBateria, temBluetooth, temRGB;

        Produto* produto;

        // Leitura do nome
        cin.ignore();
        cout << "Nome (o nome deve ser único para cada produto): " << endl;
        getline(cin, nome);
        cout << "\n";

        // Verificar se já existe um produto com o nome de entrada
        for(long unsigned int i = 0; i < DB.size(); i++){
            aux1 = DB[i]->getNome();
            aux2 = nome;
            for (auto & c: aux1) c = toupper(c);
            for (auto & c: aux2) c = toupper(c);
            if(aux1 == aux2){
                cout << "Já existe um produto com esse nome no sistema." << endl;
                return false;
            }
        }

        // Leitura da marca
        cout << "Marca: " << endl;
        getline(cin, marca);
        cout << "\n";

        // Leitura da descrição
        cout << "Descrição: " << endl;
        getline(cin, descricao);
        cout << "\n";

        // Leitura da cor
        cout << "Cor: " << endl;
        getline(cin, cor);
        cout << "\n";

        // Leitura da quantidade em estoque
        cout << "Quantidade em estoque: " << endl;
        cin >> qtd;
        cout << "\n";

        // Leitura do preço
        cout << "Preço: " << endl;
        cin >> preco;
        cout << "\n";

        if(tipo == 1){ // Periférico
            // Leitura do tamanho
            cout << "Tamanho (centimetros): " << endl;
            cin >> tamanho;
            cout << "\n";

            // Leitura se possui bateria
            do
            {
                cout << "Possui bateria? [s] ou [n]" << endl;
                cin >> hasBatery;
                cout << "\n";
                (toupper(hasBatery) == 'S') ? temBateria = true : temBateria = false;
            } while (toupper(hasBatery) != 'S' && toupper(hasBatery) != 'N');

            // Leitura se possui conexão Bluetooth
            do
            {
                cout << "Possui conexão Bluetooth? [s] ou [n]" << endl;
                cin >> hasBluetooth;
                cout << "\n";
                (toupper(hasBluetooth) == 'S') ? temBluetooth = true : temBluetooth = false;
            } while (toupper(hasBluetooth) != 'S' && toupper(hasBluetooth) != 'N');

            // Leitura se possui iluminação RGB
            do
            {
                cout << "Possui iluminação RGB? [s] ou [n]" << endl;
                cin >> hasRGB;
                cout << "\n";
                (toupper(hasRGB) == 'S') ? temRGB = true : temRGB = false;
            } while (toupper(hasRGB) != 'S' && toupper(hasRGB) != 'N');
            
            produto = new Periferico(nome, marca, descricao, cor, preco, qtd, tamanho, temBateria, temBluetooth, temRGB);
            
        } else { // Notebook
            // Leitura do tamanho da tela
            cout << "Tamanho da tela (número inteiro de polegadas):" << endl;
            cin >> tamTela;
            cout << "\n";

            // Leitura do tamanho da bateria
            cout << "Tamanho bateria (número inteiro em mAh):" << endl;
            cin >> bateria;
            cout << "\n";

            // Leitura do nome do processador
            cin.ignore();
            cout << "Processador: " << endl;
            getline(cin, processador);
            cout << "\n";

            produto = new Notebook(nome, marca, descricao, cor, preco, qtd, tamTela, bateria, processador);
        }

        DB.push_back(produto);

        escrita();  
        
        return true;
    };

    bool Loja::editarProduto(string nome){
        int pos = -1;
        int opt, qtd;
        string descricao, aux1, aux2;
        double preco;

        // Verificar qual o produto a ser editado
        for(long unsigned int i = 0; i < DB.size(); i++){
            aux1 = DB[i]->getNome();
            aux2 = nome;
            for (auto & c: aux1) c = toupper(c);
            for (auto & c: aux2) c = toupper(c);
            if(aux1 == aux2) pos = i;
        }

        // Sai do método caso não exista o produto em questão
        if(pos == -1){
            cout << "O produto não existe no banco de dados." << endl;
            return false;
        }

        do
        {
            menu(DB[pos]);
            cin >> opt;

            switch (opt)
            {
            case 1:
                // Edição da descrição
                cout << "Digite a nova descrição: " << endl;
                cin >> descricao;
                DB[pos]->setDescricao(descricao);
                break;

            case 2:
                // Edição do preço
                cout << "Digite o novo preco: " << endl;
                cin >> preco;
                DB[pos]->setPreco(preco);
                break;

            case 3:
                // Edição da quantidade em estoque
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

        } while (opt != 4);

        escrita();
        return true;
    };

    bool Loja::removerProduto(string nome){
        int pos = -1;
        string aux1, aux2;

        // Buscar posição do produto em questão e verificar se existe
        for(long unsigned int i = 0; i < DB.size(); i++){
            aux1 = DB[i]->getNome();
            aux2 = nome;
            for (auto & c: aux1) c = toupper(c);
            for (auto & c: aux2) c = toupper(c);
            if(aux1 == aux2) pos = i;
        }

        // Deletar produto
        if(pos != -1) DB.erase(DB.begin() + pos);

        // Reescrita no arquivo binário
        escrita();
        return (pos != -1);
    };

    void Loja::listarProdutos(){
        // Releitura do arquivo persistente
        DB.clear();
        leitura();

        // Verifica se existem produtos cadastrados
        if(DB.size() == 0){
            cout << "Não existem produtos no sistema." << endl;
            return;
        }

        cout << "Listagem de Produtos: " << endl;
        // Faz a impressão de cada um dos produtos existentes
        for(long unsigned int i = 0; i < DB.size(); i++){
            DB[i]->imprimir();
        }
    };

    int Loja::opcao(){
        int i;
        cout << "--------------------------------------------" << endl;
        cout << "Selecione uma opção (digite o número)" << endl;
        cout << "1 - Listar estoque" << endl;
        cout << "2 - Adicionar Notebook" << endl;
        cout << "3 - Adicionar Periférico" << endl;
        cout << "4 - Atualizar um produto no estoque (por nome)" << endl;
        cout << "5 - Remover um produto (por nome)" << endl;
        cout << "6 - Encerrar programa" << endl;

        cout << "> ";
        cin >> i;
        return i;
    }
}