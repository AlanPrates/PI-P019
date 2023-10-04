#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ItemSet {
private:
    vector<string> items;  // Vetor de strings para armazenar os itens.

public:
    ItemSet() {}  // Construtor padrão.

    ItemSet(const ItemSet& other) : items(other.items) {}  // Construtor de cópia.

    void inserir(string s) {
        for (const string& item : items) {
            if (item == s) {
                cout << "O item já existe no conjunto." << endl;
                return;
            }
        }
        items.push_back(s);  // Adiciona o item ao vetor.
        cout << "Item inserido com sucesso." << endl;
    }

    void excluir(string s) {
        auto it = find(items.begin(), items.end(), s);
        if (it != items.end()) {
            items.erase(it);  // Remove o item do vetor.
            cout << "Item excluído com sucesso." << endl;
        } else {
            cout << "O item não existe no conjunto." << endl;
        }
    }

    ItemSet& operator=(const ItemSet& other) {
        if (this == &other)
            return *this;

        items = other.items;  // Atribui os itens do outro conjunto a este.
        return *this;
    }

    ItemSet operator+(const ItemSet& other) const {
        ItemSet result(*this);  // Cria um novo conjunto a partir deste.
        for (const string& item : other.items) {
            result.inserir(item);  // Insere os itens do outro conjunto neste.
        }
        return result;
    }

    ItemSet operator*(const ItemSet& other) const {
        ItemSet result;
        for (const string& item : items) {
            if (other.contem(item)) {
                result.inserir(item);
            }
        }
        return result;
    }

    ItemSet operator-(const ItemSet& other) const {
        ItemSet result(*this);
        for (const string& item : other.items) {
            result.excluir(item);
        }
        return result;
    }

    ItemSet operator^(const ItemSet& other) const {
        ItemSet result;
        for (const string& item : items) {
            if (!other.contem(item)) {
                result.inserir(item);
            }
        }
        for (const string& item : other.items) {
            if (!contem(item)) {
                result.inserir(item);
            }
        }
        return result;
    }

    bool operator==(const ItemSet& other) const {
        return is_permutation(items.begin(), items.end(), other.items.begin(), other.items.end());
    }

    bool contem(string s) const {
        return find(items.begin(), items.end(), s) != items.end();
    }

    void mostrarItens() const {
        for (const string& item : items) {
            cout << item << " ";
        }
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const ItemSet& conjunto) {
        for (const string& item : conjunto.items) {
            os << item << " ";
        }
        return os;
    }
};

int main() {
    ItemSet A, B, C;

    A.inserir("item1");
    A.inserir("item2");
    A.inserir("item3");

    B.inserir("item2");
    B.inserir("item3");
    B.inserir("item4");

    C.inserir("item3");
    C.inserir("item4");
    C.inserir("item5");

    ItemSet D = B + C;  // União de B e C
    cout << "D: " << D << endl;

    ItemSet E = B * C;  // Interseção entre B e C
    cout << "E: " << E << endl;

    ItemSet F = B - C;  // Diferença entre B e C
    cout << "F: " << F << endl;

    ItemSet G = B ^ C;  // Delta entre B e C
    cout << "G: " << G << endl;

    if (A == B) {
        cout << "A e B são iguais." << endl;
    } else {
        cout << "A e B não são iguais." << endl;
    }

    return 0;
}
