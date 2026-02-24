#include <stdio.h>
#include<stdlib.h>
#define N 20 
typedef struct node{
    int info;
    struct node *next;
    struct node *g;
    struct node *d
}node;
typedef node* Link ;

Link lookup(Link r, int x){
    // Rechercher l'entier x dans l'arbre BST pointé par r

    if(r== NULL || r->info == x){
        return r;
    }
    if(x<r->info){      // chercher dans l'arbre gauche
        return lookup(r->g, x);
    }
    else{   // Rechercher dans l'autre arbre   
        return lookup(r->d, x);  // appel récur
    } 
}

// FAIRE FOCNTION NPON R2CURSIVE