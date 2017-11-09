#include "evaluation.h"
#include "section.h"
#include "note.h"
using namespace std;
#include <iostream> 

Evaluation::Evaluation(Section* lien)
{
	parent=lien;
}


void Evaluation::inputEvaluation()
{
	cout << " Nom du contrôle : ";
	cin.ignore(1);
	getline(cin,nomEval);
	cout << endl;

	int semestre;
	cout << "Semestre du contrôle : ";
	cin >> semestre;
	cout << endl;

	cout << " Quelle matière : "<<endl;
	//pLaMatiere = parent->vectMatiere[];
	parent->afficherMatieres();
	int matiereAAdd=0;
	cout << " Numéro de la matière : ";
	cin >> matiereAAdd;
	cout <<endl;
	pLaMatiere= parent->getVectMatiere()[matiereAAdd-1];
	// pLaMatiere->display();
	cout<<endl <<"Notes des élèves (/20) : "<<endl;
	int count=parent->getVectEleve()->size();
	//cout << count <<endl;
	Note noteAEleve;
	for (int noEleve = 0; noEleve < count; ++noEleve)
	{
		pLeleve=&parent->getVectEleve()->at(noEleve);
		cout << pLeleve->getPrenomEleve()<<" "<< pLeleve->getNomEleve()<<" : ";
		noteAEleve.inputNote();
		vectNotes.push_back(noteAEleve);
	}
	displayEvaluation();
}

void Evaluation::displayEvaluation()
{
	cout <<endl;
	int nbEval=parent->getVectEleve()->size();
	// int noteAEleve;
	for (int numEleve = 0; numEleve < nbEval; ++numEleve)
	{
		pLeleve=&parent->getVectEleve()->at(numEleve);
		cout << pLeleve->getPrenomEleve()<<" "<< pLeleve->getNomEleve()<<" : ";
		cout<<vectNotes[numEleve].getNote() <<"/20"<<endl;
	}
}

string Evaluation::getNomEval()
{
	return nomEval;
}

Matiere* Evaluation::getMatiereEval()
{
	return pLaMatiere;
}