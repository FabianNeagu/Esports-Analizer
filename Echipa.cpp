#include "Echipa.hpp"
#include <iostream>
using namespace std;

istream &operator>>(istream &dev, Echipa &e)
{
    char aux[256];
    dev>>e.nr_playeri;
    dev.getline(aux,256,' ');
    dev.getline(aux,256,'\n');
    e.nume_echipa=aux;
    if(e.nume_echipa[e.nume_echipa.length()-1]==' ')
	{
        e.nume_echipa.erase(e.nume_echipa.length()-1, 1);
    }
    if(e.nr_playeri<=0)
        cout<<"Echipa invalida!";
	else
    	e.v=new Player[e.nr_playeri];
    e.points_echipa=0;
    for(int i=0; i<e.nr_playeri; i++)
        {
		dev>>(Player&)e.v[i];
		e.points_echipa=e.points_echipa+e.v[i].get_points();
		}
    dev.getline(aux,256,'\n');
    e.points_echipa=(float)e.points_echipa/e.nr_playeri;
    return dev;
}
ostream &operator<<(ostream &dev, Echipa &e)
{
	dev<<e.nr_playeri;
	dev<<e.nume_echipa<<endl;
	for(int i=0;i<e.nr_playeri;i++)
	{
		dev<<(Player&)e.v[i];
	}
	dev<<endl<<endl;
	return dev;
}
float Echipa::get_points_echipa()
{
	int s=0;
	for(int i=0;i<nr_playeri;i++)
		s=s+v[i].get_points();
	return (float)s/nr_playeri;
}
Echipa &Echipa::operator=(const Echipa &e)
{
	nr_playeri=e.nr_playeri;
	nume_echipa=e.nume_echipa;
	points_echipa=e.points_echipa;
	v=new Player[nr_playeri];
	for(int i=0;i<nr_playeri;i++)
	{
		v[i]=e.v[i];
	}
	return *this;
}
string Echipa::get_nume_echipa()
{
	return nume_echipa;
}
int Echipa::get_nr_playeri()
{
	return nr_playeri;
}
Player* Echipa::get_player()
{
	return v;
}
void Echipa::set_points_echipa(float p)
{
	points_echipa=p;
}
