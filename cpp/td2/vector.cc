#include <iostream>
#include "vector.h"

//#ifdef TAB_DYNAMIQUE

using namespace std;


// Constructeurs
Vector::Vector (int d) {
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

Vector::Vector () {
	vect = new int [dim = 1];
	vect [0] = 0;
}
// Constructeur de copie
Vector::Vector (const Vector &v) {
	dim = v.dim;
	int k = 0;
	vect = new int[dim];
	for (k=0; k<v.dim; k++)
	{
		vect[k] = v.vect[k];
	}
}

// Destructeur
Vector::~Vector() {
	delete[] vect;
}


// Retourne une référence vers le ième entier du vecteur
// Le retour de référence rend possible la modification des éléments du
// vecteur
int &Vector::operator [](int i) {
	if (i<dim && i >= 0)
		return vect[i];
	cout << "indice hors limites. Dernière composante retournée\n";
	return vect[dim-1];
}

// Opérateur d'affectation
// Cet opérateur permet de copier un vecteur dans un autre
// indépendant du vecteur initial
Vector &Vector::operator= (const Vector &v) {
	if (vect)
		delete[] vect;
	vect = new int [dim = v.dim];
	for (int i=0; i<dim; i++) {
		this->vect [i] = v [i];
	}
	return *this;
}

// Ajoute un entier au vecteur
Vector &Vector::operator +=(const int i) {
	int *newVect = new int [dim + 1];
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
/*
#else

// Partie 2. Implémentation par liste chaînées

//=============
// Classe Node
//=============

// Constructeur
Node::Node(int i)
{
	integer=i;
	nextNode=NULL;
}

Node::~Node()
{
	//Le destructeur fonctionne récursivement (avalanche de destruction)
	//Le destructeur entraine la destruction du noeud suivant etc.
	if(nextNode)
		delete nextNode;
}

//____________________________________________

//=====================
//Classe Vector
//=====================

Vector::Vector (int nElem) 
{
	head=NULL;
	length=0;
	if(nElem<=0)
	{
		cout<<"Dimension <= 0. Vecteur vide\n";
		return;
	}
	
	for (int i=0; i<nElem; i++) 
	{
		*(this)+=0; // Ajout des nElem entiers en utilisant l'opérateur +=
	}
}

Vector::Vector(const Vector &v)
{
	if(!v.head)//cas où v est une liste vide
	{
		head=NULL;
		length=0;
		return;
	}
	head=new Node(v.head->integer);//construction du premier Noeud
	
	Node *thisCurNode= head;// Curseur pour le vecteur this
	Node *vCurNode=v.head->nextNode;//Curseur pour v
	
	while(vCurNode)
	{
		thisCurNode->nextNode=new Node(vCurNode->integer);
		vCurNode = vCurNode->nextNode;
		thisCurNode = thisCurNode->nextNode;
	}
	length = v.length;
}

Vector::~Vector() 
{
	delete head;
	head=NULL;
	length=0;
}

Vector &Vector::operator+=(const int integer)
{
		Node *newNode= new Node(integer);
		if(!head)
			head=newNode;
		else
		{
			Node *n= head;
			// parcourir la liste pour arriver au dernier élément
			while (n->nextNode)
				n=n->nextNode;
			// Insérer le nouveau noeud contenant le nouvel entier
			n->nextNode = newNode;
		}
		length++;
		return *this;
}

Vector &Vector::operator=(const Vector &v)
{
	if((this)==&v)
		return *this;
	if(head)
		delete head;
	head=NULL;
	length=0;
	Node *n=v.head;
	for(int i=0; i<v.length; i++)
	{
		(*this)+=n->integer;
		n=n->nextNode;
		n=nextNode;
	}
	return *this;
}

ostream &operator <<(ostream &o, Vector &v)
{
	Node *curNode=v.head;
	for(int i=0; i<v.length; i++)
	{
		o<<curNode->getInt()<< " ";
		curNode=curNode->getNextNode();
	}
	return o;
}

istream &operator >>(istream &is, Vector &v)
{
	//intnentry = 1;
	cout<<"entrer "<<v.length<<" entiers: ";
	for(int i=0; i<v.length;i++)
		is>>v[i];
	return is;
}

int &Vector::operator [] (int index) 
{
	Node *n= head;
	if (index < 0 || index >= n->length)
		cout << "indice incorrect\n";
	for (int i=0; i<index; i++)
		n=n->nextNode;
	return n->integer;
}

#endif
*/
