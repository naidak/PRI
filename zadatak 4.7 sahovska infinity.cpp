#include <iostream>
using namespace std;

struct figura
{
	int ID;
	char* nazivFigure;
	float* visinaFigure;

	figura() {
		ID = 0;
		nazivFigure = new char[20];
		visinaFigure = new float;
	}

	~figura() {
		delete[] nazivFigure; nazivFigure = nullptr;
		delete visinaFigure; visinaFigure = nullptr;
	}
};

void Unos(figura** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Unesite ID: ";
			cin >> (*(niz + i) + j)->ID;
			cout << "Unesite naziv figure: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->nazivFigure, 20);
			cout << "Unesite visinu figure: ";
			cin >> *(*(niz + i) + j)->visinaFigure;
		}
	}
}
/*
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale.
(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.)
*/
float* ProsjecnaVisina(figura** niz, int red, int kolona)
{
	float suma = 0.0;
	int brojac = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j) % 2 == 0 && (i + j) >= red)
			{
				suma += *(*(niz + i) + j)->visinaFigure;
				brojac++;
			}
		}
	}
	return new float(float(suma) / brojac);
}

int main() {
	int red, kolona;
	cout << "Unesite broj redova: ";
	cin >> red;
	cout << "Unesite broj kolona: ";
	cin >> kolona;

	figura** niz = new figura * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new figura[kolona];

	Unos(niz, red, kolona);
	cout << "Prosjecna visina figura na crnim poljima ispod sporedne dijagonale iznosi: " << *ProsjecnaVisina(niz, red, kolona) << " i to je spremljeno na lokaciji " << ProsjecnaVisina(niz, red, kolona);

	for (int i = 0; i < red; i++)
		delete[] * (niz + i);

	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}
