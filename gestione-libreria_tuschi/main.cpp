#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits> // per numeric_limits
using namespace std;

// Struttura che rappresenta un libro
struct libro {
	string nome;
	string autore;
	string anno;
};

// Funzione che converte una stringa in minuscolo
string toLower(string s1) {
	string lower;
	for (char c : s1) {
		lower += tolower(c); // converte ogni carattere
	}
	return lower;
}

// Funzione per aggiungere un nuovo libro al vettore e salvarlo nel file
void aggiungiLibro(vector<libro>& vet) {
	string N, A, Y;
	libro l;

	// Inserimento dati da tastiera
	cout << "\nInserisci il nome del libro: ";
	getline(cin, N);
	l.nome = N;
	cout << "Inserisci il nome dell'autore: ";
	getline(cin, A);
	l.autore = A;
	cout << "Inserisci anno di pubblicazione: ";
	getline(cin, Y);
	l.anno = Y;

	// Aggiunge il libro al vettore
	vet.push_back(l);

	// Salva il libro nel file (in fondo)
	ofstream salvataggio("libreria.txt", ios::app); // modalità "append"
	if (salvataggio) {
		salvataggio << N << '|' << A << '|' << Y << '\n'; // separati da '|'
		salvataggio.close();
	} else {
		cout << "Errore nell'apertura del file.\n";
	}
}

// Funzione per cercare un libro per nome o autore
void cercaLibro(vector<libro>& vet) {
	int s = -1;

	while (s != 0) {
		cout << "\n--- Menu Ricerca ---\n";
		cout << "1. Cerca per nome\n";
		cout << "2. Cerca per autore\n";
		cout << "0. Torna al menu principale\n";
		cout << "Scelta: ";

		cin >> s;

		// Protezione contro input non numerici
		if (cin.fail()) {
			cin.clear(); // ripristina lo stato del cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // svuota il buffer
			cout << "Input non valido. Inserisci un numero.\n";
			s = -1;
			continue;
		}
		cin.ignore(); // rimuove il carattere '\n' rimasto dopo il numero

		switch (s) {
			case 1: { // Ricerca per nome
				string nome;
				bool trovato = false;

				cout << "\nInserisci il nome del libro: ";
				getline(cin, nome);

				// Scorre tutto il catalogo
				for (const libro& l : vet) {
					if (toLower(nome) == toLower(l.nome)) {
						trovato = true;
						cout << "\nTrovato!" << endl;
						cout << "Nome: " << l.nome << endl;
						cout << "Autore: " << l.autore << endl;
						cout << "Anno di pubblicazione: " << l.anno << endl;
					}
				}
				if (!trovato) {
					cout << "Libro non trovato mi spiace..." << endl;
				}
				break;
			}
			case 2: { // Ricerca per autore
				string autore;
				bool trovato = false;

				cout << "\nInserisci il nome dell'autore: ";
				getline(cin, autore);

				for (const libro& l : vet) {
					if (toLower(autore) == toLower(l.autore)) {
						trovato = true;
						cout << "\nTrovato!" << endl;
						cout << "Nome: " << l.nome << endl;
						cout << "Autore: " << l.autore << endl;
						cout << "Anno di pubblicazione: " << l.anno << endl;
					}
				}
				if (!trovato) {
					cout << "Libro non trovato mi spiace..." << endl;
				}
				break;
			}
			case 0:
				cout << "Torno al menu principale...\n";
				break;
			default:
				cout << "Scelta non valida.\n";
		}
	}
}

// Carica i dati dei libri dal file all'avvio
void caricaDaFile(vector<libro>& vet) {
	string parola;

	ifstream catalogo("libreria.txt");
	if (!catalogo) {
		// Se il file non esiste, lo crea vuoto
		ofstream crea_file("libreria.txt");
		if (crea_file) {
			cout << "File 'libreria.txt' non trovato. Creo un nuovo file..." << endl;
		} else {
			cout << "Errore nella creazione del file!" << endl;
		}
		crea_file.close();
		return;
	}

	// Legge ogni riga dal file e costruisce un libro
	while (getline(catalogo, parola)) {
		if (parola.empty()) continue; // salta righe vuote

		istringstream ss(parola);
		string N, A, Y;

		getline(ss, N, '|'); // nome
		getline(ss, A, '|'); // autore
		getline(ss, Y, '|'); // anno

		libro l;
		l.nome = N;
		l.autore = A;
		l.anno = Y;

		vet.push_back(l); // aggiunge al vettore
	}
}

// Mostra tutti i libri caricati
void mostraTuttiIlibri(vector<libro>& vet) {
	if (vet.empty()) {
		cout << "\nIl catalogo è vuoto. Nessun libro disponibile.\n";
		return;
	}

	cout << "\nEcco il nostro intero catalogo:\n" << endl;

	for (const libro& l : vet) {
		cout << "Nome: " << l.nome << endl;
		cout << "Autore: " << l.autore << endl;
		cout << "Anno di rilascio: " << l.anno << endl;
		cout << "-------------------------------------" << endl;
	}
}

// Funzione principale
int main() {
	int scelta = -1; // inizializza la scelta
	vector<libro> libri; // vettore di libri

	caricaDaFile(libri); // carica i dati all’avvio

	while (scelta != 0) {
		cout << "\n--- Menu Principale ---\n";
		cout << "1. Aggiungi un libro\n";
		cout << "2. Cerca un libro\n";
		cout << "3. Mostra catalogo libri\n";
		cout << "0. Esci\n";
		cout << "Scelta: ";

		cin >> scelta;

		// Protezione contro input errati
		if (cin.fail()) {
			cin.clear(); // resetta errore
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // svuota input
			cout << "Input non valido. Inserisci un numero.\n";
			scelta = -1;
			continue;
		}
		cin.ignore(); // rimuove newline dal buffer

		switch (scelta) {
			case 1:
				aggiungiLibro(libri);
				break;
			case 2:
				cercaLibro(libri);
				break;
			case 3:
				mostraTuttiIlibri(libri);
				break;
			case 0:
				cout << "\nArrivederci...\n";
				break;
			default:
				cout << "Scelta non valida.\n";
		}
	}

	return 0;
}
