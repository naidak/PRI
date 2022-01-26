#include <iostream>
#include <cmath>
using namespace std;

struct kosarkas
{
	char* ID;
	char* imePrezime;
	int* postignutiKosevi;

	kosarkas()
	{
		ID = new char[30];
		imePrezime = new char[50];
		postignutiKosevi = new int;
	}

	~kosarkas()
	{
		delete[] ID; ID = nullptr;
		delete[] imePrezime; imePrezime = nullptr;
		delete postignutiKosevi; postignutiKosevi = nullptr;
	}
};

void Unos(kosarkas** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Unesite ID: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->ID, 30);
			cout << "Unesite ime i prezime: ";
			cin.getline((*(niz + i) + j)->imePrezime, 50);
			cout << "Unesite broj postignutih koseva: ";
			cin >> *(*(niz + i)+j)->postignutiKosevi;
		}
	}
}
/*napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa).
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi) i 
najlošijeg košarkaša u kompletnoj ligi te izračunati razliku u broju postignutih koševa ta dva košarkaša.

(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)*/

int* NajuspjesnijiKlub(kosarkas** niz, int red, int kolona)
{
	int index_najboljeg = 0;
	int* sume = new int[red] {};
	int najbolji = 0;
	int kosevi_najboljeg_igraca = 0;
	int kosevi_najgoreg_igraca = INT_MAX;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(sume + i) = *(*(niz + i) + j)->postignutiKosevi;

			if (*(*(niz + i) + j)->postignutiKosevi < kosevi_najgoreg_igraca) // odredjivanje najgoreg u ligi
				kosevi_najgoreg_igraca = *(*(niz + i) + j)->postignutiKosevi;
		}
		
		if (*(sume + i) > najbolji)
		{
			najbolji = *(sume + i);
			index_najboljeg = i;

			for (int j = 0; j < kolona; j++)
			{
				if (*(*(niz + i) + j)->postignutiKosevi > kosevi_najboljeg_igraca) // odredjivanje najboljeg u ligi
					kosevi_najboljeg_igraca = *(*(niz + i) + j)->postignutiKosevi;
			}
		}
	}

	cout << "Najuspjesniji klub je klub broj " << index_najboljeg + 1 << endl;

	return new int(kosevi_najboljeg_igraca - kosevi_najgoreg_igraca);
}



int main() {
	int red, kolona;
	cout << "Unesite broj timova: ";
	cin >> red;
	cout << "Unesite broj kosarkasa: ";
	cin >> kolona;

	kosarkas** niz = new kosarkas * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new kosarkas[kolona];

	int* funk = NajuspjesnijiKlub(niz, red, kolona);

	Unos(niz, red, kolona);
	cout << "Razlika koseva izmedju najboljeg igraca u najboljem timu i najgoreg igraca u ligi iznosi: " << *NajuspjesnijiKlub(niz,red,kolona) <<
		" i ta vrijednost je spremljena na adresi: " <<funk << endl;

	for (int i = 0; i < red; i++)
		delete[] * (niz + i);

	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}
