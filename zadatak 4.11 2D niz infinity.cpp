#include <iostream>
using namespace std;

/*
	Napisati program koji će omogućiti unos elemenata matrice dimenzija 10x10 cijelim brojevima sa neparnim brojem cifara.
	Za provjeru broja cifara koristiti funkciju brCif(int).
	Zatim pronaći i ispisati red sa najvećim prosjekom (aritmetičkom sredinom) elemenata, te kolonu sa najmanjim prosjekom elemenata.
*/

int brCifri(int broj)
{
	return int(log10(broj) + 1);
}

void Unos(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			do
			{
				niz[i][j] = rand() % 100;
			} while (brCifri(niz[i][j])%2==0);
		}
	}
}

void Prosjeci(int** niz, int red, int kolona)
{
	float* prosjeci_po_redovima = new float[red] {};
	float* prosjeci_po_kolonama = new float[kolona] {};
	int index_reda = 0, index_kolone = 0;
	float najveci_prosjek_red = 0.0, najmanji_prosjek_kolona = INT_MAX;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			prosjeci_po_kolonama[i] += niz[j][i];
			prosjeci_po_redovima[i] += niz[i][j];
		}

		prosjeci_po_kolonama[i] /= red;
		prosjeci_po_redovima[i] /= kolona;

		if (prosjeci_po_kolonama[i]< najmanji_prosjek_kolona)
		{
			najmanji_prosjek_kolona = prosjeci_po_kolonama[i];
			index_kolone = i;
		}

		if (prosjeci_po_redovima[i] > najveci_prosjek_red)
		{
			najveci_prosjek_red = prosjeci_po_redovima[i];
			index_reda = i;
		}
	}

	cout << "Kolona sa najmanjim prosjekom je kolona " << index_kolone << endl
		<< " a red sa najvecim prosjekom je red " << index_reda << endl;
}

int main() {
	int vel = 10;
	int** niz = new int*[vel];

	for (int i = 0; i < vel; i++)
		*(niz+i) = new int[vel];

	Unos(niz,vel,vel);
	Prosjeci(niz, vel, vel);

	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < vel; i++)
		delete[] * (niz + i);

	delete[] niz;

	system("pause>0");
	return 0;
}
