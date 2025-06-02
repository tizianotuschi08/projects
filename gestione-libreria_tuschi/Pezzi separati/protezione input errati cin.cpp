// Protezione contro input errati
		if (cin.fail()) {
			cin.clear(); // resetta errore
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // svuota input
			cout << "Input non valido. Inserisci un numero.\n";
			scelta = -1;
			continue;
		}
		cin.ignore(); // rimuove newline dal buffer
