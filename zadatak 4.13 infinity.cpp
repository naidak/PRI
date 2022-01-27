#include <iostream>
using namespace std;

/*
	Napisati program koji će omogučiti:
	Unos 2D niza od 10x10 elemanata vodeći računa da su svi elementi dvocifreni 
	(ukoliko unos nekog elementa ne zadovoljava uslov, ponavljati unos tog elementa dok se ne zadovolji uslov); 
	Koristiti funkciju unos Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone - Koristiti funkciju transpose,
	a zatim na osnovu izmijenjenog 2D niza: Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale 
	- Koristiti dvije funkcije: aritmeticka i prost_broj (pozivati će se iz funkcije aritmeticka) Napisati funkciju simpatican 
	koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*. Obavezno koristiti navedene funkcije,
	a parametre i eventualne povratne vrijednosti definisati prema potrebi.
	U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom.
*/

int brCifri(int broj)
{
	return int(log10(broj) + 1);
}

bool prost_broj(int broj)
{
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}

void Unos(int** niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			do
			{
				cin>>niz[i][j] ;
			} while (brCifri(niz[i][j])!=2);
		}
	}
}

int** transpose(int** niz, int red, int kolona)
{
	int** novi_niz = new int* [red];
	for (int i = 0; i < red; i++)
	{
		novi_niz[i] = new int[kolona];
		for (int j = 0; j < kolona; j++)
		{
			novi_niz[i][j] = niz[j][i];
			cout << novi_niz[i][j] << " ";
		}
		cout << endl;
	}

	return novi_niz;
}

float aritmeticka(int** niz, int red, int kolona)
{
	int suma = 0, brojac = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i + j >= red && prost_broj(niz[i][i]))
			{
				suma += niz[i][j];
				brojac++;
			}
		}
	}
	if(brojac>0)
		return (float)suma / brojac;
	return 0;
}

int sumaCifara(int broj)
{
	int suma = 0;
	while (broj)
	{
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}

bool Simpaticni(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((pow(sumaCifara(niz[i][j]), 2) != sumaCifara(pow(niz[i][j], 2))) && (i + j <= red - 2))
				return false;
		}
	}
	return true;
}

int main() {
	int vel = 10;
	int** niz = new int*[vel];

	for (int i = 0; i < vel; i++)
		*(niz+i) = new int[vel];

	Unos(niz, vel);
	niz=transpose(niz, vel, vel); // niz pokazuje na nulti element, ovim izrazom niz krene pokazvat na nulti element niza koji vrati funkcija
								  // tako da *(*(niz+1)+1) krene pokazivati na lokaciju 1. transponovanog el, i tako svi ostali
								  // jer je promjenjena lokacija na koji pokazuje nulti, "mijenja" se za sve

	cout << "Aritmeticka prostih brojeva ispod sporedne dijagonale iznosi: " << aritmeticka(niz, vel, vel);

	if (Simpaticni(niz, vel, vel))
		cout << "Svi brojevi iznad galvne dijagonale su simpaticni.\n";
	else
		cout << "Svi brojevi iznad glavne dijagonale nisu simpaticni\n";

	for (int i = 0; i < vel; i++)
		delete[] * (niz + i);

	delete[] niz;

	system("pause>0");
	return 0;
}
