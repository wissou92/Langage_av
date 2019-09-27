#ifndef H_CLASS_H
#define H_CLASS_H
#include <iostream>
#include <iomanip>

using namespace std;

class Point {
	
	private:
		int x;
		int y;
	
	public:
		/* Methodes */
		int getAbs() const { 
			return this-> x;
		}
		int getOrd() const {
			return this-> y;		
		}
		void setAbs (int x) {
			this-> x = x;
		}
		void setOrd (int y) {
			this-> y = y;
		}
		
		void afficher() {
			for (int i=0; i<10; i++) 
			{
				if (i == this-> getOrd())
				{
					cout << setw (this-> getAbs() - 1) << "\u26AB";
				}
				cout << endl;
			}
		}
		/* Constructeur */
		Point () {
			this-> x = 0;
			this-> y = 0;
		}
		
		Point (int x, int y) {
			this-> x = x;
			this-> y = y;
		}
		
		Point (Point &p) {
			this-> x = p.getAbs();
			this-> y = p.getOrd();
		}
		
		~Point () {
			cout << "appel au destructeur" << endl;
		}
		
};

#endif
