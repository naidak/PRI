#include <iostream>
using namespace std;

//Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti(n > 2).
// Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva tako da je svaki sljedeći broj jednak umnošku dva prethodna broja, 
// a prva dva elementa su 1 i 3 (1, 3, 3, 9, 27, ...).
//
//Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza
// (voditi računa o tipu podatka zbog veličine broja).
//
//(Obavezno koristiti aritmetiku pokazivača)

void Unos(int* niz, int& vel, int i = 0)
{
	if (i == vel)
		return;
	if (i == 0)
		*(niz+i) = 1;
	else if (i == 1)
		*(niz+i) = 3;
	else {
		if (*(niz + i - 1) * *(niz + i - 2) < 0)
		{
			vel = i;
			return;
		}
		*(niz + i) = *(niz + i - 1) * *(niz + i - 2);
	}
	Unos(niz, vel, i + 1);
}

long int Suma(int* niz, int vel)
{
	if (vel == 0)
		return 0;
	return niz[vel - 1] + Suma(niz, vel - 1);
}

int main() {
	int n;
	do
	{
		cout << "Unesite n (n>2): ";
		cin >> n;
	} while (n<=2);

	int* niz = new int[n];

	Unos(niz, n);
	cout<<"Suma svih elemenata iznosi: "<<Suma(niz, n);

	delete[] niz; niz = nullptr;

	system("pause>0");
	return 0;
}
