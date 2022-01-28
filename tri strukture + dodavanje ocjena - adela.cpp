#include<iostream>
using namespace std;
struct Datum {
	int* _dan, * _mjesec, * _godina;
	void Unos()
	{
		_dan = new int;
		_mjesec = new int;
		_godina = new int;
		cout << "Unesite dan: ";
		cin >> *_dan;
		cout << "Unesite mjesec: ";
		cin >> *_mjesec;
		cout << "Unesite godinu: ";
		cin >> *_godina;
	}

	void Ispis()
	{
		cout << "Datum: " << *_dan << "." << *_mjesec << "." << *_godina << endl;
	}

	void Dealociraj()
	{
		delete _dan; _dan = nullptr;
		delete _mjesec; _mjesec = nullptr;
		delete _godina; _godina = nullptr;
	}

	void Dodjeli(Datum d)
	{
		_dan = new int;
		_mjesec = new int;
		_godina = new int;
		*_dan = *d._dan;
		*_mjesec = *d._mjesec;
		*_godina = *d._godina;
	}
};

struct Predmet {
	char* Naziv;
	int ocjena;
	Datum DatumOdgovaranja;
	void Unos()
	{
		char temp[50];
		cout << "Unesite naziv predmeta: ";
		cin.getline(temp, 50);
		Naziv = new char[strlen(temp) + 1];
		strcpy_s(Naziv, strlen(temp) + 1, temp);
		cout << "Unesite ocjenu: ";
		cin >> ocjena;
		cout << "Unesite datum odgovaranja: \n";
		DatumOdgovaranja.Unos();
	}
	void Ispis()
	{
		cout << "Naziv predmeta: " << Naziv << endl;
		cout << "Ocjena: " << ocjena << endl;
	}
	void Dealociraj() {
		delete[] Naziv; Naziv = nullptr;
	}

	void Dodjeli(Predmet p)
	{
		Naziv = new char[strlen(p.Naziv) + 1];
		strcpy_s(Naziv, (strlen(p.Naziv) + 1), p.Naziv);
		ocjena = p.ocjena;
		DatumOdgovaranja.Dodjeli(p.DatumOdgovaranja);
	}
};

struct Ucenik {
	char* ImePrezime;
	Predmet* _listaPredmeta;
	int trenutnoPredmeta;

	void Unos()
	{
		char temp[50];
		cout << "Unesite ime i prezime ucenika: ";
		cin.getline(temp, 50);
		ImePrezime = new char[strlen(temp) + 1];
		strcpy_s(ImePrezime, strlen(temp) + 1, temp);
		trenutnoPredmeta = 0;
	}
	void Ispis()
	{
		cout << "Ime i prezime ucenika: " << ImePrezime<<endl;
		cout << "Predmeti koje je odgovarao: " << endl;
		for (int i = 0; i < trenutnoPredmeta; i++)
		{
			_listaPredmeta[i].Ispis();
		}
	}

	bool DodajPredmet(Predmet p)
	{
		Predmet* tempNiz = new Predmet[trenutnoPredmeta + 1];
		for (int i = 0; i < trenutnoPredmeta; i++)
		{
			tempNiz->Dodjeli(_listaPredmeta[i]);
		}

		tempNiz[trenutnoPredmeta].Dodjeli(p);

		for (int i = 0; i < trenutnoPredmeta; i++)
			_listaPredmeta[i].Dealociraj();
		if (trenutnoPredmeta > 0)
			delete[]_listaPredmeta;
	
		_listaPredmeta = tempNiz;
		trenutnoPredmeta++;
		return true;
	}
	void Dealociraj()
	{
		delete[] ImePrezime; ImePrezime = nullptr;
		for (int i = 0; i < trenutnoPredmeta; i++)
			_listaPredmeta[i].Dealociraj();
		if (trenutnoPredmeta > 0)
		{
			delete[]_listaPredmeta;
			_listaPredmeta = nullptr;
		}
	}
};


int main() {


	system("pause>0");
	return 1;

}
