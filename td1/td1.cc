#include <iostream>
#include <string.h>
#include "class.h"

using namespace std;

// Exercice 1.a)

void exo1_a() 
{
	int tab [10] = {2, 5, 6, 9, 5, 6, 5, 7, 9, 3} ;
	int * p = tab;

	cout << "\ntab: ";
	
	for (int i=0; i<10; i++)
	{
		cout << p [i] << " ";
	}
	
	// Sinon
	cout << endl;
	
	for (; p < tab + 10; p++) 
	{
		cout << *p <<" ";
	}
	
	cout << endl;
}

// Exercice 1.b)

void exo1_b() 
{
	char * tab [3];
	int i;
	
	tab [0] = new char [strlen ("truc") + 1];
	strcpy (tab [0], "truc");
	tab [1] = new char [strlen ("machin") + 1];
	strcpy (tab [1], "machin");
	tab [2] = new char [strlen ("chose") + 1];
	strcpy (tab [2], "chose");
	
	for (i = 0; i < 3; i++) 
	{
		cout << tab [i] << " ";
	}
	cout << "\n";
	
	for (i = 0; i < 3; i++) 
	{
		delete [] tab [i];
	}
}

// Exercice 2)

void echangeur (int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



