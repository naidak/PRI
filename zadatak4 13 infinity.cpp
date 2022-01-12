#include <iostream>
#include <string.h>
using namespace std;

/*
Napisati program koji će omogučiti: Unos 2D niza od 10x10 elemanata vodeći računa da su svi elementi dvocifreni
(ukoliko unos nekog elementa ne zadovoljava uslov, ponavljati unos tog elementa dok se ne zadovolji uslov); 
Koristiti funkciju unos Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone - Koristiti funkciju transpose,
a zatim na osnovu izmijenjenog 2D niza: Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale -
Koristiti dvije funkcije: aritmeticka i prost_broj (pozivati će se iz funkcije aritmeticka) 
Napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*.
Obavezno koristiti navedene funkcije, a parametre i eventualne povratne vrijednosti definisati prema potrebi.
U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom.
*/
int brojCifara(int broj)
{
	return int(log10(broj)+ 1);
}

void Unos(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			do
			{
				cout << "Unesite dvocifren broj: ";
				cin >> niz[i][j];
			} while (brojCifara(niz[i][j])!=2);
		}
	}
}

void Ispis(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}
}

void transponuj(int** niz, int red, int kolona)
{
	int** temp = new int* [red];
	for (int i = 0; i < kolona; i++)
		*(temp + i) = new int[kolona] ;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0;  j< kolona; j++)
		{
			temp[i][j] = niz[i][j];
		}
	}

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			niz[i][j]=temp[j][i];
		}
	}
	for (int i = 0; i < kolona; i++)
		delete[] * (temp + i);
	delete[] temp; temp = nullptr;
	Ispis(niz,red,kolona);
}

//ar svih prostih ispod sporedne

bool jeProst(int broj)
{
	for (int i = 2; i < sqrt(broj); i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}

float artimetickaSredina(int** niz, int red, int kolona)
{
	int suma = 0;
	int brojac = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (jeProst(niz[i][j]) && (i + j >= kolona))
			{
				suma+=niz[i][j];
				brojac++;
					
			}
		}
	}
	return float(suma) / brojac;
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
			if ((pow(sumaCifara(niz[i][j]), 2) != sumaCifara(pow(niz[i][j], 2))) &&(i+j<=red-2))
				return false;
		}
	}
	return true;
}

int main() {
	int red = 10, kolona = 10;

	int** niz = new int* [red];

	for (int i = 0; i < kolona; i++)
		niz[i] = new int[kolona];

	Unos(niz, red, kolona);
	system("cls");
	Ispis(niz, red, kolona);
	cout << "---------------------------------------------------" << endl;
	transponuj(niz,red,kolona);

	cout << "Aritmeticka sredina prostih brojeva ispod sporedne dijagonale je: " << artimetickaSredina(niz, red, kolona) << endl;

	if (Simpaticni(niz, red, kolona))
		cout << "Brojevi iznad sporedne dijagonale su simpaticni." << endl;
	else
		cout<< "Brojevi iznad sporedne dijagonale nisu simpaticni." << endl;

	for (int i = 0; i < kolona; i++)
		delete[] niz[i];

	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}

