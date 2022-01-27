#include <iostream>
using namespace std;

/*
	Dat je 2D niz dimenzija 8 x 8. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svaki neparni red unesu parni brojevi
	a svaki parni red neparni broj. Napraviti funkciju koja pronalazi kolonu sa najmanjim prosjekom elemenata. 
	U istoj funkciji ispisati index pronađene kolone, a u main funkciji sve elemente te kolone.
*/

void Unos(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i % 2 == 0)
			{
				do
				{
					cout << "Unesite neparan broj: ";
					cin >> *(*(niz + i) + j);
				} while (*(*(niz+i)+j)%2==0);
			}
			else
			{
				do
				{
					cout << "Unesite paran broj: ";
					cin >> *(*(niz + i) + j);
				} while (*(*(niz + i) + j) % 2 != 0);
			}
		}
	}
}

int* NajmanjaKolona(int** niz, int red, int kolona)
{
	float* prosjeci = new float[kolona]{};
	float najmanji_prosjek = INT_MAX;
	int index_kolone = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) += *(*(niz + j) + i);
		}

		*(prosjeci + i) /= red;

		if (*(prosjeci + i) < najmanji_prosjek)
		{
			najmanji_prosjek = *(prosjeci + i);
			index_kolone = i;
		}
	}

	cout << "Kolona sa namanjim prosjekom je kolona " << index_kolone << endl;

	int* kolonaNiz = new int[red];

	for (int i = 0; i < red; i++)
		*(kolonaNiz + i) = *(*(niz + i) + index_kolone);
	
	return kolonaNiz;
}

int main() {
	int vel = 8;

	int** niz = new int* [vel];

	for (int i = 0; i < vel; i++)
		*(niz + i) = new int[vel];

	Unos(niz, vel, vel);

	int* kolona=NajmanjaKolona(niz, vel, vel);

	cout << "Kolona sa najmanjim prosjekom ima elemente: " << endl;
	for (int i = 0; i < vel; i++)
		cout << *(kolona + i) << endl;
	

	for (int i = 0; i < vel; i++)
		delete[] *(niz + i);

	delete[] niz;
	delete[] kolona;
	kolona = nullptr; niz = nullptr;

	system("pause>0");
	return 0;
}
