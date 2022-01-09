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
		delete prosjek;
	}
};

void Unos(student** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
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
		cout << "Fakultet " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Student " << j + 1;
			cout << "\n\tID: " << (*(niz + i) + j)->ID << endl;
			cout << "\tIme i prezime: " << (*(niz + i) + j)->imePrezime << endl;
			cout << "\tProsjek: " << *(*(niz + i) + j)->prosjek << endl;
		}
	}
}

void najboljiFakultet(student** niz, int red, int kolona)
{
	float *prosjeci = new float[red] {};
	float max_prosjek = 0.0;
	int index = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) = *(*(niz + i) + j)->prosjek;
		}
		(*(prosjeci + i) )/=kolona;
		if (*(prosjeci + i) > max_prosjek)
		{
			max_prosjek = *(prosjeci + i);
			index = i+1;
		}
	}

	cout << "Indeks fakulteta sa najvecim prosjekom je: " << index << endl;
}

void najboljiStudent(student** niz,int red, int kolona)
{
	int max_ocjena = 0;
	char* id_najboljeg=new char[21];
	
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->prosjek > max_ocjena)
			{
				max_ocjena = *(*(niz + i) + j)->prosjek;
				strcpy_s(id_najboljeg,21, (*(niz + i) + j)->ID);
			}
		}
	}

	cout << "ID najboljeg studenta je: " << id_najboljeg << endl;
}

int main() {
	int red, kolona;
	cout << "Unesite dimenzije 2D niza: " << endl;
	cin >> red >> kolona;

	student** niz = new student * [red];
	
	for (int i = 0; i < red; i++)
		*(niz + i) = new student[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	najboljiFakultet(niz, red, kolona);
	najboljiStudent(niz, red, kolona);


	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}

