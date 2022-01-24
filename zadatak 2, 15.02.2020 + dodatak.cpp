#include <iostream>
#include <cmath>
using namespace std;

struct datum {
	int dan, mjesec, godina;
	void Unos()
	{
		cout << "Unesite dan: ";
		cin >> dan;
		cout << "Unesite mjesec: ";
		cin >> mjesec;
		cout << "Unesite godinu: ";
		cin >> godina;
	}

	void Ispis()
	{
		cout << "Datum: "<<dan<<"."<<mjesec<<"."<<godina<<endl;	
	}
};

struct vremenska_prognoza
{
	char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
	float* temperatura;
	float* vlaznost_vazduha;
	datum d;

	vremenska_prognoza() {
		padavine = new char[20];
		temperatura = new float;
		vlaznost_vazduha = new float;
	}

	~vremenska_prognoza() {
		delete[] padavine; padavine = nullptr;
		delete temperatura; temperatura = nullptr;
		delete vlaznost_vazduha; vlaznost_vazduha = nullptr;
	}
};

void Unos(vremenska_prognoza** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Unesite naziv padavine: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->padavine, 20);
			cout << "Unesite temperaturu: ";
			cin >> *(*(niz + i) + j)->temperatura;
			cout << "Unesite vlaznost vazduha: ";
			cin >> *(*(niz + i) + j)->vlaznost_vazduha;
			cout << "Unesite datum: \n";
			(*(niz + i) + j)->d.Unos();
		}
	}
}

void Ispis(vremenska_prognoza** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Meteorolog " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Dan " << j + 1 << endl;
			cout << "Naziv padavine: " << (*(niz + i) + j)->padavine << endl;
			cout << "Temperatura: " << *(*(niz + i) + j)->temperatura << endl;
			cout << "Vlaznost vazduha: " << *(*(niz + i) + j)->vlaznost_vazduha << endl;
			(*(niz + i) + j)->d.Ispis();
			cout << endl;
		}
		cout << "-------------------------------------------------------------\n";
	}
}

void UnosStvarnih(float* niz, int vel)
{
	cout << "Unesite stvarne temperature: "<<endl;
	for (int i = 0; i < vel; i++)
	{
		cout << "Dan " << i + 1 << endl;
		cout << "Unesite temperaturu: ";
		cin >> *(niz + i);
	}
}

int NajtacnijiMeteorolog(vremenska_prognoza** matrica, float* niz, int red, int kolona)
{
	float* rezultati = new float[red] {};
	int indeksNajtacnijeg = 0;
	float najmanji = INT_MAX;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(rezultati+i) += abs(*(niz + j))-abs(*matrica[i][j].temperatura);
		}
		if (abs(*(rezultati + i)) < najmanji)
		{
			najmanji = *(rezultati + i);
			indeksNajtacnijeg = i;
		}
	}
	return indeksNajtacnijeg;
}

int main() {
	
	int red, kolona;
	cout << "Unesite broj firmi: ";
	cin >> red;
	cout << "Unesite broj automobila: ";
	cin >> kolona;

	vremenska_prognoza** niz = new vremenska_prognoza * [red];
	float* temperature = new float[kolona];

	for (int i = 0; i < red; i++)
		*(niz + i) = new vremenska_prognoza[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	UnosStvarnih(temperature, kolona );
	cout << "\nNajtacniji meteorolog je " << NajtacnijiMeteorolog(niz, temperature, red, kolona);

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;


	system("pause>0");
	return 0;
}

