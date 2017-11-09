/** 
\file section.h
\author Maxime IORI
 \version 0.1
 */

#ifndef SECTION
	#define SECTION
#include <iostream>
using namespace std;
#include "etudiant.h"
#include "evaluation.h"

/**
\class Application 
\brief Pour faire le lien avec la classe application et pouvoir utiliser un pointeur d'application 
*/
class Application;

/**
\class Section
\brief Ensemble des interactions ente l'utilisateur et les sections
*/
class Section
{
private:
/**
\brief Nom de la section
*/
	string nomsection;

/**
\brief vecteur d'élève propre a Section
*/
	vector <Etudiant> vectEleve;

/**
\brief vecteur d'évaluation propre a Section
*/
	vector <Evaluation> vectEval;

/**
\brief vecteur de pointeur de Matière d'Application (parti des matière propre a une Section)
*/
	vector <Matiere*> vectMatiere;

/**
\brief vecteur de coefficient des matière de la Section (ex: Maths est Coef 7 pour la Section Terminal S1)
*/
	vector <int> vectCoeff;

/**
\brief Pointeur d'applicaion permettant le lien entre Section et Application (pour en récupérer les matiere notament)
*/
	Application* parent;
public:
/**
\fn vector<Matiere*> getVectMatiere()
\return un vecteur de pointeur de Matiere d'Application
\brief Méthodes utilisée par Section pour récupérer toutes les matières de Application
*/
	vector<Matiere*> getVectMatiere();

/**
\fn vector<Etudiant>* getVectEleve()
\return un vecteur pointeur d'Etudiants de la Section
\brief Méthode utilisée par Section pour récupérer tous les élève de Section
*/
	vector<Etudiant>* getVectEleve();

/**
\fn Section (Application* lien)
\param adresse d'Application  
\return une Section
\brief Constructeur d'un lien permettant de récupérer des éléments d'Application (notament les matières)
*/
	Section (Application* lien);

/**
\fn Section (string nomDeLaSection, Application* lien)
\param un nom de section et une adresse vers Application
\return une Section
\brief Constructeur d'une section étant dans application (Création de jeu d'essai)
*/
	Section (string nomDeLaSection, Application* lien);

/**
\fn void display()
\brief utilisée par Seciton, affiche le contenu de section
*/
	void display();

/**
\fn void input()
\brief utilisé par Section, demande la saisie des informations d'un Section (son nom)
*/
	void input();

/**
\fn string getNomSection();
return string du nom de la section
\brief utilisée par Section accède au nom de la section
*/
	string getNomSection();

/**
\fn void setNomSection(string nomsection)
\param nom d'une section (a modifier)
\brief utilisée par Section, permet de modifier le nom de la seciton
*/
	void setNomSection(string nomsection);


/**
\fn void affichageTouteMatieresApp()
\brief utilisée par Section, affiche toutes les matières de l'Application
*/	
	void affichageTouteMatieresApp();


/**
\fn void afficherEleves()
\brief utilisée par Section, affiche tous les élève de la section dans laquelle on est 
*/	
	void afficherEleves();


/**
\fn void ajouterEleve()
\brief utilisée par Section, permet d'y ajouter un élève 
*/	
	void ajouterEleve();


/**
\fn void afficherEvaluations()
\brief utilisée par Section, permet d'afficher les notes de chaque élève a une évaluation (to end)
*/	
	void afficherEvaluation();


/**
\fn void ajouterEvaluation()
\brief utilisée par Section, permet d'ajouter une évaluation = une note a chaque élève, une matière et une date(semestre)
*/	
	void ajouterEvaluation();

/**
\fn void afficherMatieres()
\brief utilisée par Section, permet d'afficher les matière de la section 
*/
	void afficherMatieres();
	
/**
\fn void ajouterMatiere()
\brief utilisée par Section, permet d'ajouter une matière a la secion parmis celle d'Application
*/
	void ajouterMatiere();

/**
\fn void runSection()
\brief utilisée par Application, permet de lancer les interactions avec une section séléctionné dans Application  
*/
	void runSection();
	
/**
\fn void AfficherMenuSection()
\brief utilisée par Section, affiche le menu principale de Section
*/
	void AfficherMenuSection();
	
/**
\fn char saisieControleDuChoixUtilisateur()
\return char (lettre choisi par l'utilisateur correspondant a son choix)
\brief Permet de connaitre le choix de l'utilisateur afin d'éxécuter l'aciton demandée 
*/
	char saisieControleDuChoixUtilisateur();
	
/**
\fn void realisationActionCorrespondanteAuChoix(char leChoix)
\brief Exécute l'action choisi par l'utilisateur   
*/
	void realisationActionCorrespondanteAuChoix(char leChoix);	
};
#endif