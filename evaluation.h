/** 
\file evaluation.h
\author Maxime IORI
 \version 0.1
 */

 #ifndef EVALUATION
	#define EVALUATION
#include <iostream>
#include <vector>
using namespace std;
#include "note.h"
#include "matiere.h"

/**
\class Section
\brief Permet le liens avec Section pour en utiliser des éléments
*/
class Section;

/**
\class Evaluation
\brief Permet de créer et d'interagir avec des évaluations 
*/
class Evaluation
{
private: 
	Section* parent;
	Matiere *pLaMatiere;
	Etudiant *pLeleve;
	int semestre;
	vector <Note> vectNotes;
	string nomEval;
public:
	Evaluation(Section* lien);
	void inputEvaluation();
	void displayEvaluation();
	string getNomEval();
	Matiere* getMatiereEval();
};
#endif
