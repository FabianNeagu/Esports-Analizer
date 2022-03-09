#include "Echipa.hpp"
class lista
{
	Echipa e;
	lista *urm;
	public:
		lista* lista_init(istream &,int );
		friend void afisare_lista(lista *,ostream &);
		friend void eliminare_toate(lista *&,int );
		friend void eliminare_element(lista *&);
		void stergere_lista(lista *&);
		Echipa get_echipa();
		lista* get_urm();
};

