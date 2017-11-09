#include "application.h"
#include "matiere.h"
#include <algorithm>
#include <cstdlib>
#include <typeinfo> 
#include <string>


Application::Application()
{
	Matiere Maths("Maths");
	Matiere Francais("Francais");
	vectMatiere.push_back(Maths);
	vectMatiere.push_back(Francais);
	Section SIO("SIO",this);
	Section NRC("NRC",this);
	vectSection.push_back(SIO);
	vectSection.push_back(NRC);

}

void Application::afficherMenu()
{
	//Liste des choix (=menu)
	cout<<endl<< " Choisissez l'option souhaiter en tapant la lettre correspondante : \n (c) Créer un Section \t\t (d) Afficher les Sections \n (m) Ajouter une matiere \t (l) Afficher toutes les matières \n (g) Gérer une section \t\t (q) Quitter"<<endl;		
}

char Application::saisieControleDuChoixUtilisateur()
{
	char leChoix;
	cout <<endl<< "Entrez votre choix : ";
	cin>>leChoix;
	return leChoix;
}

void Application::creerSection()
{
	cout << endl;
	Section nouvelleSection(this);
	nouvelleSection.input();
	cout <<endl;
	bool verif=1;
	int nbSection3=vectSection.size();
	for (int sectionCourante3 = 0; sectionCourante3 < nbSection3; ++sectionCourante3)
	{
		std::string nomNouvelleSectionMaj = nouvelleSection.getNomSection();
		std::transform(nomNouvelleSectionMaj.begin(), nomNouvelleSectionMaj.end(),nomNouvelleSectionMaj.begin(), ::toupper);
		std::string nomSectionCouranteMaj = vectSection[sectionCourante3].getNomSection();
		std::transform(nomSectionCouranteMaj.begin(), nomSectionCouranteMaj.end(),nomSectionCouranteMaj.begin(), ::toupper);
		
		if (nomNouvelleSectionMaj==nomSectionCouranteMaj)
		{
			system("clear");
			//Si la section existe déjà :
			cout <<endl<< "La section éxiste déjà. "<<endl;
			verif = 0;
		}
	}
	if (verif==1)
	{
		vectSection.push_back(nouvelleSection);
		system("clear");
	}

}

void Application::gererSection()
{
	//Affichage des sections pour en choisir une a gérer
	int nbSection=vectSection.size();
	for (int sectionCourante = 0; sectionCourante < nbSection; sectionCourante++)
	{
			cout<<sectionCourante+1<< " :\t"<<vectSection[sectionCourante].getNomSection()<<endl;
	}
	//Affichage choisir une section => entrer dans le menu de gestion
	cout << "Qelle section voulez-vous gérer : ";
	int sectionAGerer;
	cin>> sectionAGerer;
	string a;
	getline(cin,a);
	int sectionGerer = atoi(a.c_str());	
	cout << sectionGerer;
	if (int sectionGerer = atoi(a.c_str()))
	{
		cout << sectionGerer<<endl;
		cout << endl <<"Entrée valide !" <<endl;
	}
	if ( ! (sectionAGerer > 0 && sectionAGerer < nbSection+1) )
	{
		system("clear");
		cout <<endl<< "Entrez un numéro valide !"<<endl;
	}
	else 
	{
		for (int sectionCourante = 0; sectionCourante < nbSection; ++sectionCourante)
		{
			if (sectionAGerer==sectionCourante+1)
			{
				//Si la section existe :
				//system("clear");
				// cout<<"type du : "<<typeid (sectionAGerer).name()<<endl;
				cout<<"Menu de la section "<<vectSection[sectionCourante].getNomSection();
				vectSection[sectionCourante].runSection();			
			}
		}
	}
}

void Application::afficherSections()
{
	int nbSection=vectSection.size();
	for (int sectionCourante2 = 0; sectionCourante2 < nbSection; sectionCourante2++)
	{
			cout<<sectionCourante2+1<<" :\t"<<vectSection[sectionCourante2].getNomSection()<<endl;
	}
}

void Application::afficherMatieres()
{
	cout<<endl;
	int nbMatiere=vectMatiere.size();
	for (int MatiereCourante2 = 0; MatiereCourante2 < nbMatiere; MatiereCourante2++)
	{
			cout<<MatiereCourante2+1<<" :\t"<<vectMatiere[MatiereCourante2].getNomMatiere()<<endl;
	}
}

void Application::creerMatiere()
{
	Matiere nouvelleMatiere;
	nouvelleMatiere.input();
	bool verif = 1;
	int nbMatiere=vectMatiere.size();
	for (int matiereCourante = 0; matiereCourante < nbMatiere; ++matiereCourante)
	{
		//Transforme la chaine de caractère (nouvelleMatiere.getNomMatiere()) en MAJUSCULE
		std::string maChaineMaj2 = nouvelleMatiere.getNomMatiere();
		std::transform(maChaineMaj2.begin(), maChaineMaj2.end(),maChaineMaj2.begin(), ::toupper);
		//Transforme la chaine en masjucule
		std::string maChaineMaj = vectMatiere[matiereCourante].getNomMatiere();
		std::transform(maChaineMaj.begin(), maChaineMaj.end(),maChaineMaj.begin(), ::toupper);
		if (maChaineMaj==maChaineMaj2)
		{
			//Si la matière existe déjà :
			system("clear");
			cout <<endl<< "La matière éxiste déjà. "<<endl;
			verif = 0;
		}
	}
	if (verif==1)
	{
		vectMatiere.push_back(nouvelleMatiere);
		system("clear");
	}
	
}

void Application::realisationActionCorrespondanteAuChoix(char leChoix)	
{
	do
	{
		//Liste des choix (=menu)
		//afficherMenu();
		//saisieControleDuChoixUtilisateur();
		switch (leChoix)
		{
			case 'c': //créer une section
			{
				creerSection();
			}
			break;
			case 'g'://gérer une section
			{
				gererSection();
			}
			break;
			case 'm':
			{
				creerMatiere();
			}
			break;
			case 'l':
			{
				afficherMatieres();
			}
			break;
			case 'd': //(afficher)display une section
			{
				cout << endl;
				afficherSections();
			}
			break;
			default:
				cout<< "Veuillez entrer un message valdie !";
			break;
		}
	}while (!(leChoix = 'q')); //quitter 	
}

void Application::run()
{
	char leChoixDeLutilisateur;
	do
	{
		afficherMenu();
		leChoixDeLutilisateur = saisieControleDuChoixUtilisateur();
		realisationActionCorrespondanteAuChoix(leChoixDeLutilisateur);
	}while(!(leChoixDeLutilisateur =='q'));
	

	// for (int i = 0; i < vectSection.size(); i++)
	// 	{
	// 		delete vectSection[i];
	// 	}
}

vector<Matiere>* Application::getVectMatiereApp()
{
	return &vectMatiere;
}