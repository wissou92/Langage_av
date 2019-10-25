/*=============================================================
 *								TD3				              *
 *                 ------------------------------    		  *
 *													          *
 *	Fichier unique.											  *
 *											 Walid Bennaceur  *
 *============================================================*/


#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>


//========
//Exo 1
//========

class Point
{
//Variables membres
public:
	double abs;	//Abscisse
	double ord;	//Ordonnée

//Fonctions membres
public:
	Point()	//Constructeur par défaut
	{
		abs=ord=0;
	}

	Point(double abs, double ord)	//Constructeur à deux paramètres
	{
		this->abs=abs;
		this->ord=ord;
	}

	Point(const Point &p)	//Constructeur de copie
	{
		this->abs=p.abs;
		this->ord=p.ord;
	}

	virtual void afficher()
	{
		cout<<"Point: x = "<<abs<<", y = "<<ord<<"\n";
	}

	void cloner(const Point &p)
	{
		this->abs=p.abs;
		this->ord=p.ord;
	}

	 virtual ~Point()	//Destructeur
	{
		cout<<"\n";
		cout<<"Destruction du Point: x = "<<abs<<", y = "<<ord<<"\n";
	}

};
enum COLOR{BLANC,BLEU,VIOLET,VERT,ROUGE};
//enum définit une enumération. C'est simplement un ensemble d'identificateurs que le compilateur traduira
//en entiers consecutifs. Ce ne sont pas des variables.
//Par défaut, le premier élément d'une énumération est 0
//et les suivants s'en déduisent par incrémentation.
//
//ainsi:
//		int couleur = BLEU;
//		cout<<VERT;
//est équivalent à :
//		int couleur = 1;
//		cout<<3;
//
//C'est utile pour avoir un code plus lisible.

char *coul[5]={"Blanc", "Bleu","Violet","Vert","Rouge"};

//La classe PointColor hérite de Point. Rappelons que l'heritage est 
//conceptuellement equivalent a la relation " est un".
//La definition suivant = PointColor "est un" Point.
//La classe PointColor aura accès aux attributs et méthodes membres public et protected
//de Point, mais pas les private.

class PointColor : public Point
{
//Variables membres
private:
	int couleur;

//Méthodes
public:
	PointColor(double abs, double ord, int c) : Point(abs, ord) //appel du constructeur de la classe de base
	{
		
		couleur=c;		
	}

	virtual void afficher()
	{
		Point::afficher();//Utilise la fontion afficher de la classe mère
		cout<<", Couleur: "<<coul[couleur]<<"\n";
	}

	~PointColor()	//Destructeur
	{
		cout<<"\n";
		cout<<"Destruction du Point Colore: x = "<<abs<<", y = "<<ord<<", Couleur: "<<coul[couleur]<<"\n";
	}

};
	
//=========
//Exo 2
//=========

//Form est une classe abstraite représentant une forme géometrique bidimensionnelle générique .
//Une classe abstraite, comme son nom l'indique est la représentation d'une concept abstrait. 
//Prenons l'exemple de la forme. Une forme n'est pas un objet concret. Ce n'est qu'une idée, un concept
//relié a la perception géometrique des objets. Ceci explique pourquoi une classe abstraite n'est pas 
//instantiable. 
class Form
{
public:
	Form(){};
	virtual ~Form(){cout<<"destructeur Form\n";}
	//---

	//Fonctions virtuelles pures.
	//Attention à la syntaxe.
	virtual void Display()=0;
	virtual void Move(double dx, double dy)=0;
			//Ce sont les fonctions virtuelles pures qui rendent la classe abstraite.
			//Une classe derivée doit imperativement implémenter ces fonctions,
			//sinon, elle serait abstraite a son tour.
};

//Rect est un rectangle dans un plan.
class Rect : public Form
{
private:
	Point position;//les coordonnées du point superieur gauche
	double width;//la dimension horizontale du rectangle;
	double height;//la dimension verticale du rectangle;
public:
	Rect(double abs=0.0, double ord=0.0, double w=1.0, double h=1.0)
		: Form(), position(abs,ord), width(w), height(h)	//Une facon d'initialiser les variables membres
	{}

	virtual ~Rect(){cout<<"destructeur Rect\n";}

	//Définition des fonctions virtuelles 
	virtual void Display()
	{
		cout<<"Rectangle. Position : ";
		position.afficher();
		cout<<"width : "<<width<<", heigth : "<<height<<endl; 
	}

	virtual void Move(double dx, double dy)
	{
		position.abs+=dx;
		position.ord+=dy;
	}
};


class Triangle: public Form
{
private:
	Point s[3];//les sommets du triangle
	
public:
	Triangle(double abs1=0.0, double ord1=0.0, double abs2=0.0, double ord2=0.0,double abs3=0.0, double ord3=0.0)
		: Form() 	
	{
		s[0]=Point(abs1,ord1);
		s[1]=Point(abs2,ord2);
		s[2]=Point(abs3,ord3);

	}

	virtual ~Triangle(){cout<<"destructeur Triangle\n";}

	virtual void Display()
	{
		cout<<"Triangle. Sommets: ";
		for(int i=0;i<3;i++)
			s[i].afficher();
	}

	virtual void Move(double dx, double dy)
	{
		for(int i=0;i<3;i++)
		{
			s[i].abs+=dx;
			s[i].ord+=dy;
		}
	}
};

//=========
//Exo 3
//=========



//Node est une classe qui represente un element de la liste chaine
class Node
{
	
	friend class CList; 
	friend class CPile; 
	friend class CFile; 

	//+ + +
	//Remarque sur l'amitié en C++ (c'est un peu vrai dans la vrai vie!):
	//
	//L'amitié, n'est ni:
	// 1- réciproque
	//		CList est ami de Node, donc, peut accéder à ses données privées.
	//		Mais cela n'implique pas que Node est ami de CList.
	//		(comme quoi, le couple est une affaire de consentement mutuel!)
	//
	// 2- transitive
	//		L'ami de mon ami n'est pas mon ami.		
	//		Par exemple, l'opérateur d'affichage << est ami de CList
	//		Mais, il n'est pas ami de Node, sauf s'il est explicitement declaré ainsi dans Node.
	//		(Problème de jalousie!)
	//
	// 3- hérité: 
	//		CList est déclarée amie de Node. Les CPile et CFile qui dérivent 
	//		de CList, n'héritent cependant pas cette amitié. C'est la raison
	//		pour laquelle, elle ont été explicitement déclarées amies de Node.
	//
	//	Notons enfin que declaré la liste amie du noeud est juste une facon de faire.
	//  Cela exprime le fait que ces deux classe forme un même ensemble fonctionnel.
	//  Mais rien n'empêche que la classe CList par exemple, accède aux données de Nodes
	//  via les méthodes de Node sans aucun privilège.
	//+ + +

//Variables membres
private:
	int integer;
	Node *nextNode;

//Méthodes
public:
	//Constructeur 
	Node(int i=0)
	{
		integer=i;
		nextNode=NULL;
	}
	~Node()
	{
		//Ce destructeur fonctionne recursivement (avalanche de destruction).
		//La destruction entraine la destruction du noeud suivant etc.		
		if(nextNode)
			delete nextNode;
	}
	int GetInt(){return integer;}
	Node * GetNextNode(){return nextNode;}
};

//classe de base de liste chainée d'entiers
class CList
{
protected:
	Node *head;
	int length;

public:
	CList()
	{
		head=NULL;
		length=0;
	}
	//Si on veut un destructeur virtuel, il faut laisser sa définition pour les classes derivées
	//Dans cet exemple, on laisse le soin de la destruction à la classe de base car
	//cette destruction est la même pour les piles et les files.
	virtual ~CList()
	{
		delete head;
		head=NULL;
		length=0;
	}

	friend ostream&operator<<(ostream&, CList&);

	//Opérateur d'empilement: la pile et la file ont chacune sa facon d'empiler
	//On va donc redéfinir cette fonction virtuelle pure dans les classes dérivées.
	virtual CList & operator<(int)=0;//si pas virtual, le polymorphisme ne marche pas.

	//Opérateur de désempilement. le même pour les files et les piles, donc, il est 
	//défini dans la classe de base.
	CList & operator>(int &i)
	{
		if(!head)
		{
			cout<<"La pile est vide\n";
			return *this;			
		}
		//retirer la tete de la pile et mettre sa valeur dans la variable passée en argument
		i=head->integer;
		Node *tmp=head;
		head=head->nextNode;
		tmp->nextNode=NULL; //pour eviter l'effacement recursif
		delete tmp;
		return *this;
	}
};

ostream&operator<<(ostream&out, CList&clist)
{
	Node *curNode=clist.head;
	for(int i=0; i<clist.length;i++)
	{
		out<<curNode->GetInt()<<" ";
		curNode=curNode->GetNextNode();
	}
	return out;
}
//==========

class CPile : public CList
{
public :
	CPile():CList(){}

	//Empile un entier a la tete de la pile
	virtual CList & operator<(int i)
	{
		Node *newNode=new Node(i);
		newNode->nextNode=head;
		head=newNode;
		length++;
		return *this;
	}	

};

//===========

class CFile : public CList
{
public :
	CFile():CList(){}

	//Empile un entier a la fin de la file
	virtual CList & operator<(int i)
	{
		Node *newNode=new Node(i);
		if(!head)
			head=newNode;
		else
		{
			Node *n=head;
			//parcourir la liste pour arriver au dernier element
			while(n->nextNode)
				n=n->nextNode;
			//Inserer le nouveau noeud contenant le nouvel entier
			n->nextNode=newNode;
		}
		length++;
		return *this;
	}

};


//=================================================
int main(int argc, char **argv)
{

//Exo 1	
	PointColor pc=PointColor(2.3,9.6,ROUGE);
	Point p=Point(-2.5, 9.0);
	Point *pp=(&pc);
	pc.afficher();
	p.afficher();

	pp->afficher(); //si la fonction afficher() n'était pas virtuelle et puisque pp est un pointeur 
					//de type Point, c'est la fonction afficher() de la classe Point qui serait appelée.
					//Le point coloré est affiche en tant que Point.
					//Rendre une fonction virtuelle permet la reconnaissance dynamique (a l'execution)
					//du type de l'objet pointé par un pointeur. Dans ce cas, c'est la fonction afficher()
					//de PointColor qui est executée.
					//C'est un exemple de polymorphisme en C++.
	pp=new PointColor(0.3,0.6,VERT);
	delete pp;	//La remarque précédente sur les fonctions virtuelles s'applique egalement 
				//aux destructeurs, ce qui signifie que si on veut qu'a la destruction d'un PointColor
				//dynamique, le destructeur de PointColor soit appelé, il faut que ce destructeur
				//soit virtuel.
				//Il faut toutefois noter que le destructeur de la classe de base
				//est toujours appelé. 

				
	pp=NULL;

//Exo 2
	Form*f=new Rect(2.3,-8.7, 5.6, 9.5);
	f->Display();
	f->Move(7.7,7.7);
	f->Display();
	delete f;

	f=new Triangle(1.0, 1.0, -2.3, -5.0, 2.3, 6.0);
	f->Display();
	f->Move(7.7,7.7);
	f->Display();
	delete f;

	//On voit bien que chaque fois, c'est la bonne fonction move qui est appelée.
	//Encore une fois, c'est le polymorphisme.

//Exo 3

	int i=90;
	CPile pile=CPile();
	CFile file=CFile();	

	CList *ptList=&file;

	*ptList<0<1<2;
	
	cout<<*ptList<<endl;

	*ptList>i;
	cout<<i;

	ptList=&pile;

	*ptList<0<1<2;
	cout<<*ptList<<endl;

	*ptList>i;
	cout<<i;
	
	
return 1;
}

