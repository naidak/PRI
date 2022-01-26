#include <iostream>
using namespace std;

struct fudbaler
{
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;

	fudbaler() {
		godRodjenja = new int;
		brojIgraca = new int;
		golovi = new int;
	}

	~fudbaler() {
		delete godRodjenja; godRodjenja = nullptr;
		delete brojIgraca; brojIgraca = nullptr;
		delete golovi; golovi = nullptr;
	}
};

void Unos(fudbaler**, int, int);
void Ispis(fudbaler**, int, int);
int NajboljiTim(fudbaler**, int, int,int&);
int NajlosijiTimNajboljiIgrac(fudbaler**, int, int);

int main() {
	
	int red, kolona;
	cout << "Unesite broj klubova: ";
	cin >> red;
	cout << "Unesite broj fudbalera: ";
	cin >> kolona;

	fudbaler** niz = new fudbaler * [red];

	for (int i = 0; i < red; i++)
		*(niz + i) = new fudbaler[kolona];

	Unos(niz, red, kolona);
	Ispis(niz, red, kolona);
	int indeks_najlosijeg_tima = 0;
	cout << "Indeks najboljeg tima je " << NajboljiTim(niz, red, kolona, indeks_najlosijeg_tima)<<endl;
	cout << "Najbolji igrac u najlosijem timu koji ima indeks " << indeks_najlosijeg_tima << " je igrac broj " << NajlosijiTimNajboljiIgrac(niz, indeks_najlosijeg_tima, kolona) + 1 << endl;

	for (int i = 0; i < red; i++)
		delete[] *(niz + i);

	delete[] niz;


	system("pause>0");
	return 0;
}

void Unos(fudbaler** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			 *(*(niz + i) + j)->godRodjenja= 1980 + rand() % ((2000 + 1) - 1980);
			 *(*(niz + i) + j)->brojIgraca= rand() % 30 + 1;
			 *(*(niz + i) + j)->golovi= rand() % 5;
		}
	}
}

void Ispis(fudbaler** niz, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		cout << "Klub " << i + 1 << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Fudbaler " << j + 1 << endl;
			cout << "Godina rodjenja: " << *(*(niz + i) + j)->godRodjenja << endl <<
				"Broj igraca: " << *(*(niz + i) + j)->brojIgraca << endl <<
				"Golovi: " << *(*(niz + i) + j)->golovi << endl<<endl;
		}
		cout << "----------------------------------------------------------------------------\n";
	}
}

// te napraviti (i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom. 
//Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova.

int NajboljiTim(fudbaler** niz, int red, int kolona,int &indeks_najlosijeg)
{
	float* prosjeci = new float[red] {};
	int indeks_najboljeg=0;
	float max_prosjek = 0;
	float min_prosjek = INT_MAX;

	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(prosjeci + i) += *(*(niz + i) + j)->golovi;
		}
		*(prosjeci + i) /= kolona;
		if (*(prosjeci + i) > max_prosjek)
		{
			max_prosjek = *(prosjeci + i);
			indeks_najboljeg = i;
		}
		if (*(prosjeci + i) < min_prosjek)
		{
			min_prosjek = *(prosjeci + i);
			indeks_najlosijeg = i;
		}
	}
	delete[] prosjeci; prosjeci = nullptr;
	return indeks_najboljeg;
}

int NajlosijiTimNajboljiIgrac(fudbaler** niz, int red, int kolona)
{
	int indeks_najboljeg = 0;
	int golovi_najboljeg = 0;

	for (int j = 0; j < kolona; j++)
	{
		if (*(*(niz + red) + j)->golovi > golovi_najboljeg)
		{
			golovi_najboljeg = *(*(niz + red) + j)->golovi;
			indeks_najboljeg = j;
		}
	}
	return indeks_najboljeg;
}
