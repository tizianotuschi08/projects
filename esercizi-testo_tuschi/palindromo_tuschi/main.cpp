#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string toLower(string s){
	for(int i=0;i<s.length();i++){
		s[i]= tolower(s[i]);
	}
	return s;
}

string spaceLess(string s){
	string pulita;
	
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '){
			pulita += s[i];
		}
	}
	return pulita;
}

int main() {
	setlocale(LC_ALL, "");
	string palindromo, conferma;
	
	cout << "Inserisci una parola per sapere se è palindroma: ";
	getline(cin, palindromo);
	
	conferma = palindromo;
	reverse(conferma.begin(), conferma.end());
	
	if(toLower(spaceLess(conferma)) == toLower(spaceLess(palindromo))){
		cout<<"La parola e palindroma!";
	}else{
		cout<<"La parola non e palindroma!";
	}
	
	return 0;
}
