#include <iostream>
#include <conio2.h>
using namespace std;


int main() {
	// Dichiaro le variabili
	int base_asta, offerta_1 = 0, offerta_2 = 0;
	string astante_1, astante_2;

	// Leggo i nomi degli astanti
	cout << "Inserire il nome del primo astante: ";
	textcolor(RED);
	getline(cin, astante_1);
	normvideo();
	cout << "Inserire il nome del secondo astante: ";
	textcolor(BLUE);
	getline(cin, astante_2);
	normvideo();

	// Leggo la base_asta e verifico che sia >0
	do {
		if (base_asta <= 0) {
			textcolor(BROWN);
			cout << "Inserire una base valida: ";
			normvideo();
		} else {
			cout << "Inserire una base d'asta: ";
		}
		textcolor(GREEN);
		cin >> base_asta;
		normvideo();
	} while (base_asta <= 0);

	//Apro un ciclo che si conclude quando gli astanti scrivono 0
	while (true) {
		// Gestione dell'offerta dell'astante 1
		textcolor(RED);
		cout << "\n" << astante_1;
		normvideo();
		cout << " inserisci la tua offerta: ";
		cin >> offerta_1;
		do {
			if (offerta_1 == 0) {
				textcolor(RED);
				cout << "\n" << astante_1 << " ha deciso di abbandonare l'asta"<<endl;
				textcolor(GREEN);
				cout << "Ha vinto " << astante_2 << " con l'offerta di " << offerta_2 << "$";
				normvideo();
				return false;
			} else if (offerta_1 <= base_asta) {
				textcolor(BROWN);
				cout << "Inserisci un'offerta valida >" << base_asta << ": ";
				normvideo();
				cin >> offerta_1;
			}
		} while (offerta_1 <= base_asta);

		base_asta = offerta_1;

		// Gestione dell'offerta dell'astante 2
		textcolor(BLUE);
		cout << "\n" << astante_2;
		normvideo();
		cout << " inserisci la tua offerta: ";
		cin >> offerta_2;
		do {
			if (offerta_2 == 0) {
				textcolor(RED);
				cout << "\n" << astante_2 << " ha deciso di abbandonare l'asta"<<endl;
				textcolor(GREEN);
				cout << "Ha vinto " << astante_1 << " con l'offerta di " << offerta_1 << "$";
				normvideo();
				return false;
			} else if (offerta_2 <= base_asta) {
				textcolor(BROWN);
				cout << "Inserisci un'offerta valida >" << base_asta << ": ";
				normvideo();
				cin >> offerta_2;
			}
		} while (base_asta >= offerta_2);

		base_asta = offerta_2;
	}

	return 0;
}
