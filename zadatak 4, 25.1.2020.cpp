#include <iostream>
#include <cmath>
using namespace std;

struct vozilo
{
	char* markaVozila;
	char* nazivVozila;
	char* tipVozila; // omogućiti unos samo 'A', 'B','C'
	float* potrosnja_goriva_po_km;

	vozilo() {
		markaVozila = new char[20];
		nazivVozila = new char[20];
		tipVozila = new char;
		potrosnja_goriva_po_km = new float;
	}

	~vozilo() {
		delete[] markaVozila; markaVozila = nullptr;
		delete[] nazivVozila; nazivVozila = nullptr;
		delete tipVozila; tipVozila = nullptr;
		delete potrosnja_goriva_po_km; potrosnja_goriva_po_km = nullptr;
	}
};

void Unos(vozilo** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Unesite marku vozila: ";
			cin.ignore();
			cin.getline( (*(niz + i) + j)->markaVozila,20);
			cout << "Unesite naziv vozila: ";
			cin.getline((*(niz + i) + j)->nazivVozila, 20);
			do {
				cout << "Unesite tip vozila (A, B, C) : ";
				cin >> *(*(niz + i) + j)->tipVozila;
			} while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
			cout << "Unesite potrosnju po km: ";
			cin >> *(*(niz + i) + j)->potrosnja_goriva_po_km;
		}
	}
}

void Ispis(vozilo** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Firma " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "	Automobil " << j + 1 << endl;
			cout << "	Marka vozila: " << (*(niz + i) + j)->markaVozila << endl;
			cout << "	Naziv vozila: " << (*(niz + i) + j)->nazivVozila << endl;
			cout << "	Tip vozila: " << *(*(niz + i) + j)->tipVozila << endl;
			cout << "	Potrosnja goriva po km: " << *(*(niz + i) + j)->potrosnja_goriva_po_km << endl;
		}
		cout << "-----------------------------------------------------------------------------\n";
	}
}

int NajvecaPotrosnjaGoriva(vozilo** niz, int red, int kolona)
{
	float* potrosnje = new float[red] {};
	float najvecaPotrosnja = 0.0;
	int indeksNajvece = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			potrosnje[i] += *(*(niz + i) + j)->potrosnja_goriva_po_km;
		}
		if (*(potrosnje + i) > najvecaPotrosnja)
		{
			najvecaPotrosnja = *(potrosnje + i);
			indeksNajvece = i;
		}
	}
  
  delete[] potrosnje; potrosnje=nullptr;
  
	return indeksNajvece;
}

float prosjecnaPotrosnjaC(vozilo** niz, int red, int kolona)
{
	float prosjecnaPotrosnja = 0.0;
	int brojac = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->tipVozila == 'C')
			{
				prosjecnaPotrosnja += *(*(niz + i) + j)->potrosnja_goriva_po_km;
				brojac++;
			}
		}
	}
	return (prosjecnaPotrosnja / brojac);
}

int main() {
	
	int red, kolona;
	cout << "Unesite broj firmi: ";
	cin >> red;
	cout << "Unesite broj automobila: ";
	cin >> kolona;

	vozilo** niz = new vozilo * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new vozilo[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	int potrosnja = NajvecaPotrosnjaGoriva(niz, red, kolona);
	cout << "Firma sa najvecom potrosnjom goriva po km: " << potrosnja+1 <<" tj. firma sa indeksom "<<potrosnja<< endl;
	cout << "Prosjecna potrosnja tipa vozila C u svim firmama je: " << prosjecnaPotrosnjaC(niz, red, kolona) << endl;

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;


	system("pause>0");
	return 0;
}

