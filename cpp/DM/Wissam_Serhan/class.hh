// Déclaration des templates des différentes classes
template <class T>
class CList;

template <class T>
class CPile;

template <class T>
class CFile;

//=============================================
//classe Node : élément des listes/piles/files
//=============================================
template <class T>
class Node {
	
	friend class CList; 
	friend class CPile; 
	friend class CFile; 	

	//Attributs
	private:
		T element;
		Node<T> *nextNode;

	//Méthodes
	public:
		//Constructeur 
		Node(T elem) {
			element = elem;
			nextNode=NULL;
		}
		//Destructeur
		~Node() {	
			if(nextNode)
				delete nextNode;
		}
		//Fonctions
		T GetElem(){return element;}
		Node<T> * GetNextNode(){return nextNode;}
};


//===============================
//Classe CList : Listes chaînées
//===============================
template <class T>
class CList
{
	protected:
		Node<T> *head;
		int length;

	public:
		CList() {
			head=NULL;
			length=0;
		}
		
		virtual ~CList() {
			delete head;
			head=NULL;
			length=0;
		}

		friend ostream &operator<< (ostream&, CList&);

		//Opérateur d'empilement
		//On va donc redéfinir cette fonction purement virtuelle dans les classes dérivées.
		virtual CList & operator< (T)=0;
 
		//Opérateur de désempilement.
		//Défini dans la classe de base.
		CList & operator>(T &i)
		{
			if(!head)
			{
				cout<<"La pile est vide\n";
				return *this;			
			}
			//retirer la tete de la pile et mettre sa valeur dans la variable passée en argument
			i=head->element;
			Node<T> *tmp=head;
			head=head->nextNode;
			tmp->nextNode=NULL; //pour éviter l'effacement récursif
			delete tmp;
			return *this;
		}
};

ostream &operator<< (ostream &out, CList<T> &clist)
{
	Node<T> *curNode=clist.head;
	for(int i=0; i<clist.length;i++)
	{
		out<<curNode->GetElem()<<" ";
		curNode=curNode->GetNextNode();
	}
	return out;
}


//=====================
// classe CPile : pile
//=====================
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


//=====================
// Classe CFile : file
//=====================
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
