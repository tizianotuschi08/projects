// Lettura da file con ifstream
	ifstream inFile("esempio.txt");
	string linea;
	vector<string> nomi;

	while (getline(inFile, linea)) { // Legge una riga intera da file
		istringstream ss(linea);     // Usa stringa come stream di input
		string nome, cognome, anno;
		getline(ss, nome, '|');      // Legge fino al delimitatore '|'
		getline(ss, cognome, '|');
		getline(ss, anno, '|');

		cout << "Nome: " << nome << ", Cognome: " << cognome << ", Anno: " << anno << endl;

		nomi.push_back(nome); // Aggiunge un elemento al vector
	}
	inFile.close();
