#include <iostream>
#include <iomanip>
using namespace std;

struct vrijeme {
	float* temperatura;
	float* vlaznostZraka;
	bool* padavine;
	char* vrstaPadavine;
	float* kolicinaPadavine;

	vrijeme()
	{
		temperatura = new float;
		vlaznostZraka = new float;
		padavine = new bool;
		vrstaPadavine = new char[20];
		kolicinaPadavine = new float;
	}

	~vrijeme() {
		delete temperatura; temperatura = nullptr;
		delete vlaznostZraka; vlaznostZraka = nullptr;
		delete padavine; padavine = nullptr;
		delete[] vrstaPadavine; vrstaPadavine = nullptr;
		delete kolicinaPadavine; kolicinaPadavine = nullptr;
	}

	void Unos();
	void Ispis();
};

void vrijeme::Unos()
{
	cout << "Unesite temperaturu: ";
	cin >> *temperatura;
	cout << "Unesite vlaznost zraka: ";
	cin >> *vlaznostZraka;
	cout << "Da li je danas bilo padavina? 1/0: ";
	cin >> *padavine;
	cout << "Uneiste vrstu padavine: ";
	cin.ignore();
	cin.getline(vrstaPadavine, 20);
	cout << "Unesite kolicinu padavine: ";
	cin >> *kolicinaPadavine;
}

void vrijeme::Ispis() {
	cout << "Temperatura: " << *temperatura << endl;
	cout << "Vlaznost vazduha: " << *vlaznostZraka<<endl;
	cout<<"Padavine: " << boolalpha << *padavine<<endl;
	cout << "Vrsta padavine: " << vrstaPadavine << endl;
	cout << "Kolicina padavine: " << *kolicinaPadavine << endl<<endl;
}

void ProsjecnaTemp(vrijeme**, int, int);
float ProsjekSati(vrijeme**, int, int);
int SatSaNajvisomTemp(vrijeme**, int, int);

int main() {
	int red, kolona;
	cout << "Unesite broj dana: ";
	cin >> red;
	cout << "Unesite broj sati: ";
	cin >> kolona;

	vrijeme** niz = new vrijeme * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new vrijeme[kolona];


	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			(*(niz + i)+j)->Unos();
		}
	}

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			(*(niz + i) + j)->Ispis();
		}
	}

	ProsjecnaTemp(niz, red, kolona);
	cout << "Rezultat je: " << ProsjekSati(niz, red, kolona) << endl;
	cout << "Sat sa najvisom temperaturom kroz sve dane je: " << SatSaNajvisomTemp(niz, red, kolona) << endl;

	for (int i = 0; i < red; i++)
	{
		delete[] * (niz + i);
		*(niz + i) = nullptr;
	}
	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}

//ispisati dan sa najvisom prosjecnom temp i najnizom prosjecnom temp
void ProsjecnaTemp(vrijeme** niz, int red , int kolona)
{
	float* prosjeci = new float[red] {};
	int index_najnize = 0, index_najvise = 0;
	float prosjekNajnize = INT_MAX, prosjekNajvise = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) = *(*(niz + i) + j)->temperatura;
		}
		*(prosjeci + i) /= kolona;

		if (*(prosjeci + i) < prosjekNajnize)
		{
			prosjekNajnize = *(prosjeci + i);
			index_najnize = i;
		}

		if (*(prosjeci + i) > prosjekNajvise)
		{
			prosjekNajvise = *(prosjeci + i);
			index_najvise = i;
		}

	}
	cout << "Indeks dana sa najvisom temperaturom je: " << index_najvise << endl;
	cout << "Indeks dana sa najnizom temperaturom je: " << index_najnize << endl;
}

//potrebno je napraviti funkciju koja ce racunati prosjek sati sa temp visom 25.5 a u kojima je bilo padavian u odnosu 
// na broj sati sa temp 25.5 bez padavina

float ProsjekSati(vrijeme** niz, int red, int kolona)
{
	int brojacPadavineTemp = 0, brojacTemp = 0;
	float prosjek = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->temperatura > 25.5)
			{
				brojacTemp++;
				if (*(*(niz + i) + j)->padavine)
				{
					brojacPadavineTemp++;
					prosjek += *(*(niz + i) + j)->temperatura;
				}
			}
		}
	}
	prosjek = (float(brojacPadavineTemp) / brojacTemp) * 100;
	return prosjek;
}

//potrebno je napraviti funkciju koja ce pronaci sat sa najvisom unesenom temperaturom tokom svih dana
int SatSaNajvisomTemp(vrijeme** niz, int red, int kolona)
{
	int index_dana = 0;
	float* prosjecneTempPoSatu = new float[red] {};
	float najvecaTemp = 0.0;

	for (int i = 0; i < kolona; i++)
	{
		for (int j = 0; j < red; j++)
		{
			*(prosjecneTempPoSatu + i) += *(*(niz + j) + i)->temperatura;
		}
		*(prosjecneTempPoSatu + i) /= red;

		if (*(prosjecneTempPoSatu + i) > najvecaTemp)
		{
			najvecaTemp = *(prosjecneTempPoSatu + i);
			index_dana = i;
		}
	}
	delete[] prosjecneTempPoSatu; prosjecneTempPoSatu = nullptr;
	return index_dana;
}
