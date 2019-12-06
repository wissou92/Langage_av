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
	
	
	
	
	
	
	
	//Si on veut un destructeur virtuel, il faut laisser sa définition pour les classes derivées
		//Dans cet exemple, on laisse le soin de la destruction à la classe de base car
		//cette destruction est la même pour les piles et les files.
		// CList()
