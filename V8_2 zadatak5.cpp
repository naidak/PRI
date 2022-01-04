#include <iostream>
using namespace std;

/*
Kreirati statički niz od pet (5) cjelobrojnih vrijednosti;
• Kreirati dinamički niz od dva pokazivača;
• Inicijalizirati jedan od pokazivača da pokazuje na najmanji element u statičkom
nizu;
• Inicijalizirati drugi pokazivač da pokazuje na najveći element u statičkom nizu;
• Koristite funkcije.
*/
void setPointers(int arr[], int** dynamicArr, int vel)
{
	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < vel; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			dynamicArr[0] = &arr[i];
		}

		if (arr[i] > max)
		{
			max = arr[i];
			dynamicArr[1] = &arr[i];
		}
	}
}

int main() {
	int staticArr[5] = { 3,5,1,6,2 };

	int** dynamicPointersArr = new int* [2];

	setPointers(staticArr, dynamicPointersArr, 5);

	cout << "Najmanji element niza je: " << **dynamicPointersArr << " i nalazi se na adresi: " << *dynamicPointersArr<<endl;
	cout << "Provjera: " << &staticArr[2]<<endl;
	cout << "Najveci element niza je: " << **(dynamicPointersArr+1) << " i nalazi se na adresi: " << dynamicPointersArr[1] << endl;
	cout << "Provjera: " << &staticArr[3] << endl;

	delete[] dynamicPointersArr;
	dynamicPointersArr = nullptr;

	system("pause>0");
	return 0;
}
