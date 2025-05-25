#include <iostream>
using namespace std;


int main() {
	int x;
	
	cout<<"Inserisci un numero e ti dimostro che alla fine diventa 1: ";
	cin>>x;
	
	while(x!=1){
		
		if(x%2==0){
			x=x/2;
			cout<<"\n"<<x;
		}
		else
		{
			x=x*3+1;
			cout<<"\n"<<x;
		}
		
	}
	
	return 0;
}
