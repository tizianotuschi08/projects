#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	
	cout<<"Inserisci un valore per a: ";
	cin>>a;
	
	cout<<"inserisci un valore per b: ";
	cin>>b;
	
	cout<<"inserisci nu valore per c: ";
	cin>>c;
	
	
	if (a%2==0 && b%2==0 && c%2==0)
		cout<<a*b*c;

	else if (a%2==0 || b%2==0 || c%2==0)
		cout<<a+b+c;
		
	else
		cout<<a-b-c;
	
	return 0;
}
