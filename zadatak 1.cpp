#include <iostream>
#include <string.h>
using namespace std;

/*
	Napišite program u kojem ćete upotrijebiti rekurzivnu funkciju čiji je zadatak računanje sume
	kvadrata od 1 do n (n je prirodan broj).
*/

int sumaKvadrata(int n, int i = 1)
{
	if (n < 1)
		return -1;

	if (i == n)
		return pow(n, 2);

	return pow(i, 2) + sumaKvadrata(n, i + 1);
}

int main() {
	int n = 3;
	cout << "Suma kvadrata od 1 do " << n << " je: " << sumaKvadrata(n);

	system("pause>0");
	return 0;
}

