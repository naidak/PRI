#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., 
tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2.
Zatim,korisnik unosi željeni broj te rekurzivnom funkcijom provjerava da li je taj broj član kreiranog niza.
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/

void Unos(int* niz,int len,int i=0)
{
	if (i == len)
		return;
	else {
		*(niz + i) = pow(2, (i+1));
	}
	Unos(niz, len, i + 1);
}

void Ispis(int* niz, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(niz + i) << " ";
	cout << endl;
}

bool Provjera(int* niz, int len,int broj, int i = 0)
{
	if (i == len)
		return false;
	else if (*(niz + i) == broj)
		return true;
	Provjera(niz, len, broj, i + 1);
}

int main() {
	int len;
	len = 5;
	int* niz = new int[len];
	int trazeni_broj = 32;
	
	Unos(niz, len);

	Ispis(niz, len);

	if (Provjera(niz, len, trazeni_broj))
		cout << trazeni_broj << " postoji u nizu\n";
	else
		cout << trazeni_broj << " ne postoji u nizu\n";

	delete[] niz;

	system("pause>0");
	return 0;
}
