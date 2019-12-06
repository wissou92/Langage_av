/*=============================================================
 *                       Classe Vector			              *
 *						 (exo2 du TD2)				          *
 *            -----------------------------------    		  *
 *													          *
 * Fichier ent�te.											  *
 *															  *
 * Deux impl�mentation du vecteur:							  *
 *	1- tableau dynamique									  *
 *	2- liste cha�n�e										  *
 *															  *
 *											 Walid Bennaceur  *
 *============================================================*/

//Pour eviter des declarations multiples ou recursives
#ifndef _TD2VECTOR_H
#define _TD2VECTOR_H

#include <iostream>
using namespace std;


//Constante macro qui permet de choisir l'implementation � compiler
//Si cette d�finition est faite, c'est l'impl�mentation par tableau
//dynamique qui est r�alis�e.
//Pour l'impl�mentation par liste cha�n�e, il suffit de mettre en commentaire
//la d�finition de TAB_DYNAMIQUE
//#define TAB_DYNAMIQUE

#ifdef TAB_DYNAMIQUE
//Partie 1. Implementation par tableau dynamique
class Vector
{
//Attributs
private:
	int *vect;
	int dim;	//taille du vecteur = nombre de composantes (ou entiers)
//M�thodes
public:
	//Constructeurs 
	Vector(int d=1);
	Vector(const Vector &v);//de copie
	//Destructeur
	~Vector();
	
	Vector &operator=(const Vector &);
	int & operator [](int i);//Retourne le i�me �l�ment
	Vector &operator+=(const int);	//Ajoute un entier au Vector
	friend ostream &operator <<(ostream &o, Vector &v);//Surchage de l'op�rateur d'affichage.
	friend istream &operator >>(istream &is, Vector &v);//Op�rateur de saisie
};
#else

// Partie 2. Implementation par liste chaine.

//Node est une classe qui represente un element de la liste chaine
class Node
{
	friend class Vector;//Le vecteur sera une classe amie de Node
						//pour acc�der facilement aux attributs.
//Variables membres
private:
	int integer;
	Node *nextNode;
//M�thodes
public:
	Node(int =0);//Constructeur 
	~Node();//destructeur
	int GetInt(){return integer;}
	Node * GetNextNode(){return nextNode;}
	//Nous voyons que nous pouvons d�finir une partie des m�thodes
	//dans la classe elle-m�me et laisser les autres pour l'impl�mentation.
};

class Vector
{
//Variables membres
public:
	Node *head;
	int length;

//M�thodes
public:
	//Constructeur 
	Vector(int =0);
	Vector(const Vector &v);//de copie	
	//Destructeur
	~Vector();

	//Fonctions de gestion de la liste chainee	
	Vector &operator+=(const int);//Ajoute un entier en fin de la liste
	Vector &operator=(const Vector &);	
	int & operator [](int);	
	friend ostream &operator <<(ostream &o, Vector &v);
	friend istream &operator >>(istream &is, Vector &v);
};

#endif
#endif
