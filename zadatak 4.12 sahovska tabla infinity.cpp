#include <iostream>
using namespace std;

/*
	Dat je 2D niz koji simulira šahovsku tablu. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza 
	tako da se u svako "crno" polje unese parni broj sa neparnim brojem cifara, a u "bijelo polje neparni broj sa parnim brojem cifara. 
	Izračunati i ispisati prosjeke (aritmetičke sredine) svih elemenata na bijelim poljima iznad glavne dijagonale 
	te na crnim poljima ispod sporedne dijagonale.
*/

int brCifri(int broj)
{
	return int(log10(broj) + 1);
}

void Unos(int** niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if((i+j)%2==0)
			{ 
				do
				{
					cout << "Unesite paran broj sa neparnim brojem cifara: ";
					cin >> niz[i][j];
				} while (brCifri(niz[i][j])%2==0 || niz[i][j]%2!=0);
			}
			else {
				do
				{
					cout << "Unesite neparan broj sa parnim brojem cifara: ";
					cin >> niz[i][j];
				} while (brCifri(niz[i][j])%2!=0 || niz[i][j]%2==0);
			}
		}
	}
}

void AritmetickeSredine(int** niz, int red, int kolona)
{
	int brojacB = 0, brojacC = 0;
	float prosjekB = 0.0, prosjekC = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (j > i && (i + j) % 2 != 0)
			{
				prosjekB += niz[i][j];
				brojacB++;
			}
			else if ((i + j) >= red && (i + j) % 2 == 0)
			{
				prosjekC += niz[i][j];
				brojacC++;
			}
		}
	}
	cout << "Aritmeticka sredina elemenata na bijelim poljima iznad glavne dijagonale iznosi " << prosjekB / brojacB << endl;
	cout << "Aritmeticka sredina elemenata na crnim poljima iznad sporedne dijagonale iznosi " << prosjekC / brojacC << endl;
}

int main() {
	int vel = 10;
	int** niz = new int*[vel];

	for (int i = 0; i < vel; i++)
		*(niz+i) = new int[vel];

	Unos(niz,vel);
	AritmetickeSredine(niz, vel,vel);

	for (int i = 0; i < vel; i++)
		delete[] * (niz + i);

	delete[] niz;

	system("pause>0");
	return 0;
}
