#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2).
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva tako da je svaki sljedeći broj jednak umnošku dva prethodna broja, 
a prva dva elementa su 1 i 3 (1, 3, 3, 9, 27, ...).

Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza 
(voditi računa o tipu podatka zbog veličine broja).

(Obavezno koristiti aritmetiku pokazivača)
*/

void Unos(int* niz,int len,int i=0)
{
	if (i == len)
		return;
	if (i == 1)
		*(niz + i) = 3;
	else if (i == 0)
		*(niz + i) = 1;
	else {
		if (*(niz + i - 1) * *(niz + i - 2) < 0)
			return;
		else
			*(niz + i) = *(niz + i - 1) * *(niz + i - 2);
	}
	Unos(niz, len, i + 1);
}

int Suma(int* niz, int len,int i=0)
{
	if (len==i)
		return *(niz+i);
	return *(niz+i)+Suma(niz,len,i+1);
}

int main() {
	int len;
	len = 5;
	int* niz = new int[len];

	Unos(niz, len);

	for (int i = 0; i < len; i++)
	{
		cout << *(niz + i) << " ";
	}

	cout << "Suma clanova niza je: " << Suma(niz, len-1);

	delete[] niz;

	system("pause>0");
	return 0;
}
