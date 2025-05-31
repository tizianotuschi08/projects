#include <iostream>
#include <cstring>
using namespace std;


int main() {
	string testo;
	int voc = 0, con = 0;

	cout << "Inserisci un testo o una parola: ";
	getline(cin, testo);

	for (int i = 0; i < testo.length(); i++) {
		if (isalpha(testo[i])) {
		    char c = tolower(testo[i]);
		    switch (c) {
		        case 'a': case 'e': case 'i': case 'o': case 'u':
		            voc++;
		            break;
		        default:
		            con++;
		            break;
		    }
		}
	}
	
	cout<<"Vocali: "<<voc<<endl;
	cout<<"Consonanti:"<<con<<endl;

	return 0;
}
