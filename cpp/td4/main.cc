#include <iostream>
#include "fonction.hh"


using namespace std;

int main() {
	// exo 1
	int i=5, j=6, k;
	float l=10.0, m=5.0, n;
	
	k = GetMax<int>(i, j);
	n = GetMax<float>(l, m);
	
	cout << k << endl;
	cout << n << endl;
	return 0;
	
	// exo 2
	
}
