#include <iostream>
using namespace std;

struct kosarkas
{
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    kosarkas() {
        ID = new char[20];
        imePrezime = new char[50];
        postignutiKosevi = new int;
    }

    ~kosarkas() {
        delete[] ID; ID = nullptr;
        delete[] imePrezime; imePrezime = nullptr;
        delete postignutiKosevi; postignutiKosevi = nullptr;
    }
};

void Unos(kosarkas**, int, int);
void Ispis(kosarkas**, int, int);
int max_tim(kosarkas**, int, int);
int* razlika(kosarkas**, int, int, int);

int main() {
    int red, kolona;
    cout << "Unesite broj klubova: ";
    cin >> red;
    cout << "Unesite broj kosarkasa: ";
    cin >> kolona;

    kosarkas** niz = new kosarkas * [red];

    for (int i = 0; i < red; i++)
        *(niz + i) = new kosarkas[kolona];

    Unos(niz, red, kolona);
    Ispis(niz, red, kolona);

    cout << "Razlika izmedju postignutih koseva u najboljeg igraca u timu " << max_tim(niz, red, kolona) + 1 
        << " i najlosijeg igraca u ligi je: " <<*razlika(niz, red, kolona, max_tim(niz, red, kolona)) << endl;

    for (int i = 0; i < red; i++)
        delete[] * (niz + i);

    delete[] niz;
    niz = nullptr;

	system("pause>0");
	return 0;
}

void Unos(kosarkas** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        cout << i + 1 << " tim: " << endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << j + 1 << " kosarkas: " << endl;
            cout << "Unesite ID: " << endl;
            cin.ignore();
            cin.getline((*(niz+i)+j)->ID, 20);
            cout << "Unesite ime i prezime: " << endl;
            cin.getline((*(niz + i) + j)->imePrezime, 50);
            cout << "Unesite broj koseva: ";
            cin >> *(*(niz + i) + j)->postignutiKosevi;
            cout << endl;
        }
        cout << "---------------------------------------------------\n";
    }
}

void Ispis(kosarkas** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        cout << i + 1 << " tim: " << endl;
        for (int j = 0; j < kolona; j++)
        {
            cout << j + 1 << " kosarkas: " << endl;
            cout << "\tID: " << (*(niz + i) + j)->ID << endl;
            cout << "\tIme i prezime: " << (*(niz + i) + j)->imePrezime << endl;
            cout << "\tBroj postinutih koseva: " << *(*(niz + i) + j)->postignutiKosevi << endl;
            cout << endl;
        }
        cout << "---------------------------------------------------\n";
    }
}

int max_tim(kosarkas** niz, int red, int kolona) {
    int* brojKoseva = new int[red] {};

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(brojKoseva + i) += *(*(niz + i) + j)->postignutiKosevi;
        }
    }

    int max_broj = 0.0;
    int max_indeks = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(brojKoseva + i) > max_broj)
        {
            max_broj = *(brojKoseva + i);
            max_indeks = i;
        }
    }
    return max_indeks;
}

int* razlika(kosarkas** niz, int red, int kolona, int max_koseva) {
    int max_igracUTimu = 0;

    for (int j = 0; j < kolona; j++)
    {
        if (max_igracUTimu < *(*(niz + max_koseva) + j)->postignutiKosevi)
        {
            max_igracUTimu = *(*(niz + max_koseva) + j)->postignutiKosevi;
        }
    }

    int najlosiji_u_ligi = INT_MAX;
    
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (*(*(niz + i) + j)->postignutiKosevi < najlosiji_u_ligi)
                najlosiji_u_ligi = *(*(niz + i) + j)->postignutiKosevi;
        }
    }

    int razlika = abs(max_igracUTimu - najlosiji_u_ligi);

    return new int(razlika);
}
