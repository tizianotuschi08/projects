#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	ifstream fin("originale.txt"); // al posto di fin si puo inserire qualsiasi nome
	ofstream fout("copia.txt"); // al posto di fout si puo inserire qualsiasi nome

	if (!fin || !fout) {
		cerr << "Impossibile aprire i file!";
		return 1;
	}

	string riga;
	while (getline(fin, riga)) {
		fout << riga << endl;
	}
	
	fin.close();
	fout.close();
	return 0;
}
