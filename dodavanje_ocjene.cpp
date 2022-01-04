#include <iostream>
using namespace std;

struct Ucenik {
	char* Ime;
	char* Prezime;
	int* NizOcjena;
	int TrenutnoOcjena;

	void Unos() {
		char temp[50];
		cout << "Unesite ime ucenika: ";
		cin.getline(temp, 50);
		Ime = new char[strlen(temp) + 1];
		strcpy_s(Ime, strlen(temp) + 1, temp);
		cout << "Unesite prezime ucenika: ";
		cin.getline(temp, 50);
		Prezime = new char[strlen(temp) + 1];
		strcpy_s(Prezime, strlen(temp) + 1, temp);

		TrenutnoOcjena = 0;
	}

	void Ispis()
	{
		cout << "Ime: " << Ime << endl;
		cout << "Prezime: " << Prezime << endl;
		cout << "Ocjene: ";
		for (int i = 0; i < TrenutnoOcjena; i++)
		{
			cout << NizOcjena[i] << " ";
		}
	}

	void DodajOcjenu(int ocjena)
	{
		int* temp = new int[TrenutnoOcjena + 1];
		for (int i = 0; i < TrenutnoOcjena; i++)
		{
			temp[i] = NizOcjena[i];
		}

		temp[TrenutnoOcjena] = ocjena;

		if(TrenutnoOcjena>0)
			delete[] NizOcjena;

		NizOcjena = temp;
		TrenutnoOcjena++;
	}

	void Dealociraj() {
		delete[] Ime;
		Ime = nullptr;
		delete[] Prezime;
		Prezime = nullptr;
		delete[] NizOcjena;
		NizOcjena = nullptr;
	}
};

int main() {
	Ucenik u;
	u.Unos();
	u.DodajOcjenu(5);
	u.Ispis();

	system("pause>0");
	return 0;
}
