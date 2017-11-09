#include "etudiant.h"
#include <algorithm>

void Etudiant::input()
{
	cout <<endl<< "Nom de famille de l'élève : ";
	cin >> nomEleve;
	std::string nomEleveMaj = nomEleve;
	std::transform(nomEleveMaj.begin(), nomEleveMaj.end(),nomEleveMaj.begin(), ::toupper);
	nomEleve=nomEleveMaj;

	cout <<endl<< "Prénom de l'élève : ";
	cin >> prenomEleve;
	cout <<endl<< "Date de naissance de l'élève : (JJ/MM/AAAA) ";
	cin >> birthdate;
}

string Etudiant::getPrenomEleve()
{
	return prenomEleve;
}

string Etudiant::getNomEleve()
{
	return nomEleve;
}

void Etudiant::display()
{
	cout << nomEleve << "\t" <<prenomEleve << "\t\t" <<birthdate <<endl;
}