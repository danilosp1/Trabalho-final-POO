#include <iostream>
#include "Produto.h"
#include "Notebook.h"
#include "Periferico.h"
#include "Loja.h"

using namespace std;
using namespace loja;

void teste(){
    int op;
    bool sucesso;
    string nome;

    Loja novaLoja("registro.dat");

    do {
        op = Loja::opcao();
        cout << "\n";
        switch (op)
        {
        case 1:
            novaLoja.listarProdutos();
            break;
        case 2:
            sucesso = novaLoja.adicionarProduto(0);
            cout << "Adição " << (sucesso ? "bem sucessida." : "falhou.") << endl;
            break;
        case 3:
            sucesso = novaLoja.adicionarProduto(1);
            cout << "Adição " << (sucesso ? "bem sucessida." : "falhou.") << endl;
            break;
        case 4:
            cin.ignore();
            cout << "Digite o nome do produto a ser editado: " << endl;
            getline(cin, nome);
            sucesso = novaLoja.editarProduto(nome);
            cout << "Edição " << (sucesso ? "bem sucessida." : "falhou.") << endl;
            break;
        case 5:
            cin.ignore();
            cout << "Digite o nome do produto a ser removido: " << endl;
            getline(cin, nome);
            sucesso = novaLoja.removerProduto(nome);
            cout << "Remoção " << (sucesso ? "bem sucessida." : "falhou.") << endl;
            break;
        case 6:
            cout << "Programa finalizado com sucesso!" << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }
        cin.ignore();
    } while (op != 6);
}

int main(){
    teste();

    return 0;
}