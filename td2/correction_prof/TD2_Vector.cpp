/*=============================================================
 *                       Classe Vector			              *
 *						 (exo2 du TD2)				          *
 *            -----------------------------------    		  *
 *													          *
 * Ce fichier d'implementation contient deux versions de la   *
 * la classe Vector:										  *
 *															  *
 * 1- Les entiers sont stockés dans un tableau dynamique      *
 * Le code est parsemé de commentaires qui serviront à        *    
 * 2- Les entiers sont stockés une liste chaînée		      *    
 *															  *
 *											 Walid Bennaceur  *
 *============================================================*/


//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// Déclarations
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "TD2_Vector.h"


#ifdef TAB_DYNAMIQUE

//Partie 1. Implementation par tableau dynamique.

//initialise un vecteur à d entiers tous nuls
Vector::Vector(int d)
{
	if(d<=1)
	{
		cout<<"Dimension <=1. Un seul entier (0) sera alloué\n";
		vect = new int[1];
		vect[0]=0;
		dim=1;
		return;
	}
	vect = new int[d];
	dim=d;
	for(int i=0;i<dim;i++)
		vect[i]=0;
}

//Constructeur de copie
Vector::Vector(const Vector &v)
{
	dim=v.dim;
	vect=new int[dim];
	for(int i=0;i<dim;i++)
		vect[i]=v.vect[i];		
}

//Destructeur
Vector::~Vector()
{
	delete []vect;
	vect=NULL;
}

//Operateur d'affectation. Le vecteur appelant sera une copie du vecteur passé en paramètre.
Vector & Vector::operator=(const Vector &v)
{
	//Si le parametre de droite et de gauche sont les memes
	if(this==&v)
		return *this;

	//Sinon, libérer l'objet appelant et le construire comme 
	//étant une copie de v.
	dim=v.dim;
	if (vect)
		delete[] vect;
	vect = new int[dim];
	for (int i=0; i<dim; i++)
		this->vect[i] = v.vect[i];
	return *this;
}


//retourne une reference vers l'ieme entier du vecteur.
//Le retour de reference rend possible la modification des élements du vecteur.
int & Vector::operator [](int i)	
{
	if (i<dim && i>=0)
		return vect[i];
	cout<<"indice hors limites. Dernière composante retournée\n";
	return vect[dim-1];
}

//Ajoute un entier au Vector
Vector &Vector::operator+=(const int i)
{
	int *newVect=new int [dim];	
	for (int k=0; k<dim; k++)	//Copie des composantes du vecteur dans une autre tableau
		newVect[k] = vect[k];
	newVect[dim++]=i;	//ajout du nouvel entier à la fin du nouveau tableau
	if (vect)
		delete[] vect;	//Effacement de l'ancien tableau.	
	vect = newVect;	
	return *this;
}

//Opérateur d'affichage.
ostream &operator <<(ostream &o, Vector &v)
{
	for (int i=0;i<v.dim;i++)
	{
		o<<v[i]<<" ";
	}
	cout<<endl;
	return o;
}

//Opérateur de saisie.
//Cet opérateur suppose la connaissane de la taille du vecteur.
//L'utilisateur pourra alors entrer dim entiers séparés par des espaces ou par des entrées
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

//Partie 2: implémentation par liste chaînée.


//==============
//Classe Node
//==============

//Constructeur 
Node::Node(int i)
{
	integer=i;	
	nextNode=NULL;
}	

Node::~Node()
{
	//Ce destructeur fonctionne récursivement (avalanche de destruction).
	//La destruction entraine la destruction du noeud suivant etc.	
	if(nextNode)
		delete nextNode;
}
//_______________________________________

//==============
//Classe Vector
//==============
//initialise une liste à nElem entiers tous nuls
Vector::Vector(int nElem)
{
	head=NULL;	
	length=0;	
	if(nElem<=0)
	{
		cout<<"Dimension <=0. Vecteur vide\n";
		return;
	}
		
	
	for(int i=0;i<nElem;i++)
		(*this)+=0; //Ajout des nElem entiers en utilisant l'opérateur += défini ci-dessous.
	
}


Vector::Vector(const Vector &v)
{
	if(!v.head)//cas où v est une liste vide
	{
		head=NULL;
		length=0;
		return;
	}
	head=new Node(v.head->integer);//construction du premier noeud.

	Node*thisCurNode=head;//Curseur pour le vecteur this
	Node*vCurNode=v.head->nextNode;//curseur pour v

	while(vCurNode)
	{
		thisCurNode->nextNode=new Node(vCurNode->integer);
		vCurNode=vCurNode->nextNode;
		thisCurNode=thisCurNode->nextNode;
	}
	length=v.length;
}

//Destructeur
Vector::~Vector()
{
	delete head; //effacement recursif
	head=NULL;
	length=0;	
}

Vector &Vector::operator+=(const int integer)
{
	Node *newNode=new Node(integer);
	if(!head)
		head=newNode;
	else
	{
		Node *n=head;
		//parcourir la liste pour arriver au dernier élément
		while(n->nextNode)
			n=n->nextNode;
		//Inserer le nouveau noeud contenant le nouvel entier
		n->nextNode=newNode;
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
	Node*n=v.head;		
	for(int i=0; i<v.length;i++)
	{
		(*this)+=n->integer;		
		n=n->nextNode;
	}
	return *this;
}

ostream &operator <<(ostream &o, Vector &v)
{
	Node *curNode=v.head;
	for(int i=0; i<v.length;i++)
	{
		o<<curNode->GetInt()<<" ";
		curNode=curNode->GetNextNode();
	}
	return o;
}

//Saisie de nouvelles valeurs pour le vecteur.
istream &operator >>(istream &is, Vector &v)
{
	int entry=-1;
	cout<<"entrer "<<v.length<<" entiers: ";
	for(int i=0;i<v.length;i++)
		is>>v[i];	
	return is;

}

int & Vector::operator [](int index)
{
	
	Node*n=head;
	for(int i=0; i<index;i++)
		n=n->nextNode;
	return n->integer;
}

#endif


////////////////////////////
///Fonction Principale/////
///////////////////////////
int main(int argc, char **argv)
{

	//Ce test fonctionne avec les deux implémentations du vecteur.
	//Cela montre l'utilité de l'encapsulation des données dans une classe
	//et la fourniture de fonctions interfaces, qui font abstraction
	//de l'implémentation du code.


	Vector v1=Vector(2);
	Vector v2=Vector(4);
	
	//Test des differents operateurs
	cout<<"v1=:"<<v1<<endl;
	cout<<"v2=:"<<v2<<endl;
	v1[0]=56;
	v1[1]=24;
	v1+=3;
	v1[0]=56;
	cout<<"v1=:"<<v1<<endl;
	cout<<"v2=:"<<v2<<endl;
	
	cin>>v1;

	cout<<"v1=:"<<v1<<endl;

	v2=v1;
	cout<<"v2=:"<<v2<<endl;

	v2+=67;
	cout<<"v2=:"<<v2<<endl;


return 1;
}

