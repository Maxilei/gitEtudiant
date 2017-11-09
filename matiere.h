/** 
\file matiere.h
\author Maxime IORI
 \version 0.1
 */

 #ifndef MATIERE
	#define MATIERE
#include <iostream>
using namespace std;

/**
\class Matiere
\brief Permet de créer et d'interagir avec les matières
*/
class Matiere
{
private: 
	string nomMatiere;
public:
	Matiere();
	Matiere(string nomDeLaMatiere);
	void input();
	void display();
	void calculMoyenne();
	string getNomMatiere();
};
#endif