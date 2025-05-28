#include <iostream>
using namespace std;
int main()
{
	int mese;

	cout << "inserisci un numero che equivale ad un mese: ";
	cin >> mese;


	switch (mese)
	{
		case 6:
		case 7:
		case 8:
			cout << "la stagione e: Estate";
			break;
		case 9:
		case 10:
		case 11:
			cout << "la stagione e: Autunno";
			break;
		case 12:
		case 1:
		case 2:
			cout << "la stagione e: Inverno";
			break;
		case 3:
		case 4:
		case 5:
			cout << "la stagione e: Primavera";
			break;
		default:
			cout << "non esiste";
			break;
	}
	return 0;
}
