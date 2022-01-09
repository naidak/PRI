#include <iostream>
using namespace std;

struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;

    figura()
    {
        nazivFigure = new char[20];
        visinaFigure = new float;
    }

    ~figura() {
        delete[] nazivFigure; nazivFigure = nullptr;
        delete visinaFigure; visinaFigure = nullptr;
    }
};

void Unos(figura** , int , int);
void Ispis(figura**, int, int);
float* prosjecnaVisina(figura**, int, int);

int main() {
    int red, kolona;
    cout << "Unesite red: ";
    cin >> red;
    cout << "Unesite kolonu: ";
    cin >> kolona;

    figura** niz = new figura*[red];

    for (int i = 0; i < red; i++)
        *(niz + i) = new figura[kolona];

    Unos(niz, red, kolona); Ispis(niz, red, kolona);

    cout << "Prosjecna visina crnih polja ispod sporedne dijagonale je " << *prosjecnaVisina(niz, red, kolona) << endl;

    for (int i = 0; i < red; i++)
        delete[] *(niz + i);

    delete[] niz;
    niz = nullptr;

	system("pause>0");
	return 0;
}

void Unos(figura** niz, int red, int kolona)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Unesite ID: ";
            cin >> (*(niz + i) + j)->ID;
            cin.ignore();
            cout << "Unesite naziv figure: ";
            cin.getline((*(niz + i) + j)->nazivFigure, 50);
            cout << "Unesite visinu figure: ";
            cin >> *(*(niz + i) + j)->visinaFigure;
            cin.ignore();
        }
    }
}

void Ispis(figura** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        cout << "Red " << i + 1 << endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << "Kolona " << j + 1 << endl;
            cout << "ID: " << (*(niz + i) + j)->ID << endl;
            cout << "Naziv figure: " << (*(niz + i) + j)->nazivFigure << endl;
            cout << "Visina figure: " << *(*(niz + i) + j)->visinaFigure << endl;
        }
        cout << "---------------------------------------------------\n";
    }
}

float* prosjecnaVisina(figura** niz, int red, int kolona) // elementi ispod sporedne na crnim poljima
{
    float suma = 0.0;
    int brojac = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if ((i + j)>=kolona && (i + j) % 2 == 0)
            {
                suma += *(*(niz + i) + j)->visinaFigure;
                brojac++;
            }
        }
    }
    float rez = suma / brojac;

    return new float(rez);
}
