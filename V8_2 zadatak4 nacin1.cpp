#include <iostream>

using namespace std;

/*
o Kreirati strukturu ucenik koja ima sljedeća obilježja: pokazivač redni broj, pokazivač
ime i prezime i pokazivač prosjek;
o Kreirati dinamički niz objekata tipa ucenik;
o Omogućiti unos elemenata;
o Omogućiti ispis elemenata;
o Pronaći učenika s najvećim prosjekom;
o Ne zaboravite dealocirati memoriju;
*/

struct Ucenik {
	int* redniBroj;
	char* imePrezime;
	float* prosjek;

	void Unos()
	{
		char temp[50];
		int rb;
		float pr;
		cout << "Unesite redni broj: ";
		cin >> rb;
		redniBroj = new int;
		*redniBroj = rb;
		cout << "Unesite ime i prezime: ";
		cin.ignore();
		cin.getline(temp, 50);
		imePrezime = new char[strlen(temp) + 1];
		strcpy_s(imePrezime, strlen(temp) + 1, temp);
		cout << "Unesite prosjek: ";
		cin >> pr;
		prosjek = new float;
		*prosjek = pr;
		cout << endl;
	}

	void Ispis() {
		cout << "Redni broj: " << *redniBroj<<endl;
		cout << "Ime i prezime: " << imePrezime<<endl;
		cout << "Prosjek: " << *prosjek<<endl;
	}

	void Dealociraj() {
		delete redniBroj;
		redniBroj = nullptr;
		delete[] imePrezime;
		imePrezime = nullptr;
		delete prosjek;
		prosjek = nullptr;
	}
};

Ucenik najveciProsjek(Ucenik* ucenici, int vel)
{
	Ucenik max_prosjek = ucenici[0];
	for (int i = 0; i < vel; i++)
	{
		if (ucenici[i].prosjek > max_prosjek.prosjek)
			max_prosjek = ucenici[i];
	}
	return max_prosjek;
}

int main()
{
	int vel = 3;
	Ucenik* ucenici = new Ucenik[vel];
	for (int i = 0; i < vel; i++)
	{
		ucenici[i].Unos();
	}
	cout << "------------------------------------------------------" << endl;

	for (int i = 0; i < vel; i++)
	{
		 ucenici[i].Ispis();
	}

	cout << "Ucenik sa najvecim prosjekom je: " << najveciProsjek(ucenici, vel).imePrezime << endl;

	for (int i = 0; i < vel; i++)
	{
		ucenici[i].Dealociraj();
	}

	system("pause>0");
	return 0;
}
