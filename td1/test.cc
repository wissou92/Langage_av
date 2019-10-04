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

void testExercice6()
{
	CString s1 ( "toto" ), s2 ( 'q' ), s3;
	
	cout << "nbrChaines" << CString::nbrChaines() << endl ;
	
	//afficher le nombre de chaines créées
	s3 = s1.plus( 'w' ) ;
	cout << "s3=" << s3.getString() << endl ;
	
	if( s1.plusGrandQue(s2) ) // si s1 > s2 au sens alphabétique
		cout << "plus grand" << endl ;
		
	if( s1.infOuEgale(s2) ) // si s1 <= s2 au sens alphabétique
		cout << "plus petit" << endl ;
	s3 = s1.plusGrand( s2 ) ;// retourner s1 si s1>s2, s2 sinon
}
