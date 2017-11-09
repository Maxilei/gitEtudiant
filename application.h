/** 
\file application.h
\author Maxime IORI
 \version 0.1
 */

 #ifndef APPLICATION
	#define APPLICATION
#include <iostream>
#include <vector>
using namespace std;
#include "section.h"

/**
\class Application
\brief ensemble des éléments et action du menu principal 
*/
class Application
{
private:
	vector <Section> vectSection;
	void afficherMenu();
	char saisieControleDuChoixUtilisateur();
	void realisationActionCorrespondanteAuChoix(char leChoix);	
	
	void afficherSections();
	void creerSection();
	void gererSection();
	
	void afficherMatieres();
	void creerMatiere();

	vector <Matiere> vectMatiere;
public:
/**
\fn vector <Matiere>* getVectMatiereApp()
\return une vecteur pointeur de matière 
\brief utilisée par Application
*/
	vector <Matiere>* getVectMatiereApp();

/**
\fn Application()
\return Une application
\brief Constructeur d'aplication pour jeu d'essai
*/
	Application();

/**
\fn void run()
\brief utilisé par Application Lance l'application 
*/
	void run();

};

#endif

/**
\fn 
\brief 
*/