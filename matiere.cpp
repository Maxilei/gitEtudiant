#include "matiere.h"

Matiere::Matiere(string nomDeLaMatiere)
{
	nomMatiere=nomDeLaMatiere;
}
Matiere::Matiere()
{
	
}
void Matiere::input()
{
	cout <<endl<< "Nom de la matiere : ";
	cin >> nomMatiere;
}

void Matiere::display()
{
	cout << nomMatiere<<endl;
}

string Matiere::getNomMatiere()
{
	return nomMatiere;
}