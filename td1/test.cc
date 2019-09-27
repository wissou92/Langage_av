#include <iostream>
#include <string.h>
#include "td1.h"
#include "class.h"

using namespace std;

void testExercice2()
{
	int a = 5; int b = 9;
	echangeur (&a, &b);
	cout << "a=" << a << "; b=" << b << ";" << endl;
}

void testExercice4() 
{
	Point a (8, 7);
	Point b (3, 4);
	
	a.afficher();
	cout << endl;
	b.afficher();
}
