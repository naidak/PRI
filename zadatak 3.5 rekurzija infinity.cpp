#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati rekurzivnu funkciju koja će taj niz popuniti random brojevima u opsegu od 1 do 100. 
Za generisanje random brojeva koristiti rand() % 100 + 1. Punjenje niza se prekida kada se popuni cijeli niz ili 
kada se tri puta uzastopno dobije isti random broj. U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama. 
Obavezno koristiti aritmetiku pokazivača.

(Obavezno sve riješiti jednom rekurzivnom funcijom.)
*/
void Unos(int* niz, int& len, int i = 0)
{
	if (i == len)
		return;
	else 
		*(niz + i) = rand() % 100 + 1;
	
	if (*(niz + i) == *(niz + i - 1) && *(niz + i - 2) == *(niz + i))
	{
		len -= i;
		return;
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
