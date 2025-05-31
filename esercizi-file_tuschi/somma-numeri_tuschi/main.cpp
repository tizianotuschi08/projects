#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	ifstream file("origine.txt");

	if (!file) {
		cerr << "Impossibile aprire il file!";
		return 1;
	}

	int som = 0;
	int num;

	while (file >> num) {
		som += num;
	}
	cout << "La somma totale dei numeri: " << som;

	file.close();
	return 0;
}
