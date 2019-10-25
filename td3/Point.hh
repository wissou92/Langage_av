#ifndef POINT_HH
#define POINT_HH

#define MIN_X 0
#define MAX_X 25
#define MIN_Y 0
#define MAX_Y 25

class Point 
{
	private:
		int x;
		int y;

	public:
		// Constructeurs
		Point(int, int);
		Point();
		// Destructeur
		virtual ~Point(){}
		// Méthodes
		// Retourne l'abscisse du point
		int getX() { return this->x;}
		// Retourne l'ordonnée du point
		int getY() { return this->y;}
		// Déplace le point avec des coordonnées données
		void translate(int, int);
		// Affiche les coordonnées du point
		virtual void afficher();

};

class PointColor : public Point 
{
	private:
		char * couleur;
	public:
		// Constructeurs
		PointColor(int, int, char *);
		PointColor(char *);
		// Redéfinition de l'affichage
		virtual void afficher();
		// Destructeurs
		~PointColor(){}
		// getColor
		char * getColor() {return this->couleur;}
};

#endif