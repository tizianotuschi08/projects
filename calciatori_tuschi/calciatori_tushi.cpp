#include <iostream>
#include <algorithm>
using namespace std;

// Dichiarazione della struttura per un calciatore
struct calciatore {
	string nome;
	string ruolo;
	float valore_mln;
};

// Prototipi delle funzioni
int TrovaValoreAlto(calciatore[], int);
int TrovaGiocatoreConRuolo(calciatore[], int);
string ToLower(string);

int main() {

	int dim = 20;

	// Dichiarazione array tipo calciatore
	calciatore squadra1[dim] = {
		{"Cristiano Ronaldo", "Attaccante", 50.0},
		{"Lionel Messi", "Attaccante", 45.0},
		{"Neymar Jr", "Attaccante", 40.0},
		{"Kevin De Bruyne", "Centrocampista", 38.0},
		{"Sergio Ramos", "Difensore", 30.0},
		{"Alisson Becker", "Portiere", 28.0},
		{"Kylian Mbappé", "Attaccante", 60.0},
		{"Robert Lewandowski", "Attaccante", 42.0},
		{"Virgil van Dijk", "Difensore", 35.0},
		{"Bruno Fernandes", "Centrocampista", 32.03},
		{"Erling Haaland", "Attaccante", 55.0},
		{"Gianluigi Donnarumma", "Portiere", 25.0},
		{"Joshua Kimmich", "Centrocampista", 36.0},
		{"Luka Modric", "Centrocampista", 28.0},
		{"Mohamed Salah", "Attaccante", 39.03},
		{"Paul Pogba", "Centrocampista", 27.0},
		{"Raheem Sterling", "Attaccante", 34.0},
		{"Trent Alexander-Arnold", "Difensore", 33.0},
		{"Thibaut Courtois", "Portiere", 29.0},
		{"Jadon Sancho", "Attaccante", 31.0}
	};

	// Richiamare le funzioni
	TrovaValoreAlto(squadra1, dim);
	cout << "\n\n";
	TrovaGiocatoreConRuolo(squadra1, dim);

	return 0;
}

// Funzione per i calciatori sopra un certo valore
int TrovaValoreAlto(calciatore vet[], int d) {
	cout << "I calciatori con un valore sopra i 25 mln sono: \n\n";
	for (int i = 0; i < d; i++) {
		if (vet[i].valore_mln > 25.0)cout << vet[i].nome << endl;
	}
	return 0;
}

// Funzione per trovare i giocatori di un certo ruolo
int TrovaGiocatoreConRuolo(calciatore vet[], int d) {
	string r;

	cout << "Inserisci un ruolo per sapere chi della tua squadra lo pratica: ";
	cin >> r;
	r = ToLower(r);

	cout << "Questo ruolo lo praticano: \n\n";
	for (int i = 0; i < d; i++) {
		if (ToLower(vet[i].ruolo) == r)cout << vet[i].nome << endl;
	}
	return 0;
}

// Fnuzione per convertire una stringa tutta in minuscolo
string ToLower(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
