#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

/*Aggiungi nuovo studente e i suoi voti

Visualizza tutti gli studenti

Ordina studenti per media voti (decrescente)

Salva registro su file

Carica registro da file

Cerca studente e modifica voti

Esci*/
bool salva = true;

struct studente {
	string NOME;
	int VOTI[5];
	float MEDIA;
};

// Funzione che converte una stringa in minuscolo
string toLower(string s1) {
	string lower;
	for (char c : s1) {
		lower += tolower(c); // converte ogni carattere
	}
	return lower;
}

void aggiungiStudente(studente st, vector<studente>& vet) {
	vet.push_back(st);
}

bool cercaStudente(const string& nome, vector<studente>& vet, studente& risultato) {

	for (const studente& st : vet) {
		if (toLower(nome) == toLower(st.NOME)) {
			risultato = st;
			return true;
		}
	}
	return false;
}

vector<studente> ordinaStudentiConVoto(vector<studente> vet) {
	sort(vet.begin(), vet.end(), [](studente& s1, studente& s2) {
		return s1.MEDIA > s2.MEDIA;
	});

	return vet;
}

void salvaSuFile(const vector<studente>& vet) {
	ifstream file("registro.txt");
	if(!file) {
		ofstream genera_file("registro.txt");
		if(genera_file) {
			cout<<"File 'registro.txt' inesistente. Creo file..."<<endl;
		}
		else {
			cerr << "Impossibile creare file!"<<endl;
		}
		genera_file.close();
	}
	file.close();

	ofstream aggiungi("registro.txt", ios::app);

	if(!aggiungi) {
		cout<<"Impossibile aprire il file."<<endl;
	}

	for(const studente& st : vet) {
		aggiungi << st.NOME << '|';
		for(const int& voto : st.VOTI) {
			aggiungi << voto << ' ';
		}
		aggiungi << st.MEDIA<< "\n";
	}

	cout<<"Salvataggio avvenuto con successo!"<<endl;
	salva = true;

	aggiungi.close();
}


void caricaDaFile(vector<studente>& elenco) {
	ifstream file("registro.txt");

	if(!file) {
		ofstream genera_file("registro.txt");
		if(genera_file) {
			cout<<"File 'registro.txt' inesistente. Creo file..."<<endl;
		}
		else {
			cerr << "Impossibile creare file!"<<endl;
			return;
		}
		genera_file.close();
	}

	string riga;
	while (getline(file, riga)) {
		size_t sep = riga.find('|');
		if (sep == string::npos) {
			cerr << "Formato errato" << endl;
			continue;
		}

		studente st;
		st.NOME = riga.substr(0, sep);  // Parte del nome

		istringstream ss(riga.substr(sep + 1));
		for (int i = 0; i < 5; ++i) {
			if (!(ss >> st.VOTI[i])) {
				cerr << "Errore lettura voti" << endl;
				break;
			}
		}

		ss >> st.MEDIA;  // Float finale

		elenco.push_back(st);
	}

	file.close();
	if(!elenco.empty()) {
		cout<<"Caricamento avvenuto con successo!"<<endl;
	}
	else {
		cout<<"Nessun studente!"<<endl;
	}
}



int main() {
	int scelta = -1;
	vector<studente> registro;

	while (scelta != 0) {
		cout << "\n--- Registro Elettronico ---" << endl;
		cout << "1. Aggiungi nuovo studente e voti." << endl;
		cout << "2. Cerca studente e modifica voti." << endl;
		cout << "3. Ordina studenti per media voti." << endl;
		cout << "4. Salva su file." << endl;
		cout << "5. Carica da file." << endl;
		cout << "0. Esci." << endl;
		cout << "Scelta: ";
		cin >> scelta;

		// Protezione contro input non numerici
		if (cin.fail()) {
			cin.clear(); // ripristina lo stato del cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // svuota il buffer
			cout << "Input non valido. Inserisci un numero.\n";
			scelta = -1;
			continue;
		}
		cin.ignore(); // rimuove il carattere '\n' rimasto dopo il numero

		switch (scelta) {
		case 1: {
			studente alunno;
			float media = 0;

			cout << "\nInserisci il nome dell'alunno: ";
			getline(cin, alunno.NOME);
			cout << "Inserisci i voti dell'alunno (5): "<<endl;

			/*Quando si usano i getline potrebbero
			esserci spesso errori a causa del buffer, quindi questa parte sotto
			di codice impedisce al cin di inserire valori diversi da quelli richiesti
			inoltre elimina il buffer impedendo al getline di recuperare
			caratteri non digitati o digitati per sbaglio.*/

			for (int i = 0; i < 5; i++) {
				while (true) {
					cout << "Inserisci voto #" << i + 1 << ": ";
					cin >> alunno.VOTI[i];

					if (cin.fail()) {
						cin.clear(); // ripristina lo stato di cin
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // svuota il buffer
						cout << "Input non valido. Inserisci un numero intero.\n";
						continue;
					}

					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pulizia extra

					if (alunno.VOTI[i] < 1 || alunno.VOTI[i] > 10) {
						cout << "Il voto deve essere tra 1 e 10.\n";
						continue;
					}

					media += alunno.VOTI[i];
					break; // tutto ok, esci dal ciclo
				}
			}
			alunno.MEDIA = media / 5;
			aggiungiStudente(alunno, registro);
			
			salva = false;
			break;
		}
		case 2: {
			string nome_alunno;
			studente trovato;

			cout << "Inserisci il nome dell'alunno che vuoi cercare: ";
			getline(cin, nome_alunno);

			if (cercaStudente(nome_alunno, registro, trovato)) {
				cout << "\nStudente trovato!";
				cout << "\nNome: " << trovato.NOME << endl;
				cout << "Voti: ";
				for (int i = 0; i < 5; i++) {
					cout << trovato.VOTI[i] << " ";
				}
				cout << endl;
				cout << "Media voti: " << trovato.MEDIA << endl;
			} else {
				cout << "Alunno non trovato!" << endl;
			}

			break;
		}
		case 3: {
			vector<studente> studenti_ordinati = ordinaStudentiConVoto(registro);;
			if (!studenti_ordinati.empty()) {
				cout<<"\n-- Studenti in ordine di voto --"<<endl;
				for(const studente& st : studenti_ordinati) {
					cout<<"Nome: "<<st.NOME<<", Media: "<<st.MEDIA<<endl;
				}
			} else {
				cout<<"Nessun studente!"<<endl;
			}
			break;
		}
		case 4:
			salvaSuFile(registro);
			salva = true;
			break;
		case 5:
			caricaDaFile(registro);
			break;
		case 0: {
			if(!salva) {
				char scelta;
				cout<<"Vuoi salvare? ";
				cin >> scelta;

				// Protezione contro input non numerici
				if (cin.fail()) {
					cin.clear(); // ripristina lo stato del cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // svuota il buffer
					cout << "Input non valido. Inserisci s/n.\n";
					scelta = -1;
					continue;
				}
				cin.ignore(); // rimuove il carattere '\n' rimasto dopo il numero

				if (scelta == 's' || scelta == 'S') {
					salvaSuFile(registro);
				}
			}
			cout << "\nArrivederci..." << endl;
			break;
		}
		default:
			cout << "Input non valido.";
			break;
		}
	}
	return 0;
}