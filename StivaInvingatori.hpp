#include "Meci.hpp"
class invingatori
{
	Echipa e;
	invingatori *urm;
	public:
		friend void adauga_invingator(invingatori *&,Echipa );
		invingatori* get_urm();
		Echipa get_echipa();
		friend void stergere_invingatori(invingatori *&);
		friend void afisare_invingatori(invingatori *,ostream &,int );
};

