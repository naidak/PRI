#include <iostream>
using namespace std;

struct vremenska_prognoza
{
    char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float* temperatura;
    float* vlaznost_vazduha;

    vremenska_prognoza() {
        padavine = new char[20];
        temperatura = new float;
        vlaznost_vazduha = new float;
    }

    void Unos()
    {
        cin.ignore();
        cout << "   Unesite naziv padavine: ";
        cin.getline(padavine, 20);
        cout << "   Unesite temperaturu: ";
        cin >> *temperatura;
        cout << "   Unesite vlaznost vazduha: ";
        cin >> *vlaznost_vazduha;
    }

    void Ispis() {
        cout << "   Padavina: " << padavine<<endl;
        cout << "   Temperatura: " << *temperatura << endl;
        cout << "   Vlaznost vazduha: " << *vlaznost_vazduha << endl;
    }

    ~vremenska_prognoza() {
        delete[] padavine; padavine = nullptr;
        delete temperatura; temperatura = nullptr;
        delete vlaznost_vazduha; vlaznost_vazduha = nullptr;
    }
};

void indexNajtacnijeg(vremenska_prognoza** niz, float* tacneTemp, int red, int kolona)
{
    float* sume = new float[red] {};

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(sume + i) += (*niz[i][j].temperatura - tacneTemp[j]);
        }
    }

    int indeks_najtacnijeg = 0;
    float najmanja_suma = abs(*sume);

    for (int i = 0; i < red; i++)
    {
        if ((abs(*(sume + i))) < najmanja_suma)
        {
            najmanja_suma = *(sume + i);
            indeks_najtacnijeg = i;
        }
    }

    cout << "\nIndeks najtacnijeg meteorologa je: " << indeks_najtacnijeg + 1 << endl;
}

int main() {
    int red, kolona;
    cout << "Unesite broj meteorologa: ";
    cin >> red;
    cout << "Unesite broj dana: ";
    cin >> kolona;

    vremenska_prognoza** niz = new vremenska_prognoza * [red];

    for (int i = 0; i < red; i++)
        *(niz + i) = new vremenska_prognoza[kolona];

    float* stvarnaTemp = new float[kolona];

    for (int i = 0; i < red; i++)
    {
        cout << "Meteorolog " << i+1<<endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << "Dan " << j + 1 << endl;
            (*(*(niz+i)+j)).Unos();
        }
        cout << "-----------------------------------------------------\n";
    }

    for (int i = 0; i < red; i++)
    {
        cout << "Meteorolog " << i+1 << endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << "Dan " << j + 1 << endl;
            (*(*(niz + i) + j)).Ispis();
        }
        cout << "-----------------------------------------------------\n";
    }

    cout << "Unesite tacne temperature: " << endl;
    for (int i = 0; i < kolona; i++)
    {
        cout << "Dan " << i + 1 << endl;
        cin >> *(stvarnaTemp + i);
    }

    indexNajtacnijeg(niz, stvarnaTemp, red, kolona);

    for (int i = 0; i < red; i++)
        delete[] * (niz + i);

    delete[] niz;
    delete[] stvarnaTemp;
    niz = nullptr;
    stvarnaTemp = nullptr;

	system("pause>0");
	return 0;
}
