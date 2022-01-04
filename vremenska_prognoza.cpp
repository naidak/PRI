#include <iostream>
using namespace std;

/*
Kreirati dinamički jednodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza
(prognoza je struktura čija su obilježja data u nastavku). Niz treba biti velicine 7.(7 dana u sedmici)
Unosimo temperature za jednu sedmicu.
Svaki element niza je jedan dan, element na poziciji 0 - ponedjeljak, 1 - utorak itd...

struct vremenska_prognoza
{
	char *padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
	float *temperatura;
	float *vlaznost_vazduha;
}
Omogućiti korisniku unos svih prognoza u niz.
Napraviti naredne globalne funkcije:

1. Napraviti funkciju koja će pronaći i ispisati index dana čija je prognoza dnevnih temperatura bila najveca.
2. Izracunati prosjecnu temperaturu za datu sedmicu.
3. Ispisati dane kada je padao snijeg.
4. Funkciju koja ce provjeriti da li nas ocekuje kisan vikend(subota ili nedjelja da je kisa, ili oba dana)
*/

struct vremenska_prognoza
{
	char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
	float* temperatura;
	float* vlaznost_vazduha;

	void Unos()
	{
		padavine = new char[20];
		cout << "Padavine: ";
		cin.getline(padavine,20);
		cout << "Temperatura: ";
		temperatura = new float;
		cin >> *temperatura;
		cout << "Vlaznost vazduha: ";
		vlaznost_vazduha = new float;
		cin >> *vlaznost_vazduha;
		cin.ignore();
	}

	void Ispis()
	{
		cout << "Padavine: " << padavine << endl;
		cout << "Temperatura: " << *temperatura<<endl;
		cout << "Vlaznost vazduha: " << *vlaznost_vazduha << endl<<endl;
	}

	void Dealociraj()
	{
		delete[] padavine;
		padavine = nullptr;
		delete vlaznost_vazduha;
		vlaznost_vazduha = nullptr;
		delete temperatura;
		temperatura = nullptr;
	}
};

void NajvecaTemp(vremenska_prognoza* vp, int vel)
{
	float max_temp=INT8_MIN;
	int max_temp_index=0;
	for (int i = 0; i < vel; i++)
	{
		if (max_temp < *vp[i].temperatura)
		{
			max_temp = *vp[i].temperatura;
			max_temp_index = i;
		}
	}
	cout << "Index dana sa najvecom temperaturom je: " << max_temp_index << endl;
}

float ProsjecnaTemperatura(vremenska_prognoza* vp, int vel)
{
	float suma = 0.0;
	for (int i = 0; i < vel; i++)
	{
		suma += *vp[i].temperatura;
	}
	return (suma / vel);
}

void DaniSaSnijegom(vremenska_prognoza* vp, int vel)
{
	cout << "Podaci o danima sa snijegom: " << endl;
	for (int i = 0; i < vel; i++)
	{
		if (!strcmp(vp[i].padavine, "snijeg"))
			vp[i].Ispis();
	}
}

int main() {
	int vel = 7;
	vremenska_prognoza* vp = new vremenska_prognoza[vel];

	for (int i = 0; i < vel; i++)
		vp[i].Unos();

	system("cls");

	for (int i = 0; i < vel; i++)
		vp[i].Ispis();

	system("cls");

	NajvecaTemp(vp, vel);
	
	cout << "\nProsjecna temperatura u sedmici je: " << ProsjecnaTemperatura(vp, vel) << endl<<endl;

	DaniSaSnijegom(vp, vel);

	for (int i = 0; i < vel; i++)
		vp[i].Dealociraj();

	system("pause>0");
	return 0;
}
