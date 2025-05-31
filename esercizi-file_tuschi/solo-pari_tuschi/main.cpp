#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main() {
	ofstream file("solo_pari.txt");
	if (!file) {
		cerr << "Impossibile aprire il file!";
		return 1;
	}

	int num;
	cout << "Inserisci dei numeri (inserisci 0 per chiudere)" << endl;
	while (num != 0) {
		cin >> num;
		if (num % 2 == 0) {
			file << num << endl;
		}
	}

	file.close();
	return 0;
}
