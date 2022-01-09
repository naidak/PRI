#include <iostream>
using namespace std;

int brojCifri(int broj)
{
    return int(log10(broj) + 1);
}

void Unos(int** niz, int red, int kolona) {
    bool tacanUnos = false;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            do{
            int broj = rand() % 20+1;
            if((i+j)%2==0 && broj%2==0&& brojCifri(broj)%2==0)
            {
                *(*(niz + i) + j) = broj;
                tacanUnos = true;
            }
            else if((i + j) % 2 != 0 && broj % 2 != 0 && brojCifri(broj) % 2 != 0)
            {
                *(*(niz + i) + j) = broj;
                tacanUnos = true;
            }
            } while (tacanUnos == false);
            tacanUnos = false;
        }
    }
}

void Ispis(int** tabla, int red, int kolona)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << tabla[i][j]<< " ";
        }
        cout << endl;
    }

}

float AritmetickaIznadGlavne(int** tabla, int red, int kolona)
{
    int suma = 0, brojac = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (j > i && (i + j) % 2 == 0)
            {
                suma += *(*(tabla+i)+j);
                brojac++;
            }
        }
    }

    return float(suma) / float(brojac);
}

int main() {
    int red, kolona;
    cout << "Unesite broj redova: ";
    cin >> red;
    cout << "Unesite broj kolona: ";
    cin >> kolona;

    int** tabla = new int*[red];

    for (int i = 0; i < red; i++)
        *(tabla + i) = new int[kolona];


    Unos(tabla, red, kolona);
    Ispis(tabla, red, kolona);

    cout << "Aritmeticka sredina brojeva na crnom polju iznad glavne dijagonale je: " << AritmetickaIznadGlavne(tabla, red, kolona) << endl;

    for (int i = 0; i < red; i++)
        delete[] * (tabla + i);

    delete[] tabla;
    tabla = nullptr;

	system("pause>0");
	return 0;
}
