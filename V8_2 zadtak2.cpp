#include <iostream>

using namespace std;

/*
Napišite program u kojem ćete:
--Kreirati dinamički niz od onoliko cjelobrojnih elemenata koliko želi korisnik;
--Omogućiti inicijalizaciju članova niza unosom s tastature;
--Utvrditi (prebrojati) koliko elemenata niza je zadovoljava uvjet (element niza%7>4);
--Kreirati novi niz čiji će elementi biti elementi prvog niza koji zadovoljavaju prethodni
uvjet (element niza%7>4);
--Koristite funkcije.
*/

void Unos(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << "Unos " << i + 1 << ". elementa: ";
		cin >> *(niz + i);
	}
}

int Brojac(int* niz, int vel)
{
	int brojac = 0;
	for (int i = 0; i < vel; i++)
	{
		if (*(niz+i) % 7 > 4)
			brojac++;
	}
	return brojac;
}

void UnosNoviNiz(int* noviN, int* N, int vel)
{
	int poz = 0;
	for (int i = 0; i < vel; i++)
	{
		if (N[i] % 7 > 4)
		{
			noviN[poz] = N[i];
			poz++;
		}
	}
}

void Ispis(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << " ";
	}
}

int main()
{
	int vel;
	int* niz = nullptr;
	cout << "Unesite velicinu niza: ";
	cin >> vel;
	niz = new int[vel];

	Unos(niz, vel);

	int vel2 = Brojac(niz, vel);
	int* noviNiz = new int[vel2];
	UnosNoviNiz(noviNiz, niz, vel);

	cout << "Niz: "; Ispis(niz,vel);
	cout << endl << "Novi niz: ";
	Ispis(noviNiz, vel2);

	system("pause>0");
	return 0;
}
