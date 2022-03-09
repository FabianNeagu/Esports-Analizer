#include "StivaInvingatori.hpp"
class pierzatori
{
	Echipa e;
	pierzatori *urm;
	public:
		friend void adauga_pierzator(pierzatori *&,Echipa );
		pierzatori* get_urm();
		Echipa get_echipa();
		friend void stergere_pierzatori(pierzatori *&);
};

