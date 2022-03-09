#include "StivaPierzatori.hpp"
Echipa pierzatori::get_echipa()
{
	return e;
}
pierzatori* pierzatori::get_urm()
{
	return urm;
}
void adauga_pierzator(pierzatori *&top,Echipa e)
{
	pierzatori *newteam;
	newteam=new pierzatori;
	newteam->e=e;
	newteam->urm=top;
	top=newteam;
}
void stergere_pierzatori(pierzatori *&top)
{
	pierzatori *aux;
	while(top!=NULL)
	{
		aux=top;
		top=top->get_urm();
		delete aux;
	}
}

