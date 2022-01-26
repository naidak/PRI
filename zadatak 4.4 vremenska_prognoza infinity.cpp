#include <iostream>
#include <cmath>
using namespace std;

struct vremenska_prognoza
{
	char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
	float* temperatura;
	float* vlaznost_vazduha;

	vremenska_prognoza() {
		padavine = new char[30];
		temperatura = new float;
		vlaznost_vazduha = new float;
	}

	~vremenska_prognoza() {
		delete[] padavine; padavine = nullptr;
		delete temperatura; temperatura = nullptr;
		delete vlaznost_vazduha; vlaznost_vazduha = nullptr;
	}
};

void Unos(vremenska_prognoza**, int, int);
void Ispis(vremenska_prognoza**, int, int);
void UnosTemperatura(float*, int);
void NajtacnijiMeteorolog(vremenska_prognoza**, float*, int, int);

int main() {
	
	int red, kolona;
	cout << "Unesite broj meteorologa: ";
	cin >> red;
	cout << "Unesite broj dana: ";
	cin >> kolona;

	vremenska_prognoza** niz = new vremenska_prognoza * [red];
	float* temperature = new float[kolona];

	for (int i = 0; i < red; i++)
		*(niz + i) = new vremenska_prognoza[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	UnosTemperatura(temperature, kolona);
	NajtacnijiMeteorolog(niz, temperature, red, kolona);

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;


	system("pause>0");
	return 0;
}

void Unos(vremenska_prognoza** niz, int red, int kolona) {
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Unesite padavinu: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->padavine, 30);
			
			cout << "Unesite temperaturu: ";
			cin >> *(*(niz + i) + j)->temperatura;

			cout << "Unesite vlaznost vazduha: ";
			cin >> *(*(niz + i) + j)->vlaznost_vazduha;
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
			cout << "Padavina: " << (*(niz + i) + j)->padavine<<endl;
			cout << "Temperatura: " << *(*(niz + i) + j)->temperatura << endl;
			cout << "Vlaznost vazduha: " << *(*(niz + i) + j)->vlaznost_vazduha << endl<<endl;
		}
		cout << "--------------------------------------------------------------------------------\n";
	}
}

void UnosTemperatura(float* niz, int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << "Dan " << i + 1 << endl;
		cout << "Unesite temperaturu: ";
		cin >> *(niz + i);
	}
}

/* napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, 
odnosno koji je imao najmanju grešku u procjeni temperatura. 
Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.*/

void NajtacnijiMeteorolog(vremenska_prognoza** niz, float* stvarne_temp, int red, int kolona)
{
	float* rezultati = new float [red] {};
	float najtacniji = INT_MAX; // najblizi nuli je najtacniji
	int indeks_najtacnijeg = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(rezultati + i) += abs(abs(*(stvarne_temp + j)) - abs(*(*(niz + i) + j)->temperatura));
		}

		if (*(rezultati + i) < najtacniji)
		{
			najtacniji = *(rezultati + i);
			indeks_najtacnijeg = i;
		}
	}

	cout << "Indeks najtacnijeg meteorologa je " << indeks_najtacnijeg<<" i njegova greska u procjeni iznosi "<<najtacniji<<endl;
}
