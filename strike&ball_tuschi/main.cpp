#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int dim;
	int combinazione;
	int cifre_inserite = 0;
	int tentativi = -1;

	// Scelta della lunghezza del numero da indovinare
	do
	{
		cout << "Scegli la lunghezza del numero da indovinare (3/6): " << endl;
		cin >> dim;
	}
	while (dim < 3 || dim > 6);

	cout << "Regole:" << endl;
	cout << "Inserisci un numero di cifre pari a quelle che hai scelto" << endl;
	cout << "per ogni cifra corretta ma nella posizione errata viene segnato un O" << endl;
	cout << "per ogni cifra corretta e nella posizione esatta viene segnata una X" << endl;
	cout << "Se le cifre si ripetono l'indizio viene considerato solo per un numero." << endl;

	int numero_segreto[dim], numero_inserito[dim];
	bool uguali = false;

	// Generazione numero segreto
	for (int i = 0; i < dim; i++)
	{
		numero_segreto[i] = (rand() % 9) + 1;
	}

	do
	{
		tentativi++;
		// Inserimento combinazione
		do
		{
			cifre_inserite = 0;
			cout << endl << "Inserisci una combinazione di cifre: ";
			cin >> combinazione;
			int c = combinazione;
			while (c > 0)
			{
				cifre_inserite++;
				c /= 10;
			}
		}
		while (cifre_inserite != dim);

		// Estrazione delle cifre
		int copia = combinazione;
		for (int i = dim - 1; i >= 0; i--)
		{
			numero_inserito[i] = copia % 10;
			copia /= 10;
		}

		// Verifica X e O
		bool usato_segreto[dim] = {false};
		bool usato_inserito[dim] = {false};

		// Primo passaggio: X (cifre giuste e posizione giusta)
		for (int i = 0; i < dim; i++)
		{
			if (numero_inserito[i] == numero_segreto[i])
			{
				cout << "X";
				usato_segreto[i] = true;
				usato_inserito[i] = true;
			}
		}

		// Secondo passaggio: O (cifre giuste ma posizione sbagliata)
		for (int i = 0; i < dim; i++)
		{
			if (usato_inserito[i]) continue;
			for (int j = 0; j < dim; j++)
			{
				if (!usato_segreto[j] && numero_inserito[i] == numero_segreto[j])
				{
					cout << "O";
					usato_segreto[j] = true;
					break;
				}
			}
		}

		// Controllo se tutto è corretto
		uguali = true;
		for (int i = 0; i < dim; i++)
		{
			if (numero_inserito[i] != numero_segreto[i])
			{
				uguali = false;
				break;
			}
		}

	}
	while (!uguali);

	cout << endl << endl << "Complimenti! Hai indovinato il numero segreto con " << endl << tentativi << " tentativi!";
	return 0;
}
