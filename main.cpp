#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include "AVL.hpp" 
using namespace std;
void afisare_lista(lista *,ostream &);
void eliminare_toate(lista *&);
void eliminare_element(lista *&);

int main(int argc,char** argv)
{
	string infile=argv[2];
    string outfile=argv[3];
    string checkerFile=argv[1];
    ifstream fisier_in(infile.c_str());
    ifstream checker_in(checkerFile.c_str());
    ofstream fisier_out(outfile.c_str());
    int v[5];
    for(int i=0;i<5;i++)
    {
    	checker_in>>v[i];
	}
	lista *l;
	int aux;
	int n;
	if(!fisier_in)
 		cout<<"Eroare la deschiderea fisierului!";
 	fisier_in>>n;
	int x=1;
	l=l->lista_init(fisier_in,n);
	if(v[0]==1)
		{
		afisare_lista(l,fisier_out);
		fisier_out<<endl;
		}
	if(n!=64&&n!=256)
		eliminare_toate(l,n);
	if(v[1]==1)
	{	
		fisier_out.close();
		ofstream fisier_out(outfile.c_str(),ios::out);
		afisare_lista(l,fisier_out);
		fisier_out<<endl;
	}
	Coada *q;
	invingatori *top1=NULL;
	pierzatori *top2=NULL;
	q=q->initializare_coada();
	q->populeaza_coada(q,l);
	Echipa e;
	BST b;
	BST *root1=NULL; 
	AVL *root2=NULL;
	if(v[2]==1)
	{	
		ofstream fisier_out(outfile.c_str(),ios::app);
		fisier_out<<endl;
		while(nr_meciuri_coada(q)>=2)
    	{	
        	aux=nr_meciuri_coada(q);
        	creare_stiva(top1,top2,q);
        	if(nr_meciuri_coada(q)==8)
        	{
            	creare_arbore_BST(b,root1,top1);
           		creare_arbore_AVL(root2,top1);
        	}
        	q->afiseaza_coada(fisier_out,x);
        	fisier_out<<endl;
        	afisare_invingatori(top1,fisier_out,x);
        	fisier_out<<endl;
        	stergere_pierzatori(top2);
        	q->stergere_coada(q);
        	if(aux>1)
            	q->repopuleaza_coada(q,top1);
        	stergere_invingatori(top1);
       		x++;
		}
    	aux=nr_meciuri_coada(q);
    	creare_stiva(top1,top2,q);
   		q->afiseaza_coada(fisier_out,x);
    	fisier_out<<endl;
    	afisare_invingatori(top1,fisier_out,x);
    	fisier_out<<endl;
	}
	if(v[3]==1)
	{
		ofstream fisier_out(outfile.c_str(),ios::app);
		fisier_out<<endl;
		fisier_out<<"TOP 8 TEAMS:"<<endl;
		afisare_arbore_BST(root1,fisier_out);
	}
	if(v[4]==1)
    {
    	ofstream fisier_out(outfile.c_str(),ios::app);
		fisier_out<<endl<<"THE LEVEL 2 TEAMS ARE: "<<endl;
    	afisare_arbore_AVL(root2,fisier_out,2);
	}
	l->stergere_lista(l);
	q->stergere_coada(q);
	stergere_invingatori(top1);
	stergere_pierzatori(top2);
	stergere_arbore_BST(root1);
	stergere_arbore_AVL(root2);
	return 0;
}
