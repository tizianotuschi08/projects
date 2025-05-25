#include <iostream>
#include <ctime>
#include <conio2.h>
using namespace std;

const int limite = 100;

void filtra_lista(int [], int);
void stampa_lista (int [], int[], int, int);
void stampa_lista_univoci (int [], int [], int, int);

int main() {
	int lista_1[limite], lista_2[limite];
	int numeri_a_capo = 10;
	srand(time(0));

	for (int i = 0; i < limite; i++) {
		lista_1[i] = rand() % 1000;
		lista_2[i] = rand() % 1000;
	}

	textcolor(WHITE);
	cout << "Queste sono le due liste generate con numeri casuali:" << endl << endl;
	textcolor(RED);
	stampa_lista(lista_1, lista_2, limite, numeri_a_capo);

	filtra_lista(lista_1, limite);
	filtra_lista(lista_2, limite);

	textcolor(WHITE);
	cout << "Queste sono le due liste filtrate dai numeri doppioni:" << endl << endl;
	textcolor(YELLOW);
	stampa_lista(lista_1, lista_2, limite, numeri_a_capo);

	textcolor(WHITE);
	cout << "Queste sono le due liste senza doppioni:" << endl << endl;
	textcolor(GREEN);
	stampa_lista_univoci(lista_1, lista_2, limite, numeri_a_capo);

	return 0;
}

void filtra_lista (int vettore[], int limit) {

	for (int x = 0; x < limit; x++) {
		for (int y = x + 1; y < limit; y++) {
			if (vettore[x] == vettore[y]) {
				vettore[y] = 1000;
			}
		}
	}

}

void stampa_lista (int lista_1[], int lista_2[], int limit, int numero_a_capo) {
	for (int i = 0; i < limit; i++) {
		cout << lista_1[i] << " ";
		if ((i + 1) % numero_a_capo == 0) {
			cout << "\n";
		}
	}
	cout << endl;
	for (int i = 0; i < limit; i++) {
		cout << lista_2[i] << " ";
		if ((i + 1) % numero_a_capo == 0) {
			cout << "\n";
		}
	}
	cout << endl << endl;

}

void stampa_lista_univoci (int lista_1[], int lista_2[], int limit, int numero_a_capo) {

	for (int i = 0; i < limit; i++) {
		for (int y = 0; y < limite; y++) {
			if (lista_1[i] == lista_2[y]) {
				lista_1[i] = 1000;
				lista_2[y] = 1000;
			}
		}
	}
	for (int i = 0; i < limit; i++) {
		if (lista_1[i] != 1000) {
			cout << lista_1[i] << " ";
		}
		if ((i + 1) % numero_a_capo == 0) {
			cout << "\n";
		}
	}
	cout << endl ;
	for (int i = 0; i < limit; i++) {
		if (lista_2[i] != 1000) {
			cout << lista_2[i] << " ";
		}
		if ((i + 1) % numero_a_capo == 0) {
			cout << "\n";
		}
	}
	cout << endl << endl;
}
