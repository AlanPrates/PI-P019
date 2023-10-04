#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ItemSet {
private:
    vector<string> items;

public:
    void inserir(string s) {
        // Verifica se o item já existe no conjunto
        for (const string& item : items) {
            if (item == s) {
                cout << "O item já existe no conjunto." << endl;
                return;
            }
        }

        // Se não existe, insere o item
        items.push_back(s);
        cout << "Item inserido com sucesso." << endl;
    }

    void excluir(string s) {
        // Procura o item no conjunto
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == s) {
                items.erase(it);
                cout << "Item excluído com sucesso." << endl;
                return;
            }
        }

        cout << "O item não existe no conjunto." << endl;
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("item1");
    conjunto.inserir("item2");
    conjunto.inserir("item3");
    conjunto.inserir("item2");  // Tentando inserir um item já existente

    conjunto.excluir("item2");
    conjunto.excluir("item4");  // Tentando excluir um item que não existe

    return 0;
}
