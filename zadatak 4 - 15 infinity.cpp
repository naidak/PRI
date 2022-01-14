#include <iostream>
#include <string.h>
using namespace std;

struct fudbaler {
	int ID;
	char* ime_i_Prezime;
	char* pozicija;//prihvati samo slova N, O i V (napad, vezni i odbrana);
	int* broj_golova;

	fudbaler() {
		this->ime_i_Prezime = new char[50];
		this->pozicija = new char;
		this->broj_golova = new int;
	}

	~fudbaler() {
		delete[] this->ime_i_Prezime; this->ime_i_Prezime = nullptr;
		delete this->pozicija; this->pozicija = nullptr;
		delete this->broj_golova; this->broj_golova = nullptr;
	}
};

void Unos(fudbaler** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Tim " << i + 1 << ":\n";
		for (int j = 0; j < kolona; j++)
		{
			cout << "Fudbaler " << j + 1 << ":\n";
			cout << "Unesite ID: ";
			cin >> (*(niz + i) + j)->ID;
			cout << "Unesite ime i prezime: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->ime_i_Prezime,50);
			do
			{
				cout << "Unesite poziciju (1 - O, 2 - N, 3 - V): ";
				cin >> *(*(niz + i) + j)->pozicija;
			} while (*(*(niz + i) + j)->pozicija!='N' && *(*(niz + i) + j)->pozicija!='V' && *(*(niz + i) + j)->pozicija!='O');
		
			cout << "Unesite broj golova: ";
			cin >> *(*(niz + i) + j)->broj_golova;
		}
	}
}

void Ispis(fudbaler** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Fudbaler " << j + 1 << ":\n";
			cout << "ID: " << (*(niz + i) + j)->ID << endl;
			cout << "Ime i prezime: " << (*(niz + i) + j)->ime_i_Prezime << endl;
			cout << "Pozicija: " << *(*(niz + i) + j)->pozicija << endl;
			cout << "Broj golova: " << *(*(niz + i) + j)->broj_golova << endl;
		}
	}
}

void Prosjek(fudbaler** niz, int red, int kolona)
{
	float* prosjeci = new float[3]{};
	int* brojac = new int[3]{};

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->pozicija == 'O')
			{
				prosjeci[0] += *(*(niz + i) + j)->broj_golova;
				brojac[0]+=1;
			}
			else if(*(*(niz + i) + j)->pozicija == 'N')
			{
				prosjeci[1] += *(*(niz + i) + j)->broj_golova;
				brojac[1] += 1;
			}
			else
			{
				prosjeci[2] += *(*(niz + i) + j)->broj_golova;
				brojac[2] += 1;
			}

		}
	}
	for (int i = 0; i < 3; i++)
	{
		prosjeci[i] /= brojac[i];
		cout << "Prosjek na za poziciju " << i + 1 << " je: " << prosjeci[i]<<endl;
	}
}

void Najbolji(fudbaler** niz, int red, int kolona,char izbor)
{
	float* prosjeci = new float[red] {};
	int* brojaci = new int[red] {};
	int indeks_max=0;
	float prosjek_max = 0.0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->pozicija == izbor)
			{
				prosjeci[i] += *(*(niz + i) + j)->broj_golova;
				brojaci[i] += 1;
			}
		}
		prosjeci[i] /= brojaci[i];
		if (prosjeci[i] > prosjek_max)
		{
			prosjek_max = prosjeci[i];
			indeks_max = i;
		}
	}

	cout << "Tim sa najvecim prosjekom je tim broj: " << indeks_max+1 << " i njegov prosjek za poziciju " << izbor << " je: " << prosjek_max << endl;

	
}

int main() {
	int red, kolona;
	cout << "Unesite dimenzije niza: " << endl;
	cin >> red >> kolona;
	fudbaler** niz = new fudbaler * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new  fudbaler[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	Prosjek(niz, red, kolona);
	Najbolji(niz, red, kolona, 'V');

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}

