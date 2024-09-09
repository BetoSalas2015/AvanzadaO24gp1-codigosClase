#include <malloc.h>
#include <stdio.h>

struct Node
{
	int info;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
};

typedef struct Node nodo;

nodo *makeTree(int dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	nuevo -> parent = NULL;
	nuevo -> left = NULL;
	nuevo -> right = NULL;
	nuevo -> info = dato;
	return nuevo;
}

int info( nodo *p )
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
 	printf("%d\n", raiz->info);   //  Visita la raiz
 	orden(raiz->left);				// Recorre recursivamentew el arbol izquierdo
 	orden(raiz->right);				// Recorre recursivamente el arbol derecho
 }
 
 void preorden(nodo *raiz) 
 {
  	if(raiz == NULL)
 		return;
 	preorden(raiz->left);				// Recorre recursivamentew el arbol izquierdo
 	printf("%d\n", raiz->info);   //  Visita la raiz
 	preorden(raiz->right);				// Recorre recursivamente el arbol derecho	
 }
 
 void postorden(nodo *raiz)
  {
  	if(raiz == NULL)
 		return;
 	postorden(raiz->left);				// Recorre recursivamentew el arbol izquierdo
 	postorden(raiz->right);				// Recorre recursivamente el arbol derecho	
	printf("%d\n", raiz->info);   //  Visita la raiz
 }
 
 void printNodo(nodo *p)
 {
 	printf("%d \n", info(p) );
 }
 