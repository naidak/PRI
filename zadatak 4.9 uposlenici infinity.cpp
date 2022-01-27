#include <iostream>
using namespace std;

struct uposlenik
{
	char* ID;
	char* imePrezime;
	float* plata;

	uposlenik()
	{
		ID = new char[20];
		imePrezime = new char[40];
		plata = new float;
	}

	~uposlenik()
	{
		delete[] ID; ID = nullptr;
		delete[] imePrezime; imePrezime = nullptr;
		delete plata; plata = nullptr;
	}
};

void Unos(uposlenik** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Odjel " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Uposlenik " << j + 1 << endl;
			cout << "Unesite ID: ";
			cin.ignore();
			cin.getline((*(niz + i) + j)->ID, 20);
			cout << "Unesite ime i prezime: ";
			cin.getline((*(niz + i) + j)->imePrezime, 40);
			cout << "Unesite platu: ";
			cin >> *(*(niz + i) + j)->plata;
		}
	}
}

void NajveciProsjekPlate(uposlenik** niz, int red, int kolona)
{
	float* prosjeci = new float[red] {};
	float najveci_prosjek = 0.0;
	int index_najveceg = 0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) += *(*(niz + i) + j)->plata;
		}

		*(prosjeci + i) /= kolona;

		if (*(prosjeci + i) > najveci_prosjek)
		{
			najveci_prosjek = *(prosjeci + i);
			index_najveceg = i;
		}
	}

	cout << "Odjel sa najvecim prosjekom plate ima indeks: " << index_najveceg << " i prosjecna plata iznosi: " << najveci_prosjek<<endl;
}

int main() {
	int red, kolona;
	cout << "Unesite broj odjela: ";
	cin >> red;
	cout << "Unesite broj uposlenika: ";
	cin >> kolona;

	uposlenik** niz = new uposlenik * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new uposlenik[kolona];

	Unos(niz, red, kolona);
	NajveciProsjekPlate(niz, red, kolona);

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz; niz = nullptr;

	system("pause>0");
	return 0;
}
