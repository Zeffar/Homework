#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

class Pacient
{
protected:
    string nume;
    string prenume;
    int varsta;
    string adresa;
    unordered_map<string, int> afectiuni;
    string risc = "NU";

public:
    virtual ~Pacient() {}

    Pacient(int varsta)
    {
        this->varsta = varsta;
        afectiuni["colesterol (mg/dl)"] = 240;
        afectiuni["tensiune_arteriala"] = 139;
    }

    string getName()
    {
        return nume;
    }
    string getRisc()
    {
        return risc;
    }

    friend ostream &operator<<(ostream &os, const Pacient &pacient)
    {
        os << "Nume: " << pacient.nume << endl;
        os << "Prenume: " << pacient.prenume << endl;
        os << "Varsta: " << pacient.varsta << endl;
        os << "Adresa: " << pacient.adresa << endl;
        os << "Risc Cardiovascular: " << pacient.risc << endl;
        return os;
    }

    friend istream &operator>>(istream &is, Pacient &pacient)
    {
        cout << "Nume: ";
        is >> pacient.nume;
        cout << "Prenume: ";
        is >> pacient.prenume;
        cout << "Adresa: ";
        is >> pacient.adresa;

        cout << "Factori de risc:" << endl;
        for (const auto &factor : pacient.afectiuni)
        {
            cout << factor.first << ": ";
            int factorValue;
            is >> factorValue;
            if (factorValue > factor.second)
                if (pacient.risc == "DA")
                    pacient.risc = "RIDICAT";
                else if (pacient.risc == "NU")
                    pacient.risc = "DA";
        }
        return is;
    }
};

class PacientCopil : public Pacient
{
private:
    shared_ptr<Pacient> parinte[2];
    void findParents(vector<shared_ptr<Pacient>> pacienti)
    {
        for (const auto &pacient : pacienti)
        {
            if (pacient->getName() == this->nume)
            {
                if (parinte[0] == nullptr)
                    parinte[0] = move(pacient);

                else if (parinte[1] == nullptr)
                    parinte[1] = move(pacient);

            }
        }
    }

public:
    PacientCopil(int varsta, vector<shared_ptr<Pacient>> pacienti) : Pacient(varsta)
    {
        afectiuni["proteina_C (mg/L)"] = 6;
        findParents(pacienti);
        if (parinte[0] != nullptr && parinte[1] != nullptr && (parinte[0]->getRisc() == "RIDICAT" || parinte[1]->getRisc() == "RIDICAT"))
        {
            if (risc == "DA")
                risc = "RIDICAT";
            else if (risc == "NU")
                risc = "DA";
        }
    }
};

class PacientAdult : public Pacient
{
public:
    PacientAdult(int varsta) : Pacient(varsta) {}
};

class PacientAdultBatran : public PacientAdult
{
public:
    PacientAdultBatran(int varsta) : PacientAdult(varsta)
    {
        afectiuni["fumator (1 -> nu, 2 -> da)"] = 1;
        afectiuni["sedentar (1 -> scazut, 2 -> mediu, 3 -> ridicat)"] = 2;
    }
};

int main()
{
    vector<shared_ptr<Pacient>> pacienti;
    while (true)
    {
        string comanda;
        cout << "Introduceti comanda:\n";
        cout << "1. Adauga pacient" << endl;
        cout << "2. Afiseaza toti pacientii" << endl;
        cout << "3. Afiseaza pacientii adulti cu risc ridicat" << endl;
        cout << "4. Afiseaza pacientii copii cu risc ridicat" << endl;
        cout << "5. Afiseaza informatii dupa nume" << endl;
        cout << "6. Iesire" << endl;
        cin >> comanda;
        shared_ptr<Pacient> p;
        int age;
        string nume;
        switch (comanda[0])
        {
        case '1':
            system("clear");
            cout << "Introduceti varsta pacientului: ";
            cin >> age;
            if (age < 18)
                p = make_shared<PacientCopil>(age, pacienti);
            else if (age < 40)
                p = make_shared<PacientAdult>(age);
            else
                p = make_shared<PacientAdultBatran>(age);

            cin >> *p;
            pacienti.push_back(p);

            system("clear");
            break;

        case '2':
            system("clear");
            for (const auto &pacient : pacienti)
                cout << *pacient << endl;
            break;

        case '3':
            system("clear");
            for (const auto &pacient : pacienti)
            {
                if (pacient->getRisc() == "RIDICAT" && dynamic_cast<PacientAdult *>(pacient.get()))
                {
                    cout << *pacient << endl;
                }
            }
            break;

        case '4':
            system("clear");
            for (const auto &pacient : pacienti)
            {
                if (pacient->getRisc() == "DA" && dynamic_cast<PacientCopil *>(pacient.get()))
                {
                    cout << *pacient << endl;
                }
            }
            break;

        case '5':
            system("clear");
            cout << "Introduceti numele pacientului: ";
            cin >> nume;
            for (const auto &pacient : pacienti)
            {
                if (pacient->getName() == nume)
                {
                    cout << *pacient << endl;
                }
            }
            break;
        case '6':
            system("clear");
            cout << "Goodbye!\n";
            return 0;
        }
    }
}