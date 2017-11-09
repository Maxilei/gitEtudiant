#include <vector>
#include <cstdlib>
#include "section.h"
#include "application.h"
#include <algorithm>

Section::Section(string nomDeLaSection,Application* lien)
{
	nomsection=nomDeLaSection;
	parent=lien;
}

Section::Section (Application* lien)
{
	parent=lien;
}

//Fonction de saisie de section
void Section::input()
{
	cout<< "Nom de la section :";
	cin.ignore(1);
	getline(cin, nomsection);
}

void Section::display()
{
	cout << "Nom de la section : "<<nomsection<<endl;
}

string Section::getNomSection()
{
	return nomsection;
}

void Section::AfficherMenuSection()
{
	cout<<endl<< "Choisissez l'option souhaitée : \n (a) Ajouter un élève a la section \t\t (d) Afficher tous les élèves \n (m) Ajouter une matière a la section \t\t (p) Afficher toutes les matières de la section \n (e) Ajouter une Evaluation a la section \t (v) Afficher une évaluation \n (q) Retour"<<endl;
}

void Section::ajouterEleve()
{
	cout << endl;
	Etudiant nouvelEtudiant;
	nouvelEtudiant.input();
	cout <<endl;
	bool verif=1;
	int nbEtudiant=vectEleve.size();
	for (int eleveCourant = 0; eleveCourant < nbEtudiant; ++eleveCourant)
	{
		//Transforme la chaine de caractère en MAJUSCULE
		std::string maChaineMaj2 = nouvelEtudiant.getPrenomEleve();
		std::transform(maChaineMaj2.begin(), maChaineMaj2.end(),maChaineMaj2.begin(), ::toupper);
		//Transforme la chaine en masjucule
		std::string maChaineMaj = vectEleve[eleveCourant].getPrenomEleve();
		std::transform(maChaineMaj.begin(), maChaineMaj.end(),maChaineMaj.begin(), ::toupper);
		//if (maChaineMaj3==maChaineMaj4)
		
		std::string maChaineMaj4 = nouvelEtudiant.getNomEleve();
		std::transform(maChaineMaj4.begin(), maChaineMaj4.end(),maChaineMaj4.begin(), ::toupper);
		//Transforme la chaine en masjucule
		std::string maChaineMaj3 = vectEleve[eleveCourant].getNomEleve();
		std::transform(maChaineMaj3.begin(), maChaineMaj3.end(),maChaineMaj3.begin(), ::toupper);

		if (maChaineMaj==maChaineMaj2 and maChaineMaj3==maChaineMaj4)
		{
			//Si la section existe déjà :
			cout <<endl<< "L'élève éxiste déjà. "<<endl;
			verif = 0;
		}
	}
	if (verif==1)
	{
		vectEleve.push_back(nouvelEtudiant);
	}
}

void Section::afficherEleves()
{
	int nbEleve=vectEleve.size();
	for (int etudiantCourant = 0; etudiantCourant < nbEleve; etudiantCourant++)
	{
		vectEleve[etudiantCourant].display();
	}
}

void Section::ajouterMatiere()
{
	system("clear");
	cout<< "Quelle matière voulez-vous ajouter a la section : "<<endl;
	affichageTouteMatieresApp();
	int matiereAAdd=0;
	cout<< endl<<"Entrez son nunméro :";
	cin>> matiereAAdd;
	int nbMatiere=parent->getVectMatiereApp()->size();
	for (int MatiereCourante = 0; MatiereCourante < nbMatiere; MatiereCourante++)
	{
		if (matiereAAdd-1==MatiereCourante)
		{
			//Ajout des coef après que la matière ait été ajouté a la section :
			int Coefficient;
			//parent->getVectMatiereApp()[MatiereCourante]
			cout<< " Coefficient : ";
			cin>>Coefficient;
			vectCoeff.push_back(Coefficient);
			vectMatiere.push_back(&parent->getVectMatiereApp()->at(MatiereCourante));
		}
	}

}

void Section::affichageTouteMatieresApp()
{
	system("clear");
	cout<<"Toute les matières possibles : "<<endl;
	int nbMatiere=parent->getVectMatiereApp()->size();
	for (int MatiereCourante2 = 0; MatiereCourante2 < nbMatiere; MatiereCourante2++)
	{
			cout<<MatiereCourante2+1<<" :\t"<<parent->getVectMatiereApp()->at(MatiereCourante2).getNomMatiere()<<endl;
	}
}

void Section::afficherMatieres()
{
	system("clear");
	cout<<"Matière(s) de la section : "<<endl;
	int nbMatiere=vectMatiere.size();
	for (int MatiereCourante2 = 0; MatiereCourante2 < nbMatiere; MatiereCourante2++)
	{
			cout<<MatiereCourante2+1<<" :\t"<<vectMatiere[MatiereCourante2]->getNomMatiere()<<endl;
	}
}

void Section::ajouterEvaluation()
{
	system("clear");
	Evaluation controle(this);
	controle.inputEvaluation();
	vectEval.push_back(controle);
}

void Section::afficherEvaluation()
{
	int choixEval;
	cout<<endl<<"Evaluation de la section : "<<endl;
	int nbEval=vectEval.size();
	for (int EvalCourante = 0; EvalCourante < nbEval; EvalCourante++)
	{
		cout << "Numéro du contrôle : "<< EvalCourante+1 <<endl;
		cout << "Nom évaluation : ";
		cout << vectEval[EvalCourante].getNomEval()<<endl;
		cout << "Matière : ";
		cout << vectEval[EvalCourante].getMatiereEval()->getNomMatiere()<<endl<<endl;
		//affichage des notes des étudiants
	}
	cout<< "Entrez le numéro du controle auquel vous voulez accéder : ";
	cin >> choixEval; 
		vectEval[choixEval-1].displayEvaluation();
		cout <<endl;
}
	

char Section::saisieControleDuChoixUtilisateur()
{
	char leChoix;
	cout <<endl<< "Entrez votre choix : ";
	cin>>leChoix;
	return leChoix;
}

void Section::realisationActionCorrespondanteAuChoix(char leChoix)	
{
	do
	{
		//Liste des choix (=menu)
		//afficherMenu();
		//saisieControleDuChoixUtilisateur();
		switch (leChoix)
		{
			case 'a': //créer une section
			{
				ajouterEleve();
			}
			break;
			case 'd'://gérer une section
			{
				afficherEleves();
			}
			break;
			case 'm':
			{
				ajouterMatiere();
			}
			break;
			case 'p':
			{
				afficherMatieres();
			}
			break;
			case 'v':
			{
				afficherEvaluation();
			}
			break;
			case 'e':
			{
				ajouterEvaluation();
				//system("clear");
			}
			break;
			default:
				cout<< "Veuillez entrer un message valdie !";
			break;
		}
	}while (!(leChoix = 'q')); //quitter 
}

void Section::runSection()
{
	char leChoixDeLutilisateur;
	do
	{
		AfficherMenuSection();
		leChoixDeLutilisateur = saisieControleDuChoixUtilisateur();
		realisationActionCorrespondanteAuChoix(leChoixDeLutilisateur);
	}while(!(leChoixDeLutilisateur =='q'));

}

vector<Matiere*> Section::getVectMatiere()
{
	return vectMatiere;
}

vector<Etudiant>* Section::getVectEleve()
{
	return &vectEleve;
}