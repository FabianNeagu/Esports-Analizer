#include "AVL.hpp"
#include <iostream>

int AVL::max(int a,int b)
{
	return (a > b)? a : b;
}
int AVL::Height(AVL *root)  
{  
    if(root==NULL)  
        return 0;  
    return root->height;  
}  
AVL* AVL::newNode(Echipa ech) 
{  
    AVL* node = new AVL(); 
    node->e=ech;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return(node);  
} 
AVL *AVL::Right_Rotation(AVL *y)  
{  
    AVL *x=y->left;  
    AVL *T2=x->right;   
    x->right = y;  
    y->left = T2;  
  
    y->height = max(Height(y->left),Height(y->right)) + 1;  
    x->height = max(Height(x->left),Height(x->right)) + 1;  
    return x;  
} 
AVL *AVL::Left_Rotation(AVL *x)  
{  
    AVL *y = x->right;  
    AVL *T2 = y->left;  
    y->left = x;  
    x->right = T2;   
    x->height = max(Height(x->left),Height(x->right)) + 1;  
    y->height = max(Height(y->left),Height(y->right)) + 1;  
    return y;  
}  
int AVL::getBalance(AVL *root)  
{  
    if (root == NULL)  
        return 0;  
    return Height(root->left) - Height(root->right);  
}  
AVL *AVL::insert(AVL* node,Echipa ech)  
{  
    if (node == NULL)  
        return(newNode(ech)); 
		 
    if (ech.get_points_echipa() > node->get_echipa().get_points_echipa())  
        node->right = insert(node->right, ech);  
        
    if (ech.get_points_echipa() < node->get_echipa().get_points_echipa())  
        node->left = insert(node->left, ech);
        
	if((ech.get_points_echipa())==(node->get_echipa().get_points_echipa()))
	{
		if(ech.get_nume_echipa()<node->get_echipa().get_nume_echipa())
			node->left=insert(node->left,ech);
		if(ech.get_nume_echipa()>node->get_echipa().get_nume_echipa())
			node->right=insert(node->right,ech);
	}
  
    node->height = 1 + max(Height(node->left),Height(node->right));  
  
    int balance = getBalance(node);  

    if (balance > 1 && ech.get_points_echipa() < node->left->get_echipa().get_points_echipa())  
        return Right_Rotation(node);  
        
    if (balance > 1 && ech.get_points_echipa() > node->left->get_echipa().get_points_echipa())  
    {  
       node->left = Left_Rotation(node->left);  
        return Right_Rotation(node);  
    }  
   
  
    if (balance < -1 && ech.get_points_echipa() > node->right->get_echipa().get_points_echipa())  
       return Left_Rotation(node);  
    
   
    if (balance < -1 && ech.get_points_echipa() < node->right->get_echipa().get_points_echipa())  
    {  
        node->right = Right_Rotation(node->right);  
        return Left_Rotation(node);  
    }  

    return node;  
}  
Echipa AVL::get_echipa()
{
	return e;
}
void creare_arbore_AVL(AVL *&root2,invingatori *top1)
{
	invingatori *i;
	for(i=top1;i!=NULL;i=i->get_urm())
    	{	
    		root2=root2->insert(root2,i->get_echipa());
		}

}
void afisare_arbore_AVL(AVL *root,ostream &ofis,int level)  
{  
    if(root==NULL)
		return;
	if(level==1)
   		 ofis<<root->e.get_nume_echipa()<<endl; 
   	else if(level>1)
    {  
        afisare_arbore_AVL(root->right,ofis,level-1);  
        afisare_arbore_AVL(root->left,ofis,level-1);  
    }
}  
void afisare_arbore_AVL(AVL *root,ostream &ofis)  
{  
    if(root==NULL)
		return;
	afisare_arbore_AVL(root->left,ofis); 
    ofis<<root->e.get_nume_echipa()<<endl;
    afisare_arbore_AVL(root->right,ofis);
}
void stergere_arbore_AVL(AVL *&root)
{
	if(root==NULL)
		return;
	stergere_arbore_AVL(root->right);
	stergere_arbore_AVL(root->left);
	delete root;
}
