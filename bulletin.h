/** 
\file bulletin.h
\author Maxime IORI
 \version 0.1
 */
#ifndef BULLETIN 
 #define BULLETIN
 #include <iostream>
 #include <vector>
using namespace std;

/**
\class Bulletin
\brief Sert a créer les bulletins des élèves (notamment leurs appreciations)
*/
class Bulletin
{
private:
	vector<string> vectAppreciation;
public:
	vector<string>* getAppreciation();

};

#endif