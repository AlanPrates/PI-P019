/*
Sistema de gestão de conjuntos de itens
Etapa 1: Individual
Crie uma classe ItemSet (conjunto de itens)
Dentro desta classe crie um vector de String É onde serão armazenados os
itens (cada item é um String)
IMPORTANTE! Não pode haver repetição de itens num mesmo conjunto!
Crie o método inserir(string s) que insere o item s no conjunto, caso ele não exista.
Crie o método excluir(string s) que exclui o item s do conjunto, caso ele exista.
Crie uma função main() para facilitar seus testes 
*/

#include <iostream>
#include <vector>

using namespace std;

class ItemSet
{
private:
    vector<string> itens;
public:
    void inserir(const string& item){
        for(const string& existeItem : itens){
            if(existeItem == item){
                cout << "O item '" << item << "' já existe no conjunto.\n";
                return;
            }
        }
        itens.push_back(item);
        cout << "Item '" << item << "' foi inserido no conjunto.\n";
    }

    void excluir(const string& item) {
        for (size_t i = 0; i < itens.size(); ++i) {
            if (itens[i] == item) {
                itens.erase(itens.begin() + i);
                cout << "Item '" << item << "' foi excluído do conjunto.\n";
                return;
            }
        }

        cout << "O item '" << item << "' não existe no conjunto e não pode ser excluído.\n";
    }

    void exibirItens() const {
        cout << "Itens no conjunto:\n";
        for (const string& item : itens) {
            cout << item << "\n";
        }
    }
};

int main() {
    ItemSet conjunto;
    char opcao;
    string item;

    do {
        cout << "Escolha uma opção:\n";
        cout << "1. Inserir item\n";
        cout << "2. Excluir item\n";
        cout << "3. Exibir itens\n";
        cout << "4. Sair\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case '1':
                cout << "Digite o item a ser inserido: ";
                cin >> item;
                conjunto.inserir(item);
                break;
            case '2':
                cout << "Digite o item a ser excluído: ";
                cin >> item;
                conjunto.excluir(item);
                break;
            case '3':
                conjunto.exibirItens();
                break;
            case '4':
                cout << "Programa Encerrado!.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != '4');

    return 0;
}