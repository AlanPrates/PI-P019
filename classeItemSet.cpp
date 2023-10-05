/*Crie uma classe ItemSet (conjunto de itens) 
Dentro desta classe crie um vector de String É onde serão armazenados os 
itens (cada item é um String) 
IMPORTANTE! Não pode haver repetição de itens num mesmo conjunto! 
Crie o método inserir(string s) que insere o item s no conjunto, caso ele não exista. 
Crie o método excluir(string s) que exclui o item s do conjunto, caso ele exista. 
Crie uma função main() para facilitar seus testes*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ItemSet {
private:
    vector<string> items;

public:
    // Insere o item s no conjunto, caso ele não exista.
    void inserir(const string& s) {
        if (find(items.begin(), items.end(), s) == items.end()) {
            items.push_back(s);
            cout << "Item \"" << s << "\" inserido no conjunto." << endl;
        } else {
            cout << "Item \"" << s << "\" já existe no conjunto." << endl;
        }
    }

    void excluir(const string& s) {
        auto it = find(items.begin(), items.end(), s);
        if (it != items.end()) {
            items.erase(it);
            cout << "Item \"" << s << "\" excluído do conjunto." << endl;
        } else {
            cout << "Item \"" << s << "\" não encontrado no conjunto." << endl;
        }
    }

    // Exibe todos os itens no conjunto.
    void exibirItens() const {
        cout << "Itens no conjunto:" << endl;
        for (const string& item : items) {
            cout << "- " << item << endl;
        }
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("Maçã");
    conjunto.inserir("Banana");
    conjunto.inserir("Maçã"); 

    conjunto.excluir("Banana");
    conjunto.excluir("Pêra"); 

    conjunto.inserir("Laranja");

    conjunto.exibirItens();

    return 0;
}
