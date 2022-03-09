#include "Coada.hpp"

class BST
{
	Echipa e;
	BST *left,*right;
	public: 
		BST();
		BST(Echipa );
		Echipa get_echipa();
		void set_echipa(Echipa );
		BST *inserare_element(BST *,Echipa );
		friend void creare_arbore_BST(BST &,BST *&,invingatori *);
		friend void afisare_arbore_BST(BST *,ostream &);
		friend void stergere_arbore_BST(BST *&);
		BST* get_right();
		BST* get_left();
};

