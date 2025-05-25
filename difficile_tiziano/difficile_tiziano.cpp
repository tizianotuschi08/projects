#include <iostream>
#include <conio2.h>
using namespace std;


int main() {
	int settore, sesso, anni, costo_totale = 0;

	textcolor(BROWN);
	cout << "[1] Curva Nord/Sud"
	     << endl << "[2] Distinti Sud"
	     << endl << "[3] Tevere"
	     << endl << "[4] Tevere Famiglia ALl-IN"
	     << endl << "[5] Parterre"
	     << endl << "[6] Disabili/Invalidi 100% + ACC"
	     << endl << "[7] Monte Mario"
	     << endl << "[8] Monte Mario" << endl
	     << "Inserisci il settore dove vuoi stare: ";
	normvideo();
	cin >> settore;

	do {
		textcolor(BROWN);
		cout << "Inserisci il sesso Uomo[0] Donna[1]: ";
		normvideo();
		cin >> sesso;
	} while ((sesso > 1 || sesso < 0));

	do {
		textcolor(BROWN);
		cout << "Inserisci quanti anni hai: ";
		normvideo();
		cin >> anni;
	} while (anni < 0);


	switch (settore) {
		case 1:
			costo_totale = 35;
			break;
		case 2:
			costo_totale = 45;
			break;
		case 6:
			costo_totale = 40;
			break;
		case 3:
		case 7:
			costo_totale = 80;
			if (anni > 65 || anni < 14) {
				costo_totale = 56;
			} else if (sesso == 1) {
				costo_totale = 72;
			}
			break;
		case 4:
			costo_totale = 45;
			if (anni > 65 || anni < 14) {
				costo_totale = 32;
			} else if (sesso == 1) {
				costo_totale = 41;
			}
			break;
		case 5:
			costo_totale = 50;
			if (anni > 65 || anni < 14) {
				costo_totale = 35;
			} else if (sesso == 1) {
				costo_totale = 45;
			}
			break;
		case 8:
			costo_totale = 105;
			if (anni > 65 || anni < 14) {
				costo_totale = 74;
			} else if (sesso == 1) {
				costo_totale = 95;
			}
			break;
		default:
			textcolor(RED);
			cout << "\n" << "Purtroppo non hai inserito i dati correttamente, riprova.";
			normvideo();
	}

	textcolor(GREEN);
	cout << "\n" << "Il prezzo per il tuo biglietto equivale a: " << costo_totale << "$";
	normvideo();

	return 0;
}
