#include "Player.hpp"
#include <iostream>

Player::Player()
{
	firstName="";
    secondName="";
    points=0;
}
istream &operator>>(istream &dev,Player &p)
{
	char aux[256];
	int n;
	dev.getline(aux,256,' ');
	p.firstName=aux;
	dev.getline(aux,256,' ');
	p.secondName=aux;
	dev>>n;
	p.points=n;
	return dev;
}
ostream &operator<<(ostream &dev,Player &p)
{
	dev<<p.firstName<<" ";
	dev<<p.secondName<<" ";
	dev<<p.points;
	return dev;
}
int Player::get_points()
{
	return points;
}
void Player::set_points(int p)
{
	points=p;
}

