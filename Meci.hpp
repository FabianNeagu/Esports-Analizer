#include "Lista.hpp"
class Meci
{
	Echipa e1;
	Echipa e2;
	Meci *urm;
	public:
		void set_echipa1(Echipa );
		void set_echipa2(Echipa );
		void set_urm(Meci *);
		Echipa get_echipa1();
		Echipa get_echipa2();
		Meci* get_urm();
};

