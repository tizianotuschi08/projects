#include <iostream>
using namespace std;

int main() {

	int dim = 0, x, n, ris = 0, c = 0;
	cout << "Inserisci un numero: ";
	cin >> x;
	n = x;

	// Conteggio cifre del numero inserito (x).
	while (n > 0) {
		dim++;
		n /= 10;
	}

	// Inizializzazione vettore con dimensione (dim) = cifre numero inserito (n).
	cout << "Hai inserito un numero da " << dim << " cifre." << endl << endl;
	int lista[dim];
	n = x;

	// Riempimento vettore con cifre del numero inserito (n).
	for (int i = dim - 1; i >= 0; i--) {
		lista[i] = n % 10;
		n /= 10;

	}
	
	n = x;
	
	// Ciclo per calcolare il numero belga.
	while (n > ris) {
		cout << ris << " + " << lista[c] << " = " << ris + lista[c] << endl;
		ris = lista[c] + ris;
		if (c == dim - 1) {
			c = 0;
		} else {
			c++;
		}
	}

	// Verifica se il numero e belga o no.
	if (ris == x) {
		cout << endl << "Il numero " << x << " e un numero belga";
	} else {
		cout << endl << "Il numero " << x << " non e un numero belga";
	}


	return 0;
}
