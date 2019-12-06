#include "dico.h"

// DEFINITION

Definition::Definition(char *m, char *def)
{
	clef = CString(m);
	def = CString(def);
}

CString Definition::GetClef() const
{
	return clef;
}

CString Definition::GetDef() const
{
	cout <
}


// NODE

Node::Node(Definition *d)
{
	def=d;
	nextNode=NULL;
}

Node::~Node()
{
	cout<<"destNode~";
}


// DICO
Dico::Dico(bool own)
{
	head=new Node(NULL);
	length=0;
	isOwner=own;
}

Dico::~Dico()
{
	Destroy(head);
	cout<<endl;
}

// Destruction récursive de la liste.
void Dico::Destroy(Node *n)
{
	if(n)
	{
		if(isOwner && n->def)
			delete n->def;
		Destroy(n->nextNode);
		delete n;
	}
}

void Dico::AddDef(Definition *newDef)
{
	if(!newDef)
		return;
	Node* newNode = new Node(newDef);
	CString entry=newDef->Getclef();
	Node *curNode=head;
	Node *tmp;
	while(tmp=curNode->nextNode)
	{
		CString curClef=tmp->def->GetClef();
		if(curClef>entry)
			break;
		curNode=curNode->nextNode;
	}
	newNode->nextNode=tmp;
	curNode->nextNode=newNode;
	length++;
}

CString Dico::GetDef()(CString &entry)
{
	Node* curNode= head->nextNode;
	CString def ="";
	while (curNode)
	{
		if(!strcmp(entry.GetString(), (curNode->def->GetClef()).getString()))
		{
			def=curNode->def->GetDef();
			break;
		}
		curNode=curNode->nextNode;
	}
	return def;
}
