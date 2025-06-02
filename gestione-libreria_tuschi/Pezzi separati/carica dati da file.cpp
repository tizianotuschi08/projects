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
