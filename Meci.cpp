#include "Meci.hpp"

void Meci::set_echipa1(Echipa e)
{
	e1=e;
}
void Meci::set_echipa2(Echipa e)
{
	e2=e;
}
void Meci::set_urm(Meci *e)
{
	urm=e;
}
Echipa Meci::get_echipa1()
{
	return e1;
}
Echipa Meci::get_echipa2()
{
	return e2;
}
Meci* Meci::get_urm()
{
	return urm;
}

