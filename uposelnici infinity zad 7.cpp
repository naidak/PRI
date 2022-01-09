#include <iostream>
using namespace std;

struct uposlenik
{
    char* ID;
    char* imePrezime;
    float* plata;

    uposlenik() {
        ID = new char[20];
        imePrezime = new char[50];
        plata = new float;
    }

    ~uposlenik() {
        delete[] ID; ID = nullptr;
        delete[] imePrezime; imePrezime = nullptr;
        delete plata; plata = nullptr;
    }
};

void Unos(uposlenik**, int, int);
void Ispis(uposlenik**, int, int);
void NajveciProsjek(uposlenik**, int, int);

int main() {
    int red, kolona;
    cout << "Unesite red: ";
    cin >> red;
    cout << "Unesite kolonu: ";
    cin >> kolona;

    uposlenik** niz = new uposlenik*[red];

    for (int i = 0; i < red; i++)
        *(niz + i) = new uposlenik[kolona];

    Unos(niz, red, kolona);
    Ispis(niz, red, kolona);
    NajveciProsjek(niz, red, kolona);

    for (int i = 0; i < red; i++)
        delete[] *(niz + i);

    delete[] niz;
    niz = nullptr;

	system("pause>0");
	return 0;
}

void Unos(uposlenik** niz, int red, int kolona)
{
    for (int i = 0; i < red; i++)
    {
        cout << i + 1 << ". odjel: "<<endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << j + 1 << " zaposlenik: " << endl;
            cout << "\t Unesite ID zaposlenika: ";
            cin.ignore();
            cin.getline((*(niz + i) + j)->ID, 20);
            cout << "Unesite ime i prezime: ";
            cin.getline((*(niz + i) + j)->imePrezime, 50);
            cout << "Unesite platu: ";
            cin >> *(*(niz + i) + j)->plata;
            
        }
        cout << "----------------------------------\n";
    }
}

void Ispis(uposlenik** niz, int red, int kolona)
{
    for (int i = 0; i < red; i++)
    {
        cout << i + 1 << ". odjel: " << endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << j + 1 << " zaposlenik: " << endl;
            cout << "\tID: " << (*(niz + i) + j)->ID << endl;
            cout << "\tIme i prezime: " << (*(niz + i) + j)->imePrezime << endl;
            cout << "\tPlata: " << *(*(niz + i) + j)->plata << endl;
        }
        cout << "----------------------------------\n";
    }
}

void NajveciProsjek(uposlenik** niz, int red, int kolona)
{
    float* prosjecnePlate = new float[red] {};

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(prosjecnePlate + i) += *(*(niz + i) + j)->plata;
        }
        *(prosjecnePlate + i) /= kolona;
    }

    float max_prosjek=0.0;
    int max_index = 0;

    for (int i = 0; i < red; i++)
    {
        if (*(prosjecnePlate + i) > max_prosjek)
        {
            max_prosjek = *(prosjecnePlate + i);
            max_index = i;
        }
    }

    cout << "Odjel sa najvecim prosjekom ima redni broj " << max_index + 1 << ", a iznos prosjecne plate je " << max_prosjek << endl;
}
