#include "Coada.hpp"
#include <iostream>
#include <fstream>
Coada* Coada::initializare_coada()
{
	Coada *q;
	q=new Coada;
	q->front=NULL;
	q->rear=NULL;
	return q;
}
void Coada::populeaza_coada(Coada *&q,lista *cap_lista)
{
	lista *p;
	for(p=cap_lista;p!=NULL;p=p->get_urm()->get_urm())
	{
		Meci *m;
		m=new Meci;
		m->set_echipa1(p->get_echipa());
		m->set_echipa2(p->get_urm()->get_echipa());
		m->set_urm(NULL);
		if(q->rear==NULL)
			q->rear=m;
			else
				{
					(q->rear)->set_urm(m);
					q->rear=m;
				}
		if(q->front==NULL)
			q->front=q->rear;
	}
}
void Coada::afiseaza_coada(ostream &ofis,int x)
{
	Meci *m;
	int i=1;
	ofis<<"--- ROUND NO:"<<x<<endl;
	for(m=front;m!=NULL;m=m->get_urm())
	{
		ofis<<m->get_echipa1().get_nume_echipa();
		for(int j=0;j<33-(m->get_echipa1().get_nume_echipa().length());j++)
			ofis<<" ";
		ofis<<"-";
		for(int j=0;j<33-(m->get_echipa2().get_nume_echipa().length());j++)
			ofis<<" ";
		ofis<<m->get_echipa2().get_nume_echipa();
		ofis<<endl;
	}
}
Meci* Coada::get_front()
{
	return front;
}
Meci* Coada::get_rear()
{
	return rear;
}
void creare_stiva(invingatori *&top1,pierzatori *&top2,Coada *q)
{
	Meci *m;
	top1=NULL;
	for(m=q->front;m!=NULL;m=m->get_urm())
	{
		float aux=0;
		if(m->get_echipa1().get_points_echipa()>m->get_echipa2().get_points_echipa())
		{
			m->get_echipa1().set_points_echipa(m->get_echipa1().get_points_echipa()+1);
			int nr;
			nr=m->get_echipa1().get_nr_playeri();
			for(int i=0;i<nr;i++)
				m->get_echipa1().get_player()[i].set_points(m->get_echipa1().get_player()[i].get_points()+1);
			adauga_invingator(top1,m->get_echipa1());
			adauga_pierzator(top2,m->get_echipa2());
		}
		else
		{
			m->get_echipa2().set_points_echipa(m->get_echipa2().get_points_echipa()+1);
			int nr;
			nr=m->get_echipa2().get_nr_playeri();
			for(int i=0;i<nr;i++)
				m->get_echipa2().get_player()[i].set_points(m->get_echipa2().get_player()[i].get_points()+1);
			adauga_invingator(top1,m->get_echipa2());
			adauga_pierzator(top2,m->get_echipa1());	
		}
		
	}
}
int nr_meciuri_coada(Coada *q)
{
	int nr=0;
	Meci *m;
	Meci *aux=q->front;
	if(aux->get_urm()==NULL)
        return 1;
    else
        for(m=q->front;m!=NULL;m=m->get_urm())
            nr++;
	return nr;
}
void Coada::stergere_coada(Coada *&q)
{
	Meci *aux;
	while(q->front!=NULL)
	{
		aux=q->front;
		q->front=q->front->get_urm();
		delete aux;
	}

}
void Coada::repopuleaza_coada(Coada *&q,invingatori *top)
{
	invingatori *i;

	if(top->get_urm()->get_urm()==NULL)
        {Meci *m;
        m=new Meci;
		m->set_echipa1(top->get_echipa());
		m->set_echipa2(top->get_urm()->get_echipa());
		m->set_urm(NULL);}
	for(i=top;i!=NULL;i=i->get_urm()->get_urm())
	{
		Meci *m;
		m=new Meci;
		m->set_echipa1(i->get_echipa());
		m->set_echipa2(i->get_urm()->get_echipa());
		m->set_urm(NULL);
		if(q->rear==NULL)
			q->rear=m;
			else
				{
					(q->rear)->set_urm(m);
					q->rear=m;
				}
		if(q->front==NULL)
			q->front=q->rear;
	}

}
