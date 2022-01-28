#include <iostream>
#include <iomanip>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1. 
Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju. 
Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/

int fib(int pozicija)
{
	if (pozicija == 0 || pozicija == 1)
		return 1;
	return fib(pozicija - 1) + fib(pozicija - 2);
}

void Unos(int* niz, int vel)
{	
	if (vel==0)
		return;
	*(niz + vel-1) = fib(vel-1);
	Unos(niz, vel-1);
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
