#include "StivaPierzatori.hpp"
class Coada
{
	Meci *front;
	Meci *rear;
	public:
		Coada* initializare_coada();
		void populeaza_coada(Coada *&,lista* );
		void afiseaza_coada(ostream &,int );
		Meci* get_front();
		Meci *get_rear();
		friend void creare_stiva(invingatori *&,pierzatori *&,Coada *);
		friend int nr_meciuri_coada(Coada *);
		void stergere_coada(Coada *&q);
		void repopuleaza_coada(Coada *&,invingatori *);

};

