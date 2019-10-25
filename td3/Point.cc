#include "Point.hh"
#include <iostream>
#include <pthread.h>

Point::Point(int abscisse, int ordonnee) 
{
	if (abscisse <= MAX_X && abscisse >= MIN_X
		&& ordonnee <= MAX_Y && ordonnee >= MIN_Y)
	{
		this->x = abscisse;
		this->y = ordonnee;
	}
	else 
	{
		std::cout << "Coordonnées invalide: point initalisé par défaut (MIN_X, MIN_Y)" << std::endl;
		this->x = MIN_X;
		this->y = MIN_Y;
	}
}

Point::Point() 
{
	this->x = std::rand()%(MAX_X) + MIN_X;
	this->y = std::rand()%(MAX_Y) + MIN_Y;
}


void Point::translate(int dx, int dy)
{
	int newX = this->x + dx;
	int newY = this->y + dy;

	if (newX > MAX_X || newX < MIN_X || newY > MAX_Y || newY < MIN_Y)
	{
		std::cout << "déplacement invalide" << std::endl;
		return;
	}

	this->x = newX;
	this->y = newY;
}

void Point::afficher()
{
	std::cout << "Point(" << this->x << ", " << this->y << ")" << std::endl;
}

PointColor::PointColor(int x, int y, char * color) : Point(x, y)
{
	this->couleur = color;
}

PointColor::PointColor(char * color) : Point () 
{
	this->couleur = color;
}

void PointColor::afficher() 
{
	std::cout << "(" << this->getX() << ", " << this->getY() << ", " << this->getColor() << ")" <<  std::endl; 
}
