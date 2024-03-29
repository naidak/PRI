#include <iostream>
#include <iomanip>
using namespace std;

/*
Kreirati jednodim dinam niz n velicine i napuniti ga serijom kubova svakog proslog broja pocevsi od 2.
Prekida se kada se deesi overflow, napuni niz.Ispisati niz rekurzivno!

Koristiti aritmetiku pointera!
*/

void Unos(int* niz, int vel, int i=0)
{	
	if (i == vel)
		return;
	if (i == 0)
		*(niz + i) = 2;
	else {
		int temp = pow(*(niz + i - 1), 3);
		if (temp < 0)
			return;
		
		*(niz + i) =temp;
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

int main() {
	int n;

	cin >> n;

	int* niz = new int[n] {};

	Unos(niz, n);
	Ispis(niz, n);
	

	system("pause>0");
	return 0;
}
