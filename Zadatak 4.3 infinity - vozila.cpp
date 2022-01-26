#include <iostream>
using namespace std;

struct vozilo
{
	char* markaVozila;
	char* brojSasije;
	char* tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
	float* potrosnja_goriva_po_km;

	vozilo() {
		markaVozila = new char[50];
		brojSasije = new char[20];
		tipVozila = new char;
		potrosnja_goriva_po_km = new float;
	}

	~vozilo() {
		delete[] markaVozila;
		delete[] brojSasije;
		delete tipVozila;
		delete potrosnja_goriva_po_km;
		markaVozila = nullptr;
		brojSasije = nullptr;
		tipVozila = nullptr;
		potrosnja_goriva_po_km = nullptr;
	}
};

void Unos(vozilo**, int, int);
void Ispis(vozilo**, int, int);
float prosjecnaPotrosnjaGorivaC(vozilo**, int, int);

int main() {
	
	int red, kolona;
	cout << "Unesite broj firmi: ";
	cin >> red;
	cout << "Unesite broj auta: ";
	cin >> kolona;

	vozilo** niz = new vozilo * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new vozilo[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	cout << "Prosjecna potrosnja goriva vozila tipa C iznosi: " << prosjecnaPotrosnjaGorivaC(niz, red, kolona) << endl;

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;


	system("pause>0");
	return 0;
}

void Unos(vozilo** niz, int red, int kolona) {
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Unesite marku vozila: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->markaVozila,50);
			cout << "Unesite broj sasije: ";
			cin.getline((*(niz + i) + j)->brojSasije, 20);
			cout << "Unesite tip vozila: ";
			cin >> *(*(niz + i) + j)->tipVozila;
			cout << "Unesite potrosnju goriva: ";
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
			cout << "Vozilo " << j + 1 << endl;
			cout << "Marka vozila: " << (*(niz + i) + j)->markaVozila<<endl;
			cout << "Broj sasije: " << (*(niz + i) + j)->brojSasije << endl;
			do{
				cout << "Tip vozila: " << *(*(niz + i) + j)->tipVozila<<endl;
			} while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
			cout << "Potrosnja goriva: " << *(*(niz + i) + j)->potrosnja_goriva_po_km << endl;
		}
	}
}

float prosjecnaPotrosnjaGorivaC(vozilo** niz, int red, int kolona) {
	float prosjek=0.0;
	int brojac = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->tipVozila == 'C')
			{
				prosjek += *(*(niz + i) + j)->potrosnja_goriva_po_km;
				brojac++;
			}
		}
	}

	return prosjek / brojac;
}
