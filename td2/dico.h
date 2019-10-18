#define H_DICO_H
#ifndef H_DICO_H

class Definition
{
	private:
	CString clef;
	CString def;
}


class Dico
{
	private:
		Node *head;
		int length;
		bool isOwner;
		
		void Destroy(Node *); // Méthodes récursives qui sera appelée
							  // par le destructeur
	public:
		Dico(bool=true);
		~Dico();
		void AddDef(Definition*);
		int GetLength();
}

#endif
