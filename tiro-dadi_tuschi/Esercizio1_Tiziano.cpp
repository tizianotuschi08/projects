#include <iostream>
#include <ctime>
using namespace std;


int main() {
	
	srand(time(NULL));
	int x, y = 0;

	cout << "Inserisci quante volte vuoi tirare 2 dadi: ";
	cin >> x;

	for (int i = 0; i < x; i++) {
		y = y + rand() % 6 + rand() % 6 + 2;
	}

	cout << "\n" << y / x;

	return 0;
}
