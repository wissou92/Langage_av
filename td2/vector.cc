#include <iostream>

#ifdef TAB_DYNAMIQUE

using namespace std;


// Constructeurs
Vector (int d) {
	if (d<=0)
	{
		dim = 1;
		vect = new int [1];
		vect[0]=0;
		return;
	}
	dim = d;
	vect = new int [dim]
	int k = 0;
	for (k=0; k<dim; k++) 
	{
		vect[k] = 0;
	}
}

Vector (const Vector &v) {
	dim = v.dim;
	int k = 0;
	vect = new int[dim];
	for (k=0; k<v.dim; k++)
	{
		vect[k] = v.vect[k];
	}
}

// Destructeur
~Vector() {
	delete[] vect;
}


// Retourne une référence vers le ième entier du vecteur
// Le retour de référence rend possible la modification des éléments du
// vecteur
int & Vector::operator [](int i) {
	if (i<dim && i >= 0)
		return vect[i];
	cout << "indice hors limites. Dernière composante retournée\n";
	return vect[dim-1];
}

// Ajoute un entier au vecteur
Vector &Vector::operator +=(const int i) {
	int *newVect = new int [dim];
	for (int k = 0; k<dim; k++)
		newVect[k] = vect[k];
	newVect[dim++] = i;
	if (vect)
		delete[] vect;
	vect = newVect;
	return *this;
}

// Opérateur d'affichage
ostream &operator <<(ostream &o, Vector &v)
{
	for (int i=0; i<v.dim; i++)
	{
		o << v[i]<< " ";
	}
	cout<<endl;
	return o;
}

// Opérateur de saisie
// Cet opérateur suppose la connaissance de la taille du vecteur
// L'utilisateur pourra alors entrer dim entiers séparés par des espaces
// ou par
istream &operator >>(istream &is, Vector &v)
{
	int k=0;
	cout<<"entrer "<<v.dim<<" entiers: ";
	for (k=0; k<v.dim; k++)
	{
		is>>v[k];
	}
	return is;
}

#else


#endif
