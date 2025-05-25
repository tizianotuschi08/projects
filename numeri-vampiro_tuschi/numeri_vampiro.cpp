#include <iostream>
using namespace std;

int main() {
	int dim = 0, x, num1 = 0, num2 = 0, n;
	cout << "Inserisci un numero: ";
	cin >> x;

	// Conteggio cifre del numero inserito (x).
	// Verifica che le cifre del numero inserito (x) siano pari.
	do {
		n = x;
		dim = 0;
		while (n > 0) {
			dim++;
			n /= 10;
		}
		if ((dim % 2) != 0) {
			cout << "Assicurati che il numero inserito abbia un totale di cifre pari: ";
			cin >> x;
		}
	} while ((dim % 2) != 0);

	// Inizializzazione dei vettori con dimensione (dim) = cifre numero inserito (n) / 2.
	int zanna1[dim / 2];
	int zanna2[dim / 2];
	n = x;

	// Riempimento vettore della prima zanna con cifre del numero inserito (n).
	for (int i = (dim / 2) - 1; i >= 0; i--) {
		zanna1[i] = n % 10;
		n /= 10;
	}
	// Riempimento vettore della seconda zanna con cifre del numero inserito (n).
	for (int i = 0; i < (dim / 2); i++) {
		zanna2[i] = n % 10;
		n /= 10;
	}

	// Accorpamento numeri dai vettori
	for (int i = 0; i < dim / 2; i++) {
		num1 = num1 * 10 + zanna1[i];
		num2 = num2 * 10 + zanna2[i];
	}

	cout << endl << "Le zanne del numero che hai inserito sono: " << num2 << " e " << num1 << endl;
	cout << "Ora verifichiamo se il numero e un numero vampiro moltiplicando le due zanne: " << endl;
	cout << endl << num2 << " * " << num1 << " = " << num1*num2 << endl;

	if ((num1 * num2) == x) {
		cout << endl << "Come puoi vedere moltiplicando le due zanne il risultato e uguale al numero di partenza";
	} else {
		cout << endl << "Come puoi vedere moltiplicando le due zanne il risultato non e uguale al numero di partenza";
	}
	return 0;
}
