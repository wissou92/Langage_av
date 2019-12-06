#include "Point.hh"
#include <cstring>



int main(void) 
{
	Point P;
	P.afficher();
	P.translate(2, 4);
	P.afficher();

	char * a = new char[6];
	strcpy (a, "black");
	PointColor P2 (a);
	P.afficher();
	P.translate(1, 1);
	P.afficher();

	return 0;
}