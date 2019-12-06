#define H_VECTOR_H
#ifndef H_VECTOR_H

//#ifdef TAB_DYNAMIQUE

class Vector {
	// Attributs
	private:
		int *vect;
		int dim; // taille du vecteur
	// Méthodes
	public:
		// Constructeurs
		Vector (int d);
		Vector (const Vector &v); // de copie
		// Destructeur
		~Vector();
		
		Vector &operator= (const Vector &v);
		int &operator [] (int i); // Retourne le ième élément
		Vector &operator+= (const int); // Ajoute un entier au vecteur
		friend ostream &operator <<(ostream &o, Vector v); // Surcharge de l'opérateur
		friend istream &operator >>(istream &is, Vector &v); // Opérateur de saisie
};

/*#else
 
 // Partie 2 Implémentation par liste chaînées
 
class Node {
	friend class Vector; //Le vecteur sera une classe amie de Node
						 //pour accéder facilement aux attributs.
	// Attributs
	private:
		int integer;
		Node *nextNode;
	// Méthodes
	public:
		Node(int=0);//Constructeur
		~Node();//Destructeur
		int getInt() {return integer;}
		Node * getNextNode() {return nextNode;}

};

class Vector {
	// Variables membres
	private:
		Node *head;
		int length;
	// Méthodes		
	public:
		// Constructeur
		Vector(int =0);
		Vector(const Vector &v);//de copie
		// Destructeur
		~Vector();
		
		// Fonctions de gestion de liste chaînées
		Vector &operator+=(const int);//Ajoute un entier en fin de la liste
		Vector &operator=(const Vector &);
		int &operator[](int);
		friend ostream &operator <<(ostream &o, Vector &v);
		friend istream &operator >>(istream &is, Vector &v);
};


#endif*/
#endif
