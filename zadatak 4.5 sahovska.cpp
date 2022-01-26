#include <iostream>
using namespace std;

/*
	2D niz na slici predstavlja šahovsku tablu. Napraviti i testirati u main programu slijedeće funkcije:

	Funkcija za unos elemenata tako da se u svako crno polje unese parni broj sa neparnim brojem cifara
	a u svako bijelo polje unese neparni broj sa parnim brojem cifara.
	Funkcija koja će računati aritmetičku sredinu svih brojeva na crnim poljima iznad glavne dijagonale.
	Za olaksanje rjesenja, mozete izabrati prototip funkcija po zelji te kreirati dodatne funkcije po potrebi.
*/
int brojCifara(int broj)
{
	return int(log10(broj) + 1);
}

void Unos(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j) % 2 == 0)
			{
				do
				{
					cout << "Crno polje: ";
					cin >> *(*(niz + i) + j);
				} while (brojCifara(*(*(niz+i)+j))%2==0 && *(*(niz + i) + j) % 2!=0);
			}
			else
			{
				do
				{
					cout << "Bijelo polje: ";
					cin >> *(*(niz + i) + j);
				} while (brojCifara(*(*(niz + i) + j)) % 2 != 0 && *(*(niz + i) + j) % 2 == 0);
			}
		}
	}
}

void Ispis(int** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << *(*(niz + i) + j) << " ";
		}
		cout << endl;
	}
}

float AritmetickaSredina(int** niz, int red, int kolona)
{
	int suma = 0;
	int brojac = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((i + j )% 2 == 0 && (i+j)<=red-2)
			{
				suma += *(*(niz + i) + j);
				brojac++;
			}
		}
	}
	return float(suma) / float(brojac);
}

int main() {
	int red, kolona;
	cout << "Unesite dimenzije sahovske table: ";
	cin >> red;
	kolona = red;
	int** sahovska_tabla = new int* [red];

	for (int i = 0; i < red; i++)
		*(sahovska_tabla + i) = new int[kolona];

	Unos(sahovska_tabla, red, kolona);
	Ispis(sahovska_tabla, red, kolona);
	cout<<"Aritmeticka sredina brojeva na crnim poljima iznad glavne dijagonale iznosi: "<<AritmetickaSredina(sahovska_tabla, red, kolona);

	for (int i = 0; i < red; i++)
		delete[]*(sahovska_tabla + i);

	delete[] sahovska_tabla;

	system("pause>0");
	return 0;
}

