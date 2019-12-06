#include "vector.h"
#include <iostream>

using namespace std;

int main (void) {
	Vector v1 = Vector(2);
	Vector v2 = Vector(4);
	
	// Test des différents opérateurs
	cout<<"v1=:"<<v1<<endl;
	cout<<"v2=:"<<v2<<endl;
	v1[0]=56;
	v1[1]=24;
	V1+=3;
	v1[0]=56;
	cout<<"v1=:"<<v1<<endl;
	cout<<"v2=:"<<v2<<endl;
	
	cin>>v1;
	
	cout<<"v1=:"<<v1<<endl;
	
	v2 = v1;
	cout<<"v2=:"<<v2<<endl;
	
	v2 += 67;
	cout<<"v2=:"<<v2<<endl;
	
	return 1;
}
