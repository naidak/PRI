#include <iostream>
#include <string.h>
using namespace std;

/*
Dat je 2D niz dimenzija 8 x 8. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svaki neparni red 
unesu parni brojevi a svaki parni red neparni broj. Napraviti funkciju koja pronalazi kolonu sa najmanjim prosjekom elemenata.
U istoj funkciji ispisati index pronađene kolone, a u main funkciji sve elemente te kolone.
*/
int unosParni(int broj)
{
	do
	{
		cout << "Unesite paran broj: ";
		cin >> broj;
	} while (broj%2!=0);
	return broj;
}

int unosNeparni(int broj)
{
	do
	{
		cout << "Unesite neparan broj: ";
		cin >> broj;
	} while (broj%2==0);
	return broj;
}

void Unos(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i % 2 != 0)
				niz[i][j]=unosParni(niz[i][j]);
			else if (i % 2 == 0)
				niz[i][j]=unosNeparni(niz[i][j]);
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

int* najmanjiProsjek(int** niz, int red, int kolona)
{
	float* prosjeci = new float[kolona] {};
	float najmanjiProsjek=INT_MAX;
	int indexNajmanjeg = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci+i) += (*(*(niz+j)+i));
		}
		*(prosjeci + i) /= red;
		if (najmanjiProsjek > prosjeci[i])
		{
			najmanjiProsjek = prosjeci[i];
			indexNajmanjeg = i;
		}
	}

	cout << "Najmanji prosjek je: " << najmanjiProsjek << endl;
	cout << "Index najmanjeg je: " << indexNajmanjeg << endl;

	int* kolonaNiz = new int[kolona];
	for (int i = 0; i < kolona; i++)
	{
		kolonaNiz[i] = niz[i][indexNajmanjeg];
	}

	return kolonaNiz;
}

int main() {
	int red = 3, kolona = 3;

	int** niz = new int* [red];

	for (int i = 0; i < kolona; i++)
		niz[i] = new int[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);

	int* kolonaNiz=najmanjiProsjek(niz, red, kolona);

	cout << "Kolona sa najmanjim prosjekom: " << endl;
	for (int i = 0; i < kolona; i++)
	{
		cout << kolonaNiz[i] << "\n";
	}

	for (int i = 0; i < kolona; i++)
		delete[] niz[i];

	delete[] niz;
	delete[] kolonaNiz;

	system("pause>0");
	return 0;
}
