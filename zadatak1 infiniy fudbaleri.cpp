#include <iostream>
using namespace std;

struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;

    fudbaler() {
        this->godRodjenja = new int;
        this->brojIgraca = new int;
        this->golovi = new int;
    }

    ~fudbaler() {
        delete this->godRodjenja;
        this->godRodjenja = nullptr;
        delete this->brojIgraca;
        this->brojIgraca = nullptr;
        delete this->golovi;
        this->golovi = nullptr;
    }
};

void Dealociraj(fudbaler** niz,int n,int m) {
    for (int i = 0; i < n; i++)
    {
        delete[] * (niz + i);
    }
    delete[] niz;
}

void Unos(fudbaler** niz,int n,int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(niz + i) + j)->godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
            *(*(niz + i) + j)->brojIgraca = rand() % 30 + 1;
            *(*(niz + i) + j)->golovi = rand() % 5;
        }
    }
}

void Ispis(fudbaler** niz,int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Tim " << i + 1 << endl;
        for (int j = 0; j < m; j++)
        {
            cout << "Godina rodjenja: " << *(*(niz+i)+j)->godRodjenja << endl;
            cout << "Broj igraca " << *(*(niz + i) + j)->brojIgraca << endl;
            cout << "Golovi: " << *(*(niz + i) + j)->golovi << endl;
        }
        cout << "----------------------------------------------------\n";
    }
}

void NajveciProsjek(fudbaler** niz, int n, int m)
{
    float* prosjeci = new float[n] {}; // sa {} incijaluzijemo niz, tako da mozemo spremat vrijednosti poslije

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(prosjeci + i) += *(*(niz + i) + j)->golovi;
        }
        *(prosjeci + i) /=m;
    }

    int indeks_najboljeg = 0;
    float najbolji_prosjek = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (*(prosjeci + i) > najbolji_prosjek)
        {
            indeks_najboljeg = i;
            najbolji_prosjek = *(prosjeci + i);
        }
    }

    cout << "Tim sa najvecim prosjekom je tim broj " << indeks_najboljeg + 1 <<" i ima prosjek " <<najbolji_prosjek<< endl;
}

void NajviseGolova(fudbaler** niz, int n, int m)
{
    float* prosjeci = new float[n] {}; // sa {} incijaluzijemo niz, tako da mozemo spremat vrijednosti poslije

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(prosjeci + i) += *(*(niz + i) + j)->golovi;
        }
        *(prosjeci + i) /= m;
    }

    int indeks_najgoreg_tima = 0;
    float najgori_prosjek = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (*(prosjeci + i) < indeks_najgoreg_tima)
        {
            indeks_najgoreg_tima = i;
            najgori_prosjek = *(prosjeci + i);
        }
    }

    int indeks_najboljeg_igraca = 0;
    int brojGolova = 0;
    for (int i = 0; i < m; i++)
    {
        if (*(*(niz + indeks_najgoreg_tima) + i)->golovi > brojGolova)
        {
            brojGolova = *(*(niz + indeks_najgoreg_tima) + i)->golovi;
            indeks_najboljeg_igraca = i;
        }
    }

    cout << "Najbolji igrac: " << endl;
    cout << "Godiste: " << *(*(niz + indeks_najgoreg_tima) + indeks_najboljeg_igraca)->godRodjenja << endl;
    cout << "Broj igraca: " << *(*(niz + indeks_najgoreg_tima) + indeks_najboljeg_igraca)->brojIgraca << endl;
    cout << "Broj golova: " << *(*(niz + indeks_najgoreg_tima) + indeks_najboljeg_igraca)->golovi << endl;
}

void Dealociraj(fudbaler** niz, int n) {
    for (int i = 0; i < n; i++)
    {
        delete[] niz[i];
    }

    // Dealociramo niz pointera na koje pointuje fudbaler** i nullpointujemo fudbaler**
    delete[] niz;
    niz = nullptr;
}

int main() {
    cout << "Unesite dimenzije 2D niza: " << endl;
    int n, m;
    cin >> n >> m;

    fudbaler** niz = new fudbaler* [n];

    for (int i = 0; i < n; i++)
    {
        *(niz + i) = new fudbaler[m];
    }

    Unos(niz, n, m);system("cls");
    Ispis(niz, n, m);

    
    NajveciProsjek(niz, n, m);

    NajviseGolova(niz, n, m);

    Dealociraj(niz, n);

	system("pause>0");
	return 0;
}
