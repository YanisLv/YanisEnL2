#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 23
//algo : n = le nombre de noeuds : creer un noeud affecter 1 er entier n au champs info de ce noeud 
//construire un arbre à gauche de ce noeuds dont le nombre de noeuds ng = n/2 (d'une maniére recursive)
//construire un arbre à droite de ce noeuds dont le nombre de noeuds nd = n-ng-1 (d'une maniére non recursive) 

typedef struct node{
    int info;
    struct node *g;
    struct node *d;
}node;

typedef node* Link;

Link createnode(int x){
    Link p = (Link)malloc(sizeof(node));
    p->info = x;
    p->d = NULL;
    p->g = NULL;
    return p;
}

Link arbre(int n){
    if(n==0){
        return NULL;
    }
    int ng = n/2;
    int nd = n-ng -1;

    int x;
    printf("entrez x\n");
    scanf("%d",&x);
    Link t = createnode(x);
    t->g = arbre(ng);
    t->d = arbre(nd);
    return t;

}