// Uso del ciclo for-each (senza indice)
	cout << "\nLista nomi salvati:\n";
	for (const string& nome : nomi) { // Legge ogni elemento del vector
		cout << "- " << nome << endl;
	}
