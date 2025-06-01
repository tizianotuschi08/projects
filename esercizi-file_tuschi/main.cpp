/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>    // Per input/output (cout, cin)
#include <cstring>     // Non usata in questo codice, può essere rimossa
#include <set>         // Per usare 'set', struttura dati che contiene solo elementi unici
#include <cctype>      // Per funzioni sui caratteri (es. isalpha, tolower)
#include <sstream>     // Per istringstream, che permette di leggere parole da una stringa
using namespace std;

// Rimuove tutti gli spazi da una stringa
string spaceLess(string s1){
    string sl;
    for(char c : s1)  {
        if(c != ' ')      // Se il carattere non è uno spazio, lo aggiungo alla nuova stringa
            sl += c;
    }
    return sl;
}

// Cifra la stringa spostando ogni carattere avanti di uno (es: 'a' -> 'b', 'b' -> 'c', ...)
string toEncript(string s1){
    string se;
    for(char c : s1){
        se += c+1;        // Sposta ogni carattere di 1 nel codice ASCII
    }
    return se;
}

// Decifra la stringa facendo l'opposto di toEncript (es: 'b' -> 'a', ...)
string toDecript(string s1){
    string sd;
    for(char c : s1){
        sd += c-1;        // Riporta ogni carattere indietro di 1 nel codice ASCII
    }
    return sd;
}

// Rende tutti i caratteri alfabetici minuscoli e conserva solo lettere e spazi
string toLowerAllAlpha(string s1){
    string lower;
    for(char c : s1){
        if(isalpha(c) || c == ' ')   // isalpha verifica se c è una lettera (a-z o A-Z)
            lower += tolower(c);     // tolower converte in minuscolo
    }
    return lower;
}

// Restituisce un set (insieme) di parole uniche nella frase (ignorando maiuscole/minuscole)
set<string> searchUniche(string s1){
    set<string> parole;                        // Insieme vuoto per memorizzare parole uniche
    istringstream iss(toLowerAllAlpha(s1));   // istringstream divide la stringa in parole
    string parola;

    while(iss >> parola){                     // Legge parola per parola dalla stringa
        parole.insert(parola);                // Inserisce la parola nel set (duplicati ignorati)
    }
    return parole;
}

int main()
{
    string frase;
    
    cout << "Inserisci una frase: " << endl;
    getline(cin, frase);  // Legge una riga intera da input, inclusi gli spazi
    
    // Cifra la frase con toEncript
    string frase_criptata = toEncript(frase);
    // Trova le parole uniche nella frase originale (ignorando maiuscole)
    set<string> parole_uniche = searchUniche(frase);

    // Stampa la frase senza spazi
    cout << "\nLa frase senza spazi: ";
    cout << spaceLess(frase) << endl;

    // Stampa la frase criptata senza spazi
    cout << "La tua frase criptata: ";
    cout << spaceLess(frase_criptata) << endl;

    // Stampa la frase decriptata (decifrando la criptata)
    cout << "La tua frase decriptata: ";
    cout << toDecript(frase_criptata) << endl;

    // Stampa quante parole uniche sono presenti
    cout << "\nLe parole uniche nel tuo testo sono: ";
    cout << parole_uniche.size() << endl;

    // Stampa le parole uniche, una per riga
    cout << "Le parole uniche sono: ";
    for (string p : parole_uniche){
        cout << p << endl;
    }

    return 0;
}
