#include <iostream>
#include<string.h>
using namespace std;

/*
*	Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa student
	(student je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
	Kompletan 2D niz predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete
	(radi jednostavnosti rješenja podrazumijevati da svaki fakultet ima isti broj studenata).
	Omogućiti korisniku unos svih podataka za sve studente, te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati
	koji je to redni broj fakulteta (index reda sa najvećim prosjekom).
	Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu.
	U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama.
	Obavezno koristiti aritmetiku pokazivača. Obavezno voditi računa o dealociranju dinamički alociranje memorije.
*/

struct student
{
	char* ID = new char[50];
	char* imePrezime = new char[50];
	float* prosjek = new float;

	//void Unos()
	//{
	//	cin.ignore();
	//	cout << "Unesite ID studenta: ";
	//	cin.getline(this->ID, 50);

	//	cout << "Unesite ime i prezime studenta: ";
	//	cin.getline(this->imePrezime, 50);

	//	cout << "Unesite prosjek studenta: ";
	//	cin >> *this->prosjek;

	//	//cin.ignore();
	//}

	void Ispis() {
		cout << "ID: " << this->ID << endl;
		cout << "Ime i prezime: " << this->imePrezime << endl;
		cout << "Prosjek: " << *this->prosjek << endl;
	}

	void Dealociraj() {
		delete[] ID; ID = nullptr;
		delete[] imePrezime; imePrezime = nullptr;
		delete prosjek; prosjek = nullptr;
	}
};

void Unos(student s)
{
	cin.ignore();
	cout << "Unesite ID studenta: ";
	cin.getline(s.ID, 50);
	cout << "Unesite ime i prezime studenta: ";
	cin.getline(s.imePrezime, 50);
	cout << "Unesite prosjek studenta: ";
	cin >> *s.prosjek;
}

float Prosjek(student* niz, int kolona)
{
	float suma = 0.0;
	for (int i = 0; i < kolona; i++)
	{
		suma += *niz[i].prosjek;
	}
	return suma / kolona;
}

void UniSaMaxProsjekom(student** matrica, int red, int kolona)
{
	float prosjek = 0.0;
	int pozicija=0;
	for (int i = 0; i < red; i++)
	{
		if (Prosjek(matrica[i] , kolona)>prosjek){
			prosjek = Prosjek(matrica[i], kolona);
			pozicija = i;
		}
	}
	cout << "Fakultet sa najvecim prosjekom se nalazi na rednom broju " << (pozicija + 1) << " odnosno na indeksu " << pozicija << endl;
}

void ID_najbolji(student** matrica, int red, int kolona)
{
	float prosjek = 0.0;
	char* ID=new char[50];
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if ((*(*(matrica + i) + j)->prosjek) > prosjek)
			{
				prosjek = (*(*(matrica + i) + j)->prosjek);
				strcpy_s(ID, 50, matrica[i][j].ID);
			}
		}
	}
	cout << "ID najboljeg studenta je: " << ID << endl;
}

int main() {
	int red, kolona;
	cout << "Unesite dimenzije niza: ";
	cin >> red >> kolona;
	student** matrica = new student*[red];

	for (int i = 0; i < red; i++)
		*(matrica + i) = new student[kolona];

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			Unos(*(*(matrica+i)+j));
		}
	}

	system("cls");

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			(*(*(matrica + i) + j)).Ispis();
		}
	}

	cout << endl;

	UniSaMaxProsjekom(matrica, red, kolona);

	cout << endl;

	ID_najbolji(matrica, red, kolona);

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			(*(*(matrica+i)+j)).Dealociraj();
		}
	}

	delete[] matrica; matrica = nullptr;

	system("pause>0");
	return 0;
}
