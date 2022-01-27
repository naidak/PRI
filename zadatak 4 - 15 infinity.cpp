#include <iostream>
using namespace std;

struct fudbaler {
	int ID;
	char* ime_i_Prezime;
	char* pozicija;//prihvati samo slova N, O i V (napad, vezni i odbrana);
	int* broj_golova;

	fudbaler() {
		ID = 0;
		ime_i_Prezime = new char[40];
		pozicija = new char;
		broj_golova = new int;
	}

	~fudbaler() {
		delete[] ime_i_Prezime; ime_i_Prezime = nullptr;
		delete pozicija; pozicija = nullptr;
		delete broj_golova; broj_golova = nullptr;
	}
};

void Unos(fudbaler** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Klub " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Fudbaler " << j + 1 << endl;
			cout << "Unesite ID: ";
			cin >> (*(niz + i) + j)->ID;
			cout << "Unesite ime i prezime: ";
			cin >> (*(niz + i) + j)->ime_i_Prezime;
			do{
			cout << "Unesite poziciju: ";
			cin >> *(*(niz + i) + j)->pozicija;
			} while (*(*(niz + i) + j)->pozicija != 'N' && *(*(niz + i) + j)->pozicija != 'V' && *(*(niz + i) + j)->pozicija != 'O');
			cout << "Unesite broj golova: ";
			cin >> *(*(niz + i) + j)->broj_golova;
		}
	}
}

void GoloviPoPoziciji(fudbaler** niz, int red, int kolona)
{
	int brojacN = 0, brojacV = 0, brojacO = 0;
	float prosjekN = 0.0, prosjekV = 0.0, prosjekO = 0.0;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->pozicija == 'N')
			{
				brojacN++;
				prosjekN += *(*(niz + i) + j)->broj_golova;
			}
			else if (*(*(niz + i) + j)->pozicija == 'V')
			{
				brojacV++;
				prosjekV += *(*(niz + i) + j)->broj_golova;
			}
			else
			{
				brojacO++;
				prosjekO += *(*(niz + i) + j)->pozicija;
			}
		}
	}
	cout << "Prosjek postignutih golova na poziciji N iznosi: " << prosjekN / brojacN << endl;
	cout << "Prosjek postignutih golova na poziciji V iznosi: " << prosjekV / brojacV << endl;
	cout << "Prosjek postignutih golova na poziciji O iznosi: " << prosjekO / brojacO << endl;
}

void NajboljiProsjekPoPoziciji(fudbaler** niz, int red, int kolona,char izbor)
{
	float* prosjeci = new float[red] {};

	int indeks = 0;
	float najbolji_prosjek = 0.0;

	for (int i = 0; i < red; i++)
	{
		int brojac = 0;
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->pozicija == izbor)
			{
				*(prosjeci + i) += *(*(niz + i) + j)->broj_golova;
				brojac++;
			}
		}
		*(prosjeci + i) /= brojac;

		if (*(prosjeci + i) > najbolji_prosjek)
		{
			najbolji_prosjek = *(prosjeci + i);
			indeks = i;
		}
	}
	cout << "Tim sa najvecim prosjekom golova na odabranoj poziciji " << izbor << " je tim " << indeks<<endl;
}

int main() {
	int red,  kolona;
	cout << "Unesite broj timova: ";
	cin >> red;
	cout << "Unesite broj igraca: ";
	cin >> kolona;

	fudbaler** niz = new fudbaler * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new fudbaler[kolona];

	Unos(niz, red, kolona);
	GoloviPoPoziciji(niz, red, kolona);
	cout << "Unesite poziciju (N, V, O):";
	char izbor;
	do
	{
		cin >> izbor;
	} while (izbor!='N' && izbor!='V' && izbor!='O');

	NajboljiProsjekPoPoziciji(niz, red, kolona, izbor);

	for (int i = 0; i < red; i++)
		delete[] * (niz + i);

	delete[] niz;

	system("pause>0");
	return 0;
}
