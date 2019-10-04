#ifndef H_CLASS_H
#define H_CLASS_H
#include <iostream>
#include <iomanip>

using namespace std;

class Point {
	
	private:
		int x;
		int y;
	
	public:
		/* Methodes */
		int getAbs() const { 
			return this-> x;
		}
		int getOrd() const {
			return this-> y;		
		}
		void setAbs (int x) {
			this-> x = x;
		}
		void setOrd (int y) {
			this-> y = y;
		}
		
		void afficher() {
			for (int i=0; i<10; i++) 
			{
				if (i == this-> getOrd())
				{
					cout << setw (this-> getAbs() - 1) << "\u26AB";
				}
				cout << endl;
			}
		}
		/* Constructeur */
		Point () {
			this-> x = 0;
			this-> y = 0;
		}
		
		Point (int x, int y) {
			this-> x = x;
			this-> y = y;
		}
		
		Point (Point &p) {
			this-> x = p.getAbs();
			this-> y = p.getOrd();
		}
		
		~Point () {
			cout << "appel au destructeur" << endl;
		}
		
};

class CString {
	
	private:
		static int nbChaine;
		char * chaine;
		int taille;
	public:

		Cstring () 
		{
			chaine = new char [taille = 1];
			chaine[0] = '\0';
			nbChaine++;
		}

		/**
		 * Constructeur à partir d'une chaîne donnée
		 * @param s chaîne de caractères qui sera copié dans l'attribut chaine
		 */
		CString (const char *s)
		{
			chaine = new char [taille = strlen (s) + 1];
			strcpy (chaine, s);
			nbChaine++;
		}

		/**
		* Constructeur à partir d'un caractère donné
		*
		*/
		CString (const char c) 
		{
			chaine = new char [taille = 2];
			chaine [0] = c;
			chaine [1] = '\0';
			nbChaine++;
		}
		/**
		* Constructeur à partir d'un objet de la classe
		* @param s2 objet CString à clôner
		*/
		CString (const CString & s2) 
		{
			chaine = new char [taille = strlen (s2.chaine) + 1];
			strcpy (chaine, s2.chaine);
			nbChaine++;
		}
		
		
		/** 
		 * Destructeur
		 */
		~CString(){}
		
		/**
		* Retourne l'attribut chaine de l'objet
		* @return attribut chaine
		*/
		char * getString()
		{
			return chaine;
		}

		/**
		 * Afficher le nombre de chaînes
		 */
		 // "static" est nécessaire car cette fonction ne peut être
		 // invoquée sur un objet de la classe
		static int nbrChaines() 
		{
			return CString::nbChaine;
		}
		
		/**
		* Affichage d'une chaîne
		*/
		void afficher() 
		{
			cout << "Chaîne = " << getString() << endl;
		}
		
		/**
		 * Concaténation d'une chaîne avec un char
		 * @param char à concaténer avec la chaîne
		 */
		CString concat(const char c)
		{
			char temp [20];
			strcpy (temp, chaine);
			int len = strlen (temp);
			temp [len] = c;
			temp [len + 1] = '\0';
			CString tempS (temp);
			return tempS;
		}
		
		/**
		 * Compare deux chaine de caractère entre elles
		 * et indique si la chaîne est plus grande que la chaîne
		 * donnée
		 * @param s2 Chaîne à comparer
		 * @return boolean 
		 */
		 bool plusGrandQue (CString & s2) 
		 {
		 	if (strcmp (chaine, s2.chaine) > 0) return 1;
		 	else return 0;
		 }
		  
};




#endif
