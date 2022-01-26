#include <iostream>
#include <cmath>
using namespace std;

struct vozilo
{
	char* markaVozila;
	char* brojSasije;
	char* tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
	int* kubnihCM;

	vozilo() {
		markaVozila = new char[50];
		brojSasije = new char[20];
		tipVozila = new char;
		kubnihCM = new int;
	}

	~vozilo() {
		delete[] markaVozila;
		delete[] brojSasije;
		delete tipVozila;
		delete kubnihCM;
		markaVozila = nullptr;
		brojSasije = nullptr;
		tipVozila = nullptr;
		kubnihCM = nullptr;
	}
};

void Unos(vozilo**, int, int);
void Ispis(vozilo**, int, int);
int NajvecaProsjecnaKubikaza(vozilo**, int, int);
void ProsjecnaKubikazaAB(vozilo**, int, int);

int main() {
	
	int red, kolona;
	cout << "Unesite broj klubova: ";
	cin >> red;
	cout << "Unesite broj fudbalera: ";
	cin >> kolona;

	vozilo** niz = new vozilo * [red];
	float* temperature = new float[kolona];

	for (int i = 0; i < red; i++)
		*(niz + i) = new vozilo[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	cout << "Firma sa najboljim prosjekom je firma broj: " << NajvecaProsjecnaKubikaza(niz, red, kolona)+1<<endl;
	ProsjecnaKubikazaAB(niz, red, kolona);

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
			cout << "Unesite kubikazu: ";
			cin >> *(*(niz + i) + j)->kubnihCM;
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
			cout << "Tip vozila: " << *(*(niz + i) + j)->tipVozila<<endl;
			cout << "Kubikaza: " << *(*(niz + i) + j)->kubnihCM << endl;
		}
	}
}

//Napisati i testirati funkciju koja će pronaći (firmu) koja ima najvecu prosječnu kubikazu vozila (prosjek vrijednosti kubnihCM).
int NajvecaProsjecnaKubikaza(vozilo** niz, int red, int kolona) {
	float* prosjeci = new float[red] {};
	int indeks_najveceg = 0;
	float najveci = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) += *(*(niz + i) + j)->kubnihCM;
		}

		*(prosjeci + i) /= kolona;

		if (*(prosjeci + i) > najveci)
		{
			najveci = *(prosjeci + i);
			indeks_najveceg = i;
		}
	}
	delete[] prosjeci; prosjeci=nullptr;
	return indeks_najveceg;
}

//Zatim napisati i testirati funkciju koja će pronaći i ispisati porosječnu kubikažu vozila
//(prosjek vrijednosti kubnihCM) svih vozila tipova "A" te posebno svih vozila tipa "B" u cijeloj matrici
void ProsjecnaKubikazaAB(vozilo** niz, int red, int kolona)
{
	int brojacA = 0, brojacB = 0;
	float sumaA = 0.0, sumaB = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->tipVozila == 'B')
			{
				brojacB++;
				sumaB += *(*(niz + i) + j)->kubnihCM;
			}
			else if (*(*(niz + i) + j)->tipVozila == 'A')
			{
				brojacA++;
				sumaA += *(*(niz + i) + j)->kubnihCM;
			}
		}
	}

	cout << "Prosjecna kubikaza vozila tipa A u svim firmama je: " << sumaA / float(brojacA)<<endl;
	cout << "Prosjecna kubikaza vozila tipa B u svim firmama je: " << sumaB / float(brojacB) << endl;
}
