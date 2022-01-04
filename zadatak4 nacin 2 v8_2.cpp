#include <iostream>
using namespace std;

/*
Kreirati strukturu ucenik koja ima sljedeća obilježja: pokazivač redni broj, pokazivač
ime i prezime i pokazivač prosjek;
o Kreirati dinamički niz objekata tipa ucenik;
o Omogućiti unos elemenata;
o Omogućiti ispis elemenata;
o Pronaći učenika s najvećim prosjekom;
o Ne zaboravite dealocirati memoriju;
*/

struct Ucenik {
	int* redniBroj=new int;
	char* imePrezime=new char[50];
	float* prosjek = new float;

	void Dealociraj() {
		delete redniBroj;
		redniBroj = nullptr;
		delete[] imePrezime;
		imePrezime = nullptr;
		delete prosjek;
		prosjek = nullptr;
	}
};

void Unos(Ucenik u)
{
	cout << "Unesite redni broj: ";
	cin >> *u.redniBroj;

	cin.ignore();

	cout << "Unesite ime i prezime: ";
	cin.getline(u.imePrezime, 50);

	cout << "Unesite prosjek: ";
	cin >> *u.prosjek;

	cout << endl;
}

void Ispis(Ucenik u)
{
	cout << "Redni broj: " << *u.redniBroj << endl;
	cout << "Ime i prezime: " << u.imePrezime << endl;
	cout << "Prosjek: " << *u.prosjek<<endl;

}

Ucenik najveciProsjek(Ucenik* ucenici, int vel)
{
	float prosjek = 0.0;
	Ucenik u = ucenici[0];
	for (int i = 0; i < vel; i++)
	{
		if (*ucenici[i].prosjek > prosjek)
		{
			prosjek = *ucenici[i].prosjek;
			u = ucenici[i];
		}
	}

	return u;
}

int main() {
	int vel = 3;
	Ucenik* ucenici=new Ucenik[vel];

	for (int i = 0; i < vel; i++)
		Unos(ucenici[i]);
	
	for (int i = 0; i < vel; i++)
		Ispis(ucenici[i]);


	Ucenik ucenikSaMaxProsjekom = najveciProsjek(ucenici, vel);
	cout << "\n------------------------------------------------------------------------\n";
	Ispis(ucenikSaMaxProsjekom);

	for (int i = 0; i < vel; i++)
		ucenici[i].Dealociraj();
	

	system("pause>0");
	return 0;
}
