#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct squadra {
    string nome;
    int numero_giocatori;
    int overall;
};

struct partita {
    string squadra1;
    string squadra2;
    int goal1;
    int goal2;
    int tiri1;
    int tiri2;
    int angolo1;
    int angolo2;
    int gialli1;
    int gialli2;
    float quota1;
    float quota2;
    float quotaX;
    char giocata = '0'; // '1', '2', 'X', '0'
    float puntata = 0;
    bool vinta = false;
};

struct risultati {
    string nome;
    int vittorie = 0;
    int perdite = 0;
    int pareggi = 0;
    int goal = 0;
    int goal_presi = 0;
    int gialli = 0;
    int rossi = 0;
    int tiri = 0;
};

void calcolaQuote(partita& p, const squadra& s1, const squadra& s2) {
    int overall1 = s1.overall;
    int overall2 = s2.overall;

    int diff = abs(overall1 - overall2);
    float strength1 = overall1 / float(overall1 + overall2);
    float strength2 = overall2 / float(overall1 + overall2);

    // Quote base: più è forte la squadra, più bassa la sua quota
    float base1 = 1.5f - (strength1 * 0.9f);  // tra ~1.05 e 1.5
    float base2 = 1.5f - (strength2 * 0.9f);  // tra ~1.05 e 1.5

    // Aggiustamento per non avere quote troppo simili
    if (diff <= 5) {
        base1 += 0.3f;
        base2 += 0.3f;
    } else if (diff >= 20) {
        base1 -= 0.2f;
        base2 += 0.3f;
    }

    // Imposta chi è chi
    if (overall1 > overall2) {
        p.quota1 = max(1.05f, base1);
        p.quota2 = max(1.1f, base2);
    } else {
        p.quota1 = max(1.1f, base1);
        p.quota2 = max(1.05f, base2);
    }

    // Calcolo quota pareggio (più alta)
    p.quotaX = ((p.quota1 + p.quota2) / 2.0f) + 0.4f;
}

void simulaPartita(partita& p) {
    p.goal1 = rand() % 6;
    p.goal2 = rand() % 6;
    p.tiri1 = rand() % 16 + 5;
    p.tiri2 = rand() % 16 + 5;
    p.angolo1 = rand() % 10;
    p.angolo2 = rand() % 10;
    p.gialli1 = rand() % 4;
    p.gialli2 = rand() % 4;
}

int main() {
    srand(time(0));

    int numero_squadre;
    cout << "Inserisci il numero di squadre: ";
    cin >> numero_squadre;

    vector<squadra> squadre(numero_squadre);
    vector<risultati> stats(numero_squadre);

    for (int i = 0; i < numero_squadre; i++) {
        cout << "\nInserisci il nome della squadra " << i + 1 << ": ";
        cin.ignore();
        getline(cin, squadre[i].nome);

        squadre[i].numero_giocatori = rand() % 6 + 11;
        squadre[i].overall = rand() % 91 + 10;

        stats[i].nome = squadre[i].nome;

        cout << "Numero giocatori: " << squadre[i].numero_giocatori
             << ", Overall: " << squadre[i].overall << endl;
    }

    float saldo;
    cout << "\nCon quanti euro vuoi iniziare? ";
    cin >> saldo;

    int giocate_vinte = 0;
    float vincite_totali = 0;

    for (int i = 0; i < numero_squadre; i++) {
        for (int j = i + 1; j < numero_squadre; j++) {
            partita p;
            p.squadra1 = squadre[i].nome;
            p.squadra2 = squadre[j].nome;

            calcolaQuote(p, squadre[i], squadre[j]);

            // Pre-partita
            cout << "\n-----------------------------" << endl;
            cout << "Partita: " << p.squadra1 << " vs " << p.squadra2 << endl;
            cout << p.squadra1 << " - Overall: " << squadre[i].overall << endl;
            cout << p.squadra2 << " - Overall: " << squadre[j].overall << endl;
            cout << "Quote: 1 = " << p.quota1 << ", X = " << p.quotaX << ", 2 = " << p.quota2 << endl;
            cout << "Saldo attuale: " << saldo << " euro" << endl;

            cout << "Inserisci la tua giocata (1/X/2 o 0 per saltare): ";
            cin >> p.giocata;
            p.giocata = toupper(p.giocata);

            while (p.giocata != '1' && p.giocata != '2' && p.giocata != 'X' && p.giocata != '0') {
                cout << "Scelta non valida. Inserisci 1, X, 2 o 0: ";
                cin >> p.giocata;
                p.giocata = toupper(p.giocata);
            }

            if (p.giocata != '0') {
                do {
                    cout << "Quanto vuoi puntare? ";
                    cin >> p.puntata;
                    if (p.puntata > saldo) {
                        cout << "Non hai abbastanza saldo!" << endl;
                    }
                } while (p.puntata > saldo || p.puntata <= 0);
                saldo -= p.puntata;
            }

            // Simula partita
            simulaPartita(p);
            cout << "\nRisultato: " << p.squadra1 << " " << p.goal1 << " - " << p.goal2 << " " << p.squadra2 << endl;

            // Calcola risultato
            char risultato;
            if (p.goal1 > p.goal2) risultato = '1';
            else if (p.goal2 > p.goal1) risultato = '2';
            else risultato = 'X';

            // Aggiorna statistiche
            stats[i].goal += p.goal1;
            stats[j].goal += p.goal2;

            stats[i].goal_presi += p.goal2;
            stats[j].goal_presi += p.goal1;

            stats[i].tiri += p.tiri1;
            stats[j].tiri += p.tiri2;

            stats[i].gialli += p.gialli1;
            stats[j].gialli += p.gialli2;

            stats[i].rossi = stats[i].gialli / 2;
            stats[j].rossi = stats[j].gialli / 2;

            if (risultato == '1') {
                stats[i].vittorie++;
                stats[j].perdite++;
            } else if (risultato == '2') {
                stats[j].vittorie++;
                stats[i].perdite++;
            } else {
                stats[i].pareggi++;
                stats[j].pareggi++;
            }

            // Controlla scommessa
            if (p.giocata != '0') {
                if (p.giocata == risultato) {
                    float quota_vinta = (p.giocata == '1') ? p.quota1 :
                                        (p.giocata == '2') ? p.quota2 : p.quotaX;

                    float vincita = p.puntata * quota_vinta;
                    saldo += vincita;
                    vincite_totali += vincita;
                    giocate_vinte++;

                    cout << "✔ Hai vinto! Guadagni: " << vincita << " euro" << endl;
                } else {
                    cout << "✘ Hai perso la scommessa." << endl;
                }
                cout << "Saldo aggiornato: " << saldo << " euro" << endl;
            }
        }
    }

    // Riepilogo finale
    cout << "\n===== FINE GIOCO =====" << endl;
    cout << "Giocate vinte: " << giocate_vinte << endl;
    cout << "Vincite totali: " << vincite_totali << " euro" << endl;
    cout << "Saldo finale: " << saldo << " euro" << endl;

    cout << "\n===== STATISTICHE SQUADRE =====" << endl;
    for (const auto& r : stats) {
        cout << "\nSquadra: " << r.nome << endl;
        cout << " Vittorie: " << r.vittorie
             << " | Pareggi: " << r.pareggi
             << " | Sconfitte: " << r.perdite << endl;
        cout << " Goal fatti: " << r.goal
             << " | Goal subiti: " << r.goal_presi << endl;
        cout << " Tiri totali: " << r.tiri << endl;
        cout << " Gialli: " << r.gialli << " | Rossi: " << r.rossi << endl;
    }

    return 0;
}