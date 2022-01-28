#include <iostream>
#include <iomanip>
using namespace std;

/*
	Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
	Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., 
	tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2. 
	Zatim,korisnik unosi željeni broj te rekurzivnom funkcijom provjerava da li je taj broj član kreiranog niza.
	Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

	(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/

void Unos(int* niz, int vel, int i = 0)
{	
	if (i == vel)
		return;
	if (i == 0)
		*(niz) = 2;
	else {
		if (2 * *(niz + i - 1) < 0)
			return;
		*(niz + i) = 2 * *(niz + i - 1);
	}
	Unos(niz, vel, i + 1);
}

void Ispis(int* niz, int vel)
{
	if (vel == 0)
		return;
	Ispis(niz, vel - 1);
	cout << niz[vel-1]<<" ";
}

bool Provjera(int* niz, int vel,int broj)
{
	if (vel==0)
		return false;
	if (*(niz + vel-1) == broj)
		return true;
	Provjera(niz, vel-1, broj);
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

	int broj;
	cout << "Unesite zeljeni broj: ";
	cin >> broj;
	if (Provjera(niz, n, broj))
		cout << "Broj " << broj << " je clan kreiranog niza. \n";
	else
		cout << "Broj " << broj << " nije clan kreiranog niza\n";

	system("pause>0");
	return 0;
}
