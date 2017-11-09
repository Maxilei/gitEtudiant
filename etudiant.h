/** 
\file etudiant.h
\author Maxime IORI
 \version 0.1
 */

#ifndef ETUDIANT
	#define ETUDIANT
#include <iostream>
using namespace std;

/**
\class Etudiant
\brief Permet d'interagir avec les élèves, avoir leurs noms etc... 
*/
class Etudiant
{ 	
private:
	string nomEleve;
	string prenomEleve;
	string birthdate;
public:
	string getNomEleve();
	void setNomEleve(string name);
	string getPrenomEleve();
	void setPrenomEleve(string surname);
	string getBirthdate();
	void setBirthdate(string birthdate);	

	void input();
	void display();
	
};
#endif