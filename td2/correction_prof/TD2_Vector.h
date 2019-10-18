/*=============================================================
 *                       Classe Vector			              *
 *						 (exo2 du TD2)				          *
 *            -----------------------------------    		  *
 *													          *
 * Fichier entête.											  *
 *															  *
 * Deux implémentation du vecteur:							  *
 *	1- tableau dynamique									  *
 *	2- liste chaînée										  *
 *															  *
 *											 Walid Bennaceur  *
 *============================================================*/

//Pour eviter des declarations multiples ou recursives
#ifndef _TD2VECTOR_H
#define _TD2VECTOR_H

#include <iostream>
using namespace std;


//Constante macro qui permet de choisir l'implementation à compiler
//Si cette définition est faite, c'est l'implémentation par tableau
//dynamique qui est réalisée.
//Pour l'implémentation par liste chaînée, il suffit de mettre en commentaire
//la définition de TAB_DYNAMIQUE
//#define TAB_DYNAMIQUE

#ifdef TAB_DYNAMIQUE
//Partie 1. Implementation par tableau dynamique
class Vector
{
//Attributs
private:
	int *vect;
	int dim;	//taille du vecteur = nombre de composantes (ou entiers)
//Méthodes
public:
	//Constructeurs 
	Vector(int d=1);
	Vector(const Vector &v);//de copie
	//Destructeur
	~Vector();
	
	Vector &operator=(const Vector &);
	int & operator [](int i);//Retourne le ième élément
	Vector &operator+=(const int);	//Ajoute un entier au Vector
	friend ostream &operator <<(ostream &o, Vector &v);//Surchage de l'opérateur d'affichage.
	friend istream &operator >>(istream &is, Vector &v);//Opérateur de saisie
};
#else

// Partie 2. Implementation par liste chaine.

//Node est une classe qui represente un element de la liste chaine
class Node
{
	friend class Vector;//Le vecteur sera une classe amie de Node
						//pour accéder facilement aux attributs.
//Variables membres
private:
	int integer;
	Node *nextNode;
//Méthodes
public:
	Node(int =0);//Constructeur 
	~Node();//destructeur
	int GetInt(){return integer;}
	Node * GetNextNode(){return nextNode;}
	//Nous voyons que nous pouvons définir une partie des méthodes
	//dans la classe elle-même et laisser les autres pour l'implémentation.
};

class Vector
{
//Variables membres
public:
	Node *head;
	int length;

//Méthodes
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
