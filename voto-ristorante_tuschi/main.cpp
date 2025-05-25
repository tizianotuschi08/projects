#include <iostream>
#include <iomanip>
using namespace std;

struct ristorante
{
	string nome;
	string luogo;
	int voto;
};


int main()
{
	int dim = 10;

	ristorante vet[dim] =
	{
		{"Da Laura", "Lazio", 4},
		{"Gigino", "Abruzzo", 3},
		{"Speedy", "Liguria", 1},
		{"Firera&co", "Lazio", 5},
		{"Vardaro Pizzeria", "Lazio", 2},
		{"Luigino", "Puglia", 2},
		{"Arsalan Malik Kebab", "Pakistan", 1 },
		{"Rosticceria Marras", "Calabria", 5},
		{"Colonnello chicken", "Toscana", 3},
		{"Gianlorenzo family food", "Lecco", 5 },
	};

	cout << "I ristoranti considerati migliori sono: \n\n";
	for (int i = 0; i < dim; i++)
	{
		if (vet[i].voto > 3)
		{
			cout << vet[i].nome << ", " << vet[i].luogo << ", " << vet[i].voto << " stelle\n";
		}
	}
	cout << "\n\nI ristoranti considerati buoni sono: \n\n";
	for (int i = 0; i < dim; i++)
	{
		if (vet[i].voto == 3)
		{
			cout << vet[i].nome << ", " << vet[i].luogo << ", " << vet[i].voto << " stelle\n";
		}
	}
	cout << "\n\nI ristoranti considerati peggiori sono: \n\n";
	for (int i = 0; i < dim; i++)
	{
		if (vet[i].voto < 3)
		{
			cout << vet[i].nome << ", " << vet[i].luogo << ", " << vet[i].voto << " stelle\n";
		}
	}

	return 0;
}
