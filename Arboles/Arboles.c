#include <malloc.h>
#include <stdio.h>

struct Node
{
	char info;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
};

typedef struct Node nodo;

nodo *makeTree(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	nuevo -> parent = NULL;
	nuevo -> left = NULL;
	nuevo -> right = NULL;
	nuevo -> info = dato;
	return nuevo;
}

char info( nodo *p )
{
	return p -> info;
}

nodo *left(nodo *p) 
{
	return p->left;
}

nodo *right(nodo *p)
 {
 	return p->right;
 }
 
 void orden(nodo *raiz)
 {
 	if(raiz == NULL)
 		return;
 	printf("%c\n", raiz->info);   //  Visita la raiz
 	orden(raiz->left);				// Recorre recursivamentew el arbol izquierdo
 	orden(raiz->right);				// Recorre recursivamente el arbol derecho
 }
 
 void preorden(nodo *raiz) 
 {
  	if(raiz == NULL)
 		return;
 	preorden(raiz->left);				// Recorre recursivamentew el arbol izquierdo
 	printf("%c\n", raiz->info);   //  Visita la raiz
 	preorden(raiz->right);				// Recorre recursivamente el arbol derecho	
 }
 
 void postorden(nodo *raiz)
  {
  	if(raiz == NULL)
 		return;
 	postorden(raiz->left);				// Recorre recursivamentew el arbol izquierdo
 	postorden(raiz->right);				// Recorre recursivamente el arbol derecho	
	printf("%c\n", raiz->info);   //  Visita la raiz
 }
 

int main()
{
	nodo *p;
	nodo *raiz = NULL;
	
	raiz = makeTree('A');
	raiz->left = makeTree('B');	 
	raiz->right = makeTree('C');
	p = left(raiz);
	p->left = makeTree('D');
	p->right = makeTree('E');
	p = right(raiz);
	p->left = makeTree('F');
	p->right = makeTree('G');
	
	postorden(raiz);
	
	return 0;
}











