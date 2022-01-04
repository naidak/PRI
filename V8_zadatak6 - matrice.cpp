#include <iostream>
using namespace std;

/*
Napišite program za zbrajanje dviju matrica (matrice A i matrice B)koji će:
• omogućiti unos željene veličine matrica (broj redova i kolona – sve matrice
moraju biti jednake veličine),
• omogućiti unos vrijednosti elemenata matrica s tastature,
• kreirati treću matricu čiji će elementi biti suma odgovarajućih elemenata
matrica A i B,
• dealocirajte dinamički kreirane objekte,
• koristite funkcije.
*/

void Unos(int** matrica, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cin >> matrica[i][j];
		}
	}
}

void Ispis(int** matrica, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Sabiranje(int** matrica1, int** matrica2, int** matrica3, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			matrica3[i][j] = (matrica1[i][j] + matrica2[i][j]);
		}
	}
}

int main() {
	int red, kolona;
	cout << "Unesite broj redova: ";
	cin >> red;
	cout << "Unesite broj kolona: ";
	cin >> kolona;

	int** matrica1 = new int* [red];
	int** matrica2 = new int* [red];
	int** matrica3 = new int* [red];

	for (int i = 0; i < red; i++)
	{
		matrica1[i] = new int[kolona];
		matrica2[i] = new int[kolona];
		matrica3[i] = new int[kolona];
	}

	Unos(matrica1, red, kolona);
	Unos(matrica2, red, kolona);

	Ispis(matrica1, red, kolona);
	Ispis(matrica2, red, kolona);

	Sabiranje(matrica1, matrica2, matrica3, red, kolona);

	Ispis(matrica3, red, kolona);

	for (int i = 0; i < red; i++)
	{
		delete[] matrica1[i];
		delete[] matrica2[i];
		delete[] matrica3[i];
	}

	delete[] matrica1;
	delete[] matrica2;
	delete[] matrica3;

	system("pause>0");
	return 0;
}
