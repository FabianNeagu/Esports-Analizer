#include "StivaInvingatori.hpp"
#include <iostream>
#include <string>
#include <string.h>
Echipa invingatori::get_echipa()
{
	return e;
}
invingatori* invingatori::get_urm()
{
	return urm;
}
void adauga_invingator(invingatori *&top,Echipa e)
{
	invingatori *newteam;
	newteam=new invingatori;
	newteam->e=e;
	newteam->urm=top;
	top=newteam;
}
void stergere_invingatori(invingatori *&top)
{
	invingatori *aux;
	while(top!=NULL)
	{
		aux=top;
		top=top->get_urm();
		delete aux;
	}
}
void afisare_invingatori(invingatori *top1,ostream &ofis,int x)
{
	invingatori *i;
	ofis<<"WINNERS OF ROUND NO:"<<x<<endl;
	if(top1->get_urm()!=NULL)
	{
	for(i=top1;i!=NULL;i=i->get_urm())
	{
		ofis<<i->get_echipa().get_nume_echipa();
		for(int j=0;j<(34-(i->get_echipa().get_nume_echipa().size()));j++)
			ofis<<" ";
		ofis<<"-";
		ofis<<"  ";
		ofis<<(setprecision(2))<<fixed<<i->get_echipa().get_points_echipa();
		ofis<<endl;
	}
	}
	else
	{
		ofis<<top1->get_echipa().get_nume_echipa();
		for(int j=0;j<(34-(top1->get_echipa().get_nume_echipa().size()));j++)
			ofis<<" ";
		ofis<<"-";
		ofis<<"  ";
		ofis<<(setprecision(2))<<fixed<<top1->get_echipa().get_points_echipa();
	}
}

