/** 
\file note.h
\author Maxime IORI
 \version 0.1
 */

#ifndef NOTE
	#define NOTE
#include <iostream>
using namespace std;
#include "etudiant.h"

/**
\class Note
\brief Permet de créer des notes en les lien avec les étudiants
*/
class Note	
{
private: 
	int note;
	Etudiant *pEtudiant;
public:
	int getNote();
	void setNote(int noteEntree);
	void inputNote();
};
#endif