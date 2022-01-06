#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1. 
Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju. 
Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/

void Unos(int* niz,int len,int i=0)
{
	if (i == len)
		return;
	else if (i == 0 || i == 1)
		*(niz + i) = 1;
	else {
		if (*(niz + i - 1) + *(niz + i - 2) < 0)
			return;
		else
			*(niz + i) = *(niz + i - 1) + *(niz + i - 2);
	}

	Unos(niz, len, i + 1);
}

void Ispis(int* niz, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(niz + i) << " ";
	cout << endl;
}


int main() {
	int len;
	cin >> len;
	int* niz = new int[len];
	
	Unos(niz, len);

	Ispis(niz, len);

	delete[] niz;

	system("pause>0");
	return 0;
}
