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
	double ord;	//Ordonn�e

//Fonctions membres
public:
	Point()	//Constructeur par d�faut
	{
		abs=ord=0;
	}

	Point(double abs, double ord)	//Constructeur � deux param�tres
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
//enum d�finit une enum�ration. C'est simplement un ensemble d'identificateurs que le compilateur traduira
//en entiers consecutifs. Ce ne sont pas des variables.
//Par d�faut, le premier �l�ment d'une �num�ration est 0
//et les suivants s'en d�duisent par incr�mentation.
//
//ainsi:
//		int couleur = BLEU;
//		cout<<VERT;
//est �quivalent � :
//		int couleur = 1;
//		cout<<3;
//
//C'est utile pour avoir un code plus lisible.

char *coul[5]={"Blanc", "Bleu","Violet","Vert","Rouge"};

//La classe PointColor h�rite de Point. Rappelons que l'heritage est 
//conceptuellement equivalent a la relation " est un".
//La definition suivant = PointColor "est un" Point.
//La classe PointColor aura acc�s aux attributs et m�thodes membres public et protected
//de Point, mais pas les private.

class PointColor : public Point
{
//Variables membres
private:
	int couleur;

//M�thodes
public:
	PointColor(double abs, double ord, int c) : Point(abs, ord) //appel du constructeur de la classe de base
	{
		
		couleur=c;		
	}

	virtual void afficher()
	{
		Point::afficher();//Utilise la fontion afficher de la classe m�re
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

//Form est une classe abstraite repr�sentant une forme g�ometrique bidimensionnelle g�n�rique .
//Une classe abstraite, comme son nom l'indique est la repr�sentation d'une concept abstrait. 
//Prenons l'exemple de la forme. Une forme n'est pas un objet concret. Ce n'est qu'une id�e, un concept
//reli� a la perception g�ometrique des objets. Ceci explique pourquoi une classe abstraite n'est pas 
//instantiable. 
class Form
{
public:
	Form(){};
	virtual ~Form(){cout<<"destructeur Form\n";}
	//---

	//Fonctions virtuelles pures.
	//Attention � la syntaxe.
	virtual void Display()=0;
	virtual void Move(double dx, double dy)=0;
			//Ce sont les fonctions virtuelles pures qui rendent la classe abstraite.
			//Une classe deriv�e doit imperativement impl�menter ces fonctions,
			//sinon, elle serait abstraite a son tour.
};

//Rect est un rectangle dans un plan.
class Rect : public Form
{
private:
	Point position;//les coordonn�es du point superieur gauche
	double width;//la dimension horizontale du rectangle;
	double height;//la dimension verticale du rectangle;
public:
	Rect(double abs=0.0, double ord=0.0, double w=1.0, double h=1.0)
		: Form(), position(abs,ord), width(w), height(h)	//Une facon d'initialiser les variables membres
	{}

	virtual ~Rect(){cout<<"destructeur Rect\n";}

	//D�finition des fonctions virtuelles 
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
	//Remarque sur l'amiti� en C++ (c'est un peu vrai dans la vrai vie!):
	//
	//L'amiti�, n'est ni:
	// 1- r�ciproque
	//		CList est ami de Node, donc, peut acc�der � ses donn�es priv�es.
	//		Mais cela n'implique pas que Node est ami de CList.
	//		(comme quoi, le couple est une affaire de consentement mutuel!)
	//
	// 2- transitive
	//		L'ami de mon ami n'est pas mon ami.		
	//		Par exemple, l'op�rateur d'affichage << est ami de CList
	//		Mais, il n'est pas ami de Node, sauf s'il est explicitement declar� ainsi dans Node.
	//		(Probl�me de jalousie!)
	//
	// 3- h�rit�: 
	//		CList est d�clar�e amie de Node. Les CPile et CFile qui d�rivent 
	//		de CList, n'h�ritent cependant pas cette amiti�. C'est la raison
	//		pour laquelle, elle ont �t� explicitement d�clar�es amies de Node.
	//
	//	Notons enfin que declar� la liste amie du noeud est juste une facon de faire.
	//  Cela exprime le fait que ces deux classe forme un m�me ensemble fonctionnel.
	//  Mais rien n'emp�che que la classe CList par exemple, acc�de aux donn�es de Nodes
	//  via les m�thodes de Node sans aucun privil�ge.
	//+ + +

//Variables membres
private:
	int integer;
	Node *nextNode;

//M�thodes
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

//classe de base de liste chain�e d'entiers
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
	//Si on veut un destructeur virtuel, il faut laisser sa d�finition pour les classes deriv�es
	//Dans cet exemple, on laisse le soin de la destruction � la classe de base car
	//cette destruction est la m�me pour les piles et les files.
	virtual ~CList()
	{
		delete head;
		head=NULL;
		length=0;
	}

	friend ostream&operator<<(ostream&, CList&);

	//Op�rateur d'empilement: la pile et la file ont chacune sa facon d'empiler
	//On va donc red�finir cette fonction virtuelle pure dans les classes d�riv�es.
	virtual CList & operator<(int)=0;//si pas virtual, le polymorphisme ne marche pas.

	//Op�rateur de d�sempilement. le m�me pour les files et les piles, donc, il est 
	//d�fini dans la classe de base.
	CList & operator>(int &i)
	{
		if(!head)
		{
			cout<<"La pile est vide\n";
			return *this;			
		}
		//retirer la tete de la pile et mettre sa valeur dans la variable pass�e en argument
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

	pp->afficher(); //si la fonction afficher() n'�tait pas virtuelle et puisque pp est un pointeur 
					//de type Point, c'est la fonction afficher() de la classe Point qui serait appel�e.
					//Le point color� est affiche en tant que Point.
					//Rendre une fonction virtuelle permet la reconnaissance dynamique (a l'execution)
					//du type de l'objet point� par un pointeur. Dans ce cas, c'est la fonction afficher()
					//de PointColor qui est execut�e.
					//C'est un exemple de polymorphisme en C++.
	pp=new PointColor(0.3,0.6,VERT);
	delete pp;	//La remarque pr�c�dente sur les fonctions virtuelles s'applique egalement 
				//aux destructeurs, ce qui signifie que si on veut qu'a la destruction d'un PointColor
				//dynamique, le destructeur de PointColor soit appel�, il faut que ce destructeur
				//soit virtuel.
				//Il faut toutefois noter que le destructeur de la classe de base
				//est toujours appel�. 

				
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

	//On voit bien que chaque fois, c'est la bonne fonction move qui est appel�e.
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

