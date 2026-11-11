
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class StockInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : stock insuffisant pour effectuer cette vente !";
    }
};

class Produit {
private:
    string nom;
    int stock;

public:
    
    Produit(string n, int s) {
        nom = n;
        stock = s;
    }

    void vendre(int quantite) {
        if (quantite > stock) {
            throw StockInsuffisantException();
        }

        if (quantite <= 0) {
            throw invalid_argument("La quantite doit etre positive !");
        }

        stock = stock - quantite;

        cout << "Vente reussie de " << quantite
             << " " << nom << endl;

        cout << "Stock restant : " << stock << endl;
    }
};

int main() {

    Produit p("Ordinateur", 10);

    try {
        p.vendre(3);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << endl;

   
    try {
        p.vendre(8);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << endl;

    try {
        p.vendre(5);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
