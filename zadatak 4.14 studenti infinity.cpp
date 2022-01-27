#include <iostream>
using namespace std;

struct student
{
	char* ID;
	char* imePrezime;
	float* prosjek;

	student() {
		ID = new char[20];
		imePrezime = new char[50];
		prosjek = new float;
	}

	~student() {
		delete[] ID; ID = nullptr;
		delete[] imePrezime; imePrezime = nullptr;
		delete prosjek;
	}
};

void Unos(student** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Student " << j + 1 << endl;
			cout << "Unesite ID: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->ID, 20);
			cout << "Unesite ime i prezime: ";
			cin.getline((*(niz + i) + j)->imePrezime, 40);
			cout << "Unesite prosjek: ";
			cin >> *(*(niz + i) + j)->prosjek;
		}
	}
}

/*
	te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati koji je to redni broj fakulteta 
	(index reda sa najvećim prosjekom). 
	Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu.
*/

void NajboljiFakultet(student** niz, int red, int kolona)
{
	int index = 0;
	float* prosjeci = new float[red] {};
	float najveciProsjek = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) = *(*(niz + i) + j)->prosjek;
		}
		*(prosjeci + i) /= kolona;

		if (*(prosjeci + i) > najveciProsjek)
		{
			najveciProsjek = *(prosjeci + i);
			index = i;
		}
	}
	cout << "Fakultet sa najboljim prosjekom je fakultet sa indexom " << index << endl;
}

void NajboljiStudent(student** niz, int red, int kolona)
{
	float najboljiProsjek = 0.0;
	char* IB = new char[20];

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->prosjek > najboljiProsjek)
			{
				najboljiProsjek = *(*(niz + i) + j)->prosjek;
				strcpy_s(IB, 20, (*(niz + i) + j)->ID);
			}
		}
	}
	cout << "Student sa najboljim prosjekom ima ID " << IB << endl;
}

int main() {
	int red,  kolona;
	cout << "Unesite broj fakulteta: ";
	cin >> red;
	cout << "Unesite broj studenata: ";
	cin >> kolona;

	student** niz = new student * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new student[kolona];

	Unos(niz, red, kolona);
	NajboljiFakultet(niz, red, kolona);
	NajboljiStudent(niz, red, kolona);

	for (int i = 0; i < red; i++)
		delete[] * (niz + i);

	delete[] niz;

	system("pause>0");
	return 0;
}
