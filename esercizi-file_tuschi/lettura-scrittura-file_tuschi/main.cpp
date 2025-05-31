#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// 3 Funzioni principali
// ifstream -> per leggere da un file (input)
// ofstream -> per scrivere su un file (output)
// fstream -> per leggere e scrivere

int main() {

	ofstream fout("esempio.txt"); // crea o sovrascrive


	if (!fout) { // verifica apertura file
		cerr << "Errore nell'apertura del file.\n";
		return 1;
	}

	fout << "Ciao, mondo!" << endl;
	fout << "Scrivo su un file di testo." << endl;

	fout.close(); // chiusura file

// -------------------------------------------------------------------------

	ofstream fout("esempio.txt", ios::app); // crea o aggiunge
	if (!fout) {
		cerr << "Errore nell'apertura del file.\n";
		return 1;
	}
	fout << "Questa riga viene aggiunta alla fine." << endl;

	fout.close();


// --------------------------------------------------------------------------

	ifstream fin("esempio.txt");

	if (!fin) { // verifica apertura file
		cerr << "Errore nell'apertura del file.\n";
		return 1;
	}

	// === parola per parola ===
	string parola;
	while (fin >> parola) {
		cout << parola << endl;
	}

	fin.close();

	// === riga per riga ===
	string riga;
	while (getline(fin, riga)) {
		cout << riga << endl;
	}

	fin.close();

	// === carattere per carattere ===
	char c;
	while (fin.get(c)) {
		cout << c;
	}

	fin.close();

// -----------------------------------------------------------------------------
	ifstream fin("esempio.txt"); // controllo stato del file

	if (!fin.is_open()) {
		cerr << "Impossibile aprire il file!" << endl;
	}

	return 0;
}
