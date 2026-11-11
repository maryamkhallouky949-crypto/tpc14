
#include <iostream>
#include <exception>
using namespace std;

class MontantInvalideException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : le montant doit etre positif !";
    }
};

class SoldeInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : solde insuffisant pour effectuer le retrait !";
    }
};


class Compte {
private:
    int solde;

public:
   
    Compte(int s) {
        solde = s;
    }
    void deposer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException();
        }

        solde = solde + montant;

        cout << "Depot reussi : " << montant << " DH" << endl;
        cout << "Nouveau solde : " << solde << " DH" << endl;
    }


    void retirer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException();
        }

        if (montant > solde) {
            throw SoldeInsuffisantException();
        }

        solde = solde - montant;

        cout << "Retrait reussi : " << montant << " DH" << endl;
        cout << "Nouveau solde : " << solde << " DH" << endl;
    }
};


int main() {

    Compte c(1000);
    try {
        c.deposer(500);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    cout << endl;
    try {
        c.retirer(300);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    cout << endl;
    try {
        c.retirer(2000);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    cout << endl;

    try {
        c.deposer(-100);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    cout << endl;


    try {
        c.retirer(-50);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
