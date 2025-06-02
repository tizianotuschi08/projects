// Salva il libro nel file (in fondo)
	ofstream salvataggio("libreria.txt", ios::app); // modalità "append"
	if (salvataggio) {
		salvataggio << N << '|' << A << '|' << Y << '\n'; // separati da '|'
		salvataggio.close();
	} else {
		cout << "Errore nell'apertura del file.\n";
	}
