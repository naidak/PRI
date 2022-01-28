#include <iostream>
#include <iomanip>
using namespace std;

/*
Napisati program koji će generisati Fibonacci niz i smjestiti ga u jednodimenzionalni niz od 20 elemenata. 
(Fibonaccijev niz je niz brojeva koji počinje brojevima 0 i 1, a svaki sljedeći broj u nizu dobije se zbrajanjem prethodna dva: 
F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)). Zatim napraviti funkciju koja će sortirati niz uzlazno po srednjoj cifri. 
(Za brojeve sa parnim brojem koristiti aritmeticku sredinu srednje dvije cifre).

(Voditi računa o tipu podatka prilikom računanja srednje cifre.)
*/

int brojCifara(int broj)
{
	return int(log10(broj) + 1);
}

void Unos(int* niz, int vel, int i=0)
{	
	if (i == vel)
		return;
	if (i == 0 || i == 1)
		*(niz + i) = i;
	else {
		*(niz + i) = *(niz + i - 1) + *(niz + i - 2);
	}
	Unos(niz, vel, i + 1);
}

void Ispis(int* niz, int vel)
{
	if (vel == 0)
		return;
	Ispis(niz, vel - 1);
	cout << niz[vel-1]<<" ";
}

float srednjaCifra(int broj, int brojCifara)
{
	if (brojCifara % 2 != 0)
		return int(broj / (pow(10, (brojCifara / 2)))) % 10;
	return (int(broj / (pow(10, (brojCifara / 2)))) % 10 + int(broj / (pow(10, (brojCifara / 2) -1 ))) % 10) / float(2);
}

void Sortiraj(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if (srednjaCifra(niz[i], brojCifara(niz[i]))< srednjaCifra(niz[j], brojCifara(niz[j])))
			{
				int temp = niz[j];
				niz[j] = niz[i];
				niz[i] = temp;
			}
		}
	}
}

int main() {
	int n = 20;

	int* niz = new int[n];

	Unos(niz, n);
	Ispis(niz, n);
	Sortiraj(niz, n);
	cout << endl;
	Ispis(niz, n);

	system("pause>0");
	return 0;
}
