#include <iostream>
using namespace std;

/*
	Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
	Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1. 1 1 2 3 5 8 13 
	Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju. 
	Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
	U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
*/
int fib(int n)
{
	if (n < 0)
		return -1;

	if (n == 0 || n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

void Unos(int* niz, int& vel, int i=0)
{
	if (i == vel)
		return;
	else
	{
		if (fib(i) <0)
		{
			vel = i;
			return;
		}
		else
			niz[i] = fib(i);
	}
	Unos(niz, vel, i + 1);
}

void Ispis(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << " ";
	}
}

int main() {
	int vel;
	cout << "Unesite velicinu niza: ";
	cin >> vel;

	int* niz = new int[vel];

	Unos(niz, vel);
	Ispis(niz, vel);

	delete[] niz;

	system("pause>0");
	return 0;
}

