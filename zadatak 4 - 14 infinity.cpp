#include <iostream>
#include <string.h>
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
		delete prosjek; prosjek = nullptr;
	}
};

void Unos(student** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Fakultet " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Student " << i + 1 << endl;
			cout << "Unesite ID: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->ID, 20);
			cout << "Unesite ime i prezime: ";
			cin.getline((*(niz + i) + j)->imePrezime, 50);
			cout << "Unesite prosjek: ";
			cin >> *(*(niz + i) + j)->prosjek;
		}
	}
}

void Ispis(student** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Fakultet " << i + 1 << ":\n";
		for (int j = 0; j < kolona; j++)
		{
			cout << "Ucenik " << j + 1 << ":\n";
			cout<<"ID: " << (*(niz + i) + j)->ID << endl;
			cout << "Ime i prezime: " << (*(niz + i) + j)->imePrezime << endl;
			cout << "Prosjek: " << *(*(niz + i) + j)->prosjek << endl;
		}
		cout << "--------------------------------------------------------------------\n";
	}
}

void NajveciProsjek(student** niz, int red, int kolona)
{
	int index_max = 0;
	float* prosjeci = new float[red] {};
	float prosjek_max = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) += *(*(niz + i) + j)->prosjek;
		}
		*(prosjeci + i) /= kolona;
		if (*(prosjeci + i) > prosjek_max)
		{
			prosjek_max = *(prosjeci + i);
			index_max = i;
		}
	}

	cout << "Indeks fakulteta sa najvecim prosjekom je " << index_max << " a redni broj tog fakulteta je: " << index_max + 1 << "."<<endl;
}

void IspisNjaboljeg(student** niz, int red, int kolona)
{
	float prosjek = 0.0;
	char *IB = new char[20];
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->prosjek > prosjek)
			{
				prosjek = *(*(niz + i) + j)->prosjek;
				strcpy_s(IB, 20, (*(niz + i) + j)->ID);
			}
		}
	}
	cout << "ID najboljeg je: " << IB << endl;
}

int main() {
	int red, kolona;
	cout << "Unesite dimenzije niza: " << endl;
	cin >> red >> kolona;
	student** niz = new student * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new  student[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	NajveciProsjek(niz, red, kolona);
	IspisNjaboljeg(niz, red, kolona);

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}

