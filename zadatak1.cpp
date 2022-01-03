#include <iostream>

using namespace std;

/*
V8_1 ZADATAK6
Kreirajte strukturu učenik koja će imati sljedeća obilježja: redni broj, prezime, ime i
prosjecna ocjena. Deklarirajte 3 objekta tipa učenik. Omogućite unos obilježja za svakog
od učenika (pojedinačno) uz pomoć funkcije: void unos (ucenik *);
Omogućite ispis obilježja za svakog od učenika uz pomoć funkcije:
void ispis (ucenik );
Kreirajte funkciju ucenik * najgori(ucenik * , ucenik *, ucenik *); koja će vratiti
adresu onog objekta tipa ucenik koji ima najmanju prosječnu ocjenu. Ispišite vrijednost na
adresi koju vrati funkcija najgori.
*/

struct Ucenik {
	int RedniBroj;
	char Prezime[25];
	char Ime[25];
	float ProsjecnaOcjena;
};

void Unos(Ucenik* u)
{
	cout << "Unos podataka o uceniku: "<<endl;
	cout << "    Unesite redni broj: " ;
	cin >> u->RedniBroj; cin.ignore();
	cout << "    Unesite ime: ";
	cin >> u->Ime;
	cout << "    Unesite prezime: ";
	cin >> u->Prezime;
	cout << "    Unesite prosjecnu ocjenu: ";
	cin >> u->ProsjecnaOcjena;
}

void Ispis(Ucenik u)
{
	cout << "Podaci o uceniku: " << endl;
	cout << "    Redni broj: " << u.RedniBroj<<endl;
	cout << "    Ime: " << u.Ime<<endl;
	cout << "    Prezime: " << u.Prezime << endl;
	cout << "    Prosjecna ocjena: " << u.ProsjecnaOcjena;
}

Ucenik* Najgori(Ucenik* u1, Ucenik* u2, Ucenik* u3) {
	Ucenik* najgori;
	(u1->ProsjecnaOcjena < u2->ProsjecnaOcjena&& u1->ProsjecnaOcjena < u3->ProsjecnaOcjena) ? (najgori = u1) :
		(u2->ProsjecnaOcjena < u3->ProsjecnaOcjena&& u1->ProsjecnaOcjena < u3->ProsjecnaOcjena) ? (najgori = u2) : (najgori = u3);

	return najgori;
}

int main()
{
	Ucenik u1, u2, u3;

	Unos(&u1); cout << endl;
	Unos(&u2); cout << endl;
	Unos(&u3); cout << endl;
	system("cls");
	Ispis(u1); cout << endl;
	Ispis(u2); cout << endl;
	Ispis(u3); cout << endl;

	Ucenik* najgori = Najgori(&u1, &u2, &u3);

	Ispis(*najgori);


	cin.ignore();
	return 0;
}
