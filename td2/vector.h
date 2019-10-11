#define H_VECTOR_H
#ifndef H_VECTOR_H

#ifdef TAB_DYNAMIQUE

class Vector {
	// Attributs
	private:
		int *vect;
		int dim;
	// Méthodes	
	public:
		// Constructeurs
		Vector (int d);
		Vector (const Vector &v); // de copie
		// Destructeur
		~Vector();
		
		Vector &operator= (const Vector &);
		int &operator [] (int i); // Retourne le ième élément
		Vector &operator+= (const int); // Ajoute un entier au vecteur
		friend ostream &operator <<(ostream &o, Vector v); // Surcharge de l'opérateur
		friend istream &operator >>(istream &is, Vector &v); // Opérateur de saisie
};

#else
 
class Vecteur {
	// Attributs
	private:
		
	// Méthodes
	public:


};
#endif
#endif
