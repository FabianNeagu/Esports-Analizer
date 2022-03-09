#include "BST.hpp"
class AVL
{
	Echipa e;
	int height;
	AVL *left;
	AVL *right;
	public: 
		int max(int , int );  
		int Height(AVL *);
		AVL* newNode(Echipa );
		AVL* Right_Rotation(AVL *);
		AVL* Left_Rotation(AVL *);
		AVL* insert(AVL * ,Echipa );
		int getBalance(AVL *);
		Echipa get_echipa();
		friend void afisare_arbore_AVL(AVL* ,ostream &,int);
		friend void afisare_arbore_AVL(AVL* ,ostream &);
		friend void creare_arbore_AVL(AVL *&,invingatori *);
		friend void stergere_arbore_AVL(AVL *&);
};

