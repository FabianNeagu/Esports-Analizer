#include "BST.hpp"
#include <iostream>

BST::BST()
{
	left=NULL;
	right=NULL;
}
BST::BST(Echipa ech)
{
	e=ech;
	left=NULL;
	right=NULL;
}
Echipa BST::get_echipa()
{
	return e;
}
void BST::set_echipa(Echipa ech)
{
	e=ech;
}
BST* BST::inserare_element(BST *root,Echipa ech)
{
	if(!root)
		return new BST(ech);
	if((ech.get_points_echipa())>(root->e.get_points_echipa()))
		root->right=inserare_element(root->right,ech);
			else if((ech.get_points_echipa())<(root->e.get_points_echipa()))
				root->left=inserare_element(root->left,ech);
					else if((ech.get_points_echipa())==(root->e.get_points_echipa()))
						{
							if(ech.get_nume_echipa()<root->e.get_nume_echipa())
								root->left=inserare_element(root->left,ech);
							if(ech.get_nume_echipa()>root->e.get_nume_echipa())
								root->right=inserare_element(root->right,ech);
						}
	return root;
}
void creare_arbore_BST(BST &b,BST *&root,invingatori *top1)
{
	invingatori *i;
    root = b.inserare_element(root,top1->get_echipa());
    for(i=top1->get_urm();i!=NULL;i=i->get_urm())
    	{	
    		b.inserare_element(root,i->get_echipa());
		}
}
void afisare_arbore_BST(BST *root,ostream &ofis)
{
	if(root==NULL)
		return;
	else
	{
		afisare_arbore_BST(root->right,ofis); 
    	ofis<<root->e.get_nume_echipa();
    	for(int j=0;j<34-(root->get_echipa().get_nume_echipa().length());j++)
			ofis<<" ";
		ofis<<"-  "<<(setprecision(2))<<fixed<<root->get_echipa().get_points_echipa();
		ofis<<endl;
   	    afisare_arbore_BST(root->left,ofis); 
	}
}
BST *BST::get_right()
{
	return right;
}
BST *BST::get_left()
{
	return left;
}
void stergere_arbore_BST(BST *&root)
{
	if(root==NULL)
		return;
	stergere_arbore_BST(root->right);
	stergere_arbore_BST(root->left);
	delete root;
}
