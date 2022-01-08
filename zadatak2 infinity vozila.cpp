#include <iostream>
using namespace std;

struct vozilo
{
    char* markaVozila;
    char* brojSasije;
    char* tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int* kubnihCM;

    vozilo() {
        markaVozila = new char[50];
        brojSasije = new char[20];
        tipVozila = new char[2]; // 2 zbog nulterminirajuceg znaka
        kubnihCM = new int;
    }

    ~vozilo() {
        delete[] markaVozila;
        delete[] brojSasije;
        delete[] tipVozila;
        delete kubnihCM;
        markaVozila = nullptr; brojSasije = nullptr; tipVozila = nullptr; kubnihCM = nullptr;
    }
};

void Unos(vozilo** v, int red, int kolona)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            cout << "Unesite marku vozila: " ;
            cin.getline((*(v + i) + j)->markaVozila, 50);
            cout << "Unesite broj sasije: ";
            cin.getline((*(v + i) + j)->brojSasije, 20);
            do{
            cout << "Unesite tip vozila: ";
            cin.getline((*(v + i) + j)->tipVozila, 2);
            } while (*(*(v + i) + j)->tipVozila != 'A' && *(*(v + i) + j)->tipVozila != 'B' && *(*(v + i) + j)->tipVozila != 'C');
            cout << "Unesite kubne cm: ";
            cin >> *(*(*(v + i) + j)).kubnihCM;
            cout << "---------------------------------------------------\n";
        }
    }
}

void Ispis(vozilo* v, int kolona)
{
    for (int i = 0; i < kolona; i++)
    {
        cout << "Marka vozila: " << (v+i)->markaVozila << endl;
        cout << "Broj sasije: " <<(v + i)->brojSasije << endl;
        cout << "Tip vozila: " << (v + i)->tipVozila << endl;
        cout << "Kubni CM: " << *(v + i)->kubnihCM << endl;
        cout << endl;
    }
}

//Napisati i testirati funkciju koja će pronaći (firmu) koja ima največu prosječnu kubikazu vozila (prosjek vrijednosti kubnihCM).
float* ProsjeciKubikaza(vozilo** niz, int red, int kolona)
{
    float* prosjeci = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(prosjeci + i) += *(*(niz + i) + j)->kubnihCM;
        }
        *(prosjeci + i) /= kolona;
    }

    return prosjeci;
}

void NajvecaProsjecnaKubikaza(vozilo** niz, float* prosjeci, int red, int kolona)
{
    int indeks_najveceg = 0;
    float prosjek_najveceg = 0.0;

    for (int i = 0; i < red; i++)
    {
        if (*(prosjeci + i) > prosjek_najveceg)
        {
            prosjek_najveceg = *(prosjeci + i);
            indeks_najveceg = i;
        }
    }

    cout << "Firma sa najvecim prosjekom kubikaze je na poziciji " << indeks_najveceg + 1 << " i vrijednost prosjecne kubikaze je " << prosjek_najveceg << endl;
    cout << "Auta koja se nalaze u toj firmi su: " << endl;
    Ispis(*(niz + indeks_najveceg), kolona);
}
//Zatim napisati i testirati funkciju koja će pronaći i ispisati porosječnu kubikažu vozila 
//(prosjek vrijednosti kubnihCM) svih vozila tipova "A" te posebno svih vozila tipa "B" u cijeloj matrici

void prosjecnaKubikazaVozilaPoTipu(vozilo** niz, int red, int kolona)
{
    float prosjekA = 0.0;
    float prosjekB = 0.0;
    int brojacA = 0, brojacB = 0;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'A')
            {
                prosjekA += *niz[i][j].kubnihCM;
                brojacA++;
            }
            else if (*(*(niz + i) + j)->tipVozila == 'B')
            {
                prosjekB += *niz[i][j].kubnihCM;
                brojacB++;
            }
        }
    }

    cout << "Prosjecna kubikaza vozila tipa A je: " << prosjekA / float(brojacA) << endl;
    cout << "Prosjecna kubikaza vozila tipa B je: " << prosjekB / float(brojacB) << endl;
}

int main() {
    int red, kolona;
    cout << "Unesite dimenzije 2D niza: " << endl;
    cin >> red >> kolona;

    vozilo** vozila = new vozilo*[red];

    for (int i = 0; i < red; i++)
        *(vozila + i) = new vozilo[kolona];

    Unos(vozila, red, kolona);

    for (int i = 0; i < red; i++)
        Ispis(*(vozila + i), kolona);

    NajvecaProsjecnaKubikaza(vozila, ProsjeciKubikaza(vozila, red, kolona), red, kolona);
    cout << endl;
    prosjecnaKubikazaVozilaPoTipu(vozila, red, kolona);

    for (int i = 0; i < red; i++)
        delete[] * (vozila + i);

    delete[] vozila;

	system("pause>0");
	return 0;
}
