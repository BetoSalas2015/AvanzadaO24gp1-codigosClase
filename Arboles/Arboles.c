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





