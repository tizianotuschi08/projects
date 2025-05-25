#include <iostream>
using namespace std;

int mcd(int, int);
int mcm(int, int);

int main() {
	setlocale(LC_ALL, "");

	int n1, n2;

	cout << "Inserisci due numeri: ";
	cin >> n1;
	cin >> n2;

	cout << "MCM (Minimo Comune Multiplo): " << mcm(n1, n2) << endl;
	cout << "MCD (Massimo Comune Divisore): " << mcd(n1, n2) << endl;

	return 0;
}


int mcd(int num1, int num2) {
	int mcd;

	if (num1 < num2)swap(num1, num2);

	for (int i = 1; i <= num2; i++) {
		if (num1 % i == 0 && num2 % i == 0)mcd = i;
	}

	return mcd;
}

int mcm(int num1, int num2) {
	int mcm;

	if (num1 < num2)swap(num1, num2);

	for (int i = num1 * num2; i >= num1; i--) {
		if (i % num1 == 0 && i % num2 == 0)mcm = i;
	}

	return mcm;
}
