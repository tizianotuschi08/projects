#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio2.h>
using namespace std;

int main() {

	srand(time(0));
	int dim, ris=0, pos=0;
	int ris1 = 0, ris2 = 0, ris3 = 0, ris4 = 0;

	do {
		cout << "Inserisci la grandezza della matrice: ";		// Verifica dei requisiti della grandezza del quadrato (che sia pari)
		cin >> dim;
	} while (dim % 2 != 0);

	int q[dim][dim];
	int r[4];

	for (int x = 0; x < dim; x++) {
		cout << endl;
		for (int y = 0; y < dim; y++) {

			q[x][y] = (rand() % 1000) + 1;
			
			if (y < (dim / 2) && x < (dim / 2))ris1 = ris1 + q[x][y];	r[0]=ris1;
			if (y >= (dim / 2) && x < (dim / 2))ris2 = ris2 + q[x][y];	r[1]=ris2;
			if (y < (dim / 2) && x >= (dim / 2))ris3 = ris3 + q[x][y];	r[2]=ris3;
			if (y >= (dim / 2) && x >= (dim / 2))ris4 = ris4 + q[x][y];	r[3]=ris4;
			
			if (y == (dim / 2)) {
				cout << setw(4) << "|";
			}
			cout << setw(4) << q[x][y];
		}
		if (x == (dim / 2) - 1) {
			cout << endl;
			for (int i = 0; i < dim + 1; i++) {
				cout << setw(4) << "-";
			}
		}
	}
	cout<<"\n\n";
	textcolor(RED);
	cout<<"Somma sottomatrice N/W	"<<ris1<<endl;
	textcolor(GREEN);
	cout<<"Somma sottomatrice N/E	"<<ris2<<endl;
	textcolor(YELLOW);
	cout<<"Somma sottomatrice S/W	"<<ris3<<endl;
	textcolor(BLUE);
	cout<<"Somma sottomatrice S/E	"<<ris4<<endl;
	normvideo();
	
	for(int i=0;i<4;i++){
		if(ris < r[i]){
			ris=r[i];
			pos=i;
		}
	}
	cout<<endl;
	switch (pos) {
		case 0:
			textcolor(RED);
			cout<<"La sottomatrice piu grande si trova a N/W";
			break;
		case 1:
			textcolor(GREEN);
			cout<<"La sottomatrice piu grande si trova a N/E";
			break;
		case 2:
			textcolor(YELLOW);
			cout<<"La sottomatrice piu grande si trova a S/W";
			break;
		case 3:
			textcolor(BLUE);
			cout<<"La sottomatrice piu grande si trova a S/E";
			break;

	}
	normvideo();

	return 0;
}
