#include <iostream>

using namespace std;

/*
Napišite program u kojem ćete:
--Omogućiti korisniku da unese vrijednost N (broj članova niza);
--Alocirati niz operacijom new (članovi niza su tipa double);
--Omogućiti inicijalizaciju članova niza unosom vrijednosti s tastature (koristiti
funkciju);
--Izračunati i ispisati prosječnu vrijednost elemenata niza (koristiti funkciju);
--Dealocirati memorijski blok upotrijebljen za kreiranje niza.
*/

void Unos(double* niz, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "Unesite " << i + 1 << ". element: ";
		cin >> niz[i]; //cin>>*(niz+i);
	}
}

double ProsjecnaVrijednost(double* niz, int vel)
{
	double suma = 0.0;
	for (int i = 0; i < vel; i++)
		suma += *(niz + i);

	return suma / vel;
}

int main()
{
	int vel;
	cout << "Unesite duzinu niza: ";
	cin >> vel;

	double* niz = new double[vel];
	Unos(niz, vel);

	cout << "Prosjecna vrijednost elemenata niza je: " << ProsjecnaVrijednost(niz, vel) << endl;

	delete[] niz;

	system("pause>0");
	return 0;
}