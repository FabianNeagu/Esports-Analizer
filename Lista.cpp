#include "Lista.hpp"
#include <fstream>
#include <iostream>
using namespace std;

lista *lista::lista_init(istream &ifis,int n)
{

	lista *cap_lista;
	lista *p;
	lista *q;
 	p=new lista;
 	ifis>>(p->e);
 	p->urm=NULL;
 	cap_lista=p;
 	for(int i=1;i<n;i++)
 	{
 		q=new lista;
 		ifis>>(q->e);
 		q->urm=cap_lista;
 		cap_lista=q;
	}
	return cap_lista;
}
void afisare_lista(lista *cap_lista,ostream &ofis)
{
	lista *p;
	for(p=cap_lista;p!=NULL;p=p->urm)
	{
		ofis<<p->e.get_nume_echipa();
		if(p->urm!=NULL)
			ofis<<endl;
	}
	
}

void eliminare_element(lista *&cap_lista)
{
	lista *p;
	lista *aux;
	float min;
	min=cap_lista->e.get_points_echipa();
	for(p=cap_lista->urm;p!=NULL;p=p->urm)
	{	
		if(min>(p->e.get_points_echipa()))
			min=p->e.get_points_echipa();
	}
	for(p=cap_lista;p!=NULL;p=p->urm)
	{
		if(p->e.get_points_echipa()==min&&p==cap_lista)
			
			{
				cap_lista=cap_lista->urm;
				delete p;
				break;
			}
		if(p->urm->e.get_points_echipa()==min&&p->urm->urm==NULL)
			{
				delete p->urm;
				p->urm=NULL;
				break;
			}
		
		if(p->urm->e.get_points_echipa()==min)
		{
			aux=p->urm;
			delete p->urm;
			p->urm=aux->urm;
			break;	
		}	
	}
}
void eliminare_toate(lista *&cap_lista,int n)
{
	int i=1;
	int index=0;
	while(n>i)
	{
		i=i*2;
		index++;
	}
	i=i/2;
	for(int j=0;j<n-i;j++)
	{
		eliminare_element(cap_lista);
	}
}
void lista::stergere_lista(lista *&cap_lista)
{
	lista *aux;
	while(cap_lista!=NULL)
	{
		aux=cap_lista->get_urm();
		delete cap_lista;
		cap_lista=aux;
	}
	cap_lista=NULL;

}
Echipa lista::get_echipa()
{
	return e;
}
lista* lista::get_urm()
{
	return urm;
}
