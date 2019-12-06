#ifndef FONCTION_HH
#define FONCTION_HH

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>
#include <vector>


//EXO1

template <class T>
T GetMax(const T &x,const T &y)
{
	return x > y ? x : y;
}

template <class T>
class Pair;

// les fonctions template amies d'une classe
// doivent être délarée avant cette classe

template <class T>
ostream &operator <<(ostream&, Pair<T> &);

template <class T>
class Pair
{
	private:
		T x1;
		T x2;
	public:
		// definition dans la classe
		Pair(T x_1, T x_2) {
			x1 = x_1;
			x2 = x_2;
		}
		
		T GetMax();
		
		void DispMax(Pair<T> &p);
		
		friend void Dispx1(Pair<CString>); // fonction friend spécialisée
		friend ostream &operator << <>(ostream&, Pair<T> &);// fonction friend template
		friend ostream &operator << (ostream&, Pair<CString>&);// fonction friend spécialisée
};

// Définition d'une fonction membre template
template<class T>
T Pair<T>::GetMax()
{
	return x1 > x2 ? x1 : x2;
}

// Version spécialisée
// C'est cette version qui sera appelée pour les Pair<int>
template <>
int Pair<int>::GetMax()
{
	cout << "max int ";
	return x1 > x2 ? x1 : x2;
}

// Autre version spécialisée
template <>
float Pair<float>::GetMax()
{
	cout <<"max float ";
	return x1 > x2 ? x1 : x2;
}

// Fonction globale template affichant le maximum de la paire
template <class T>
void DispMax(Pair<T> &p)
{
	cout<<p.GetMax();
}

// Fonction spécialisée pour afficher les CString qui ne définissent pas l'opérateur <<
template <>
void DispMax(Pair<CString> &p)
{
	cout << p.GetMax().GetString();
}

// Fonction amie spécialisée pour les CString 
void Dispx1(Pair<CString> p)
{
	cout << p.x1.GetString();
}

// Opérateur d'affichage template 
ostream & operator<<(ostream &out, Pair<T> &p)
{
	out<<p.x1<<", "<<p.x2;
	return out;
}

// Version spécialisée pour les CString
template <>
ostream &operator<<(ostream& out, Pair<CString> &p)
{
	cout << "spec: ";
	out <<p.x1.GetString()<<", "<<p.x2.GetString();
	return out;
}

#endif
