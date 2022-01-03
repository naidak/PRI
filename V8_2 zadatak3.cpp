#include <iostream>

using namespace std;

/*
--Kreirati strukturu obuća koja ima sljedeća obilježja: veličina, boja, model;
--Kreirati dinamički niz objekata tipa obuća
--Omogućiti unos elemenata
--Omogućiti ispis elemenata
--Utvrditi koliko je objekata tipa obuća za obilježja model ima vrijednost sandale;
--Ispisati adrese svih objekata za koje prethodnom funkcijom utvrdite da su sandale;
--Ne zaboravite dealocirati memoriju;
--Koristite funkcije.
*/

struct Obuca {
	int velicina;
	char boja[50];
	char model[50];

	void Unos()
	{
		cout << "Unesite velicinu: ";
		cin >> this->velicina;
		cin.ignore();
		cout << "Unesite boju: ";
		cin.getline(this->boja, 50);
		cout << "Unesite model: ";
		cin.getline(this->model, 50);
		cout << endl;
	}

	void Ispis()
	{
		cout << "Velicina: " << this->velicina<<endl;
		cout << "Boja: " << this->boja << endl;
		cout << "Model: " << this->model<<endl;
	}
};

int Sandale(Obuca* o, int vel)
{
	int brojac = 0;
	for (int i = 0; i < vel; i++)
	{
		if (strcmp(o[i].model,"sandale"))
		{
			cout << "Adresa obuce koja ima model sandale: " << (o + i) << " ---> pozicija u nizu: " << (i+1) << endl;
			brojac++;
		}
	}	
	return brojac;
}
	


int main()
{
	int vel;
	cout << "Unesite velicinu niza: ";
	cin >> vel;
	Obuca* o = new Obuca[vel];

	for (int i = 0; i < vel; i++)
	{
		o->Unos();
	}

	for (int i = 0; i < vel; i++)
	{
		o->Ispis();
	}
	system("cls");
	int brojSandala = Sandale(o, vel);
	cout << "Broj modela sandale je: " << brojSandala<<endl;
	
	delete[] o;

	system("pause>0");
	return 0;
}
