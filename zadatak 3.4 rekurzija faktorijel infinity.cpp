#include <iostream>
#include <iomanip>
using namespace std;

/*
	Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
	Napisati rekurzivnu funkciju koja će taj niz popuniti faktorijelom rednog broja člana niza (1!, 2!, 3!, 4!...). 
	Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
	U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama.

	(Obavezno koristiti aritmetiku pokazivača. Obavezno sve riješiti jednom rekurzivnom funkcijom.)
*/

void Unos(int* niz, int vel, int i=0, int proizvod =1)
{	
	if (i == vel)
		return;
	if (i == 0)
		*(niz) = 1;
	else {
		if (proizvod * (i+1) < 0)
			return;
		proizvod *= (i+1);
		*(niz + i) = proizvod;
	}
	Unos(niz, vel, i + 1, proizvod);
}

void Ispis(int* niz, int vel)
{
	if (vel == 0)
		return;
	Ispis(niz, vel - 1);
	cout << niz[vel-1]<<" ";
}

int main() {
	int n;
	do
	{
		cout << "Unesite velicinu niza: ";
		cin >> n;
	} while (n<=2);

	int* niz = new int[n] {};

	Unos(niz, n);
	Ispis(niz, n);

	system("pause>0");
	return 0;
}
