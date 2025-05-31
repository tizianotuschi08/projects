#include <iostream>     // per input/output
#include <fstream>      // per leggere/scrivere su file
#include <cstring>      // non serve in realtà, può essere rimosso
using namespace std;

// Struttura per salvare le statistiche del testo
struct testo {
	int num_parole = 0;         // Numero totale di parole lette
	int max_lenght = 0;         // Lunghezza della parola più lunga
	int num_punteggiatura = 0;  // Numero totale caratteri di punteggiatura
	string parola_maxlenght;    // Parola più lunga trovata
};

int main() {
	setlocale(LC_ALL, "");
	// Apre il file "Testo.txt" in lettura
	ifstream file("Testo.txt");

	// Se il file NON esiste...
	if (!file) {
		// ...lo crea in scrittura
		ofstream nuovo_file("Testo.txt");
		if (!nuovo_file) {
			cerr << "Impossibile creare il file."; // errore se non si riesce a creare
			return 1;
		}
		cout << "File creato. Inserisci un testo all'interno e riavvia il programma." << endl;
		nuovo_file.close();
		return 0; // Esce dal programma dopo la creazione del file vuoto
	}

	// Inizializza la struttura per le statistiche
	testo t;
	string parola; // variabile per ogni parola letta

	// Legge parola per parola dal file
	while (file >> parola) {
		t.num_parole++; // conta una nuova parola

		// Se l'ultimo carattere è punteggiatura, lo rimuove
		if (ispunct(parola.back())) {
			parola.pop_back(); // rimuove ultimo carattere (es: punto, virgola, ecc.)
			t.num_punteggiatura++;
		}

		// Se la lunghezza attuale è maggiore della massima salvata
		if (t.max_lenght < parola.length()) {
			t.max_lenght = parola.length();     // aggorna lunghezza massima
			t.parola_maxlenght = parola;        // aggiorna parola più lunga
		}
	}

	// Se il file era vuoto (nessuna parola trovata)
	if (t.num_parole == 0) {
		cerr << "File vuoto!" << endl;
	} else {
		// Altrimenti stampa le statistiche
		cout << "Nel file ci sono: " << endl;
		cout << "Parole: " << t.num_parole << endl;
		cout << "Segni di punteggiatura: " << t.num_punteggiatura << endl;
		cout << "Parola più lunga: " << t.parola_maxlenght << endl;
		cout << "Lunghezza parola più lunga: " << t.max_lenght << endl;
	}

	// Chiude il file
	file.close();
	return 0;
}
