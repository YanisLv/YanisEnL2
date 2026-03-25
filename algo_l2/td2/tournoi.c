#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *g, *d;
} node;

typedef struct node* link;

link create_gd(int x){
    // creer un noeud avec x pour info et g = d = NULL
    link temp = (link)malloc(sizeof(node));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}


link tournoi(int t[],int g, int d){
    // BUILD TOURNOI POUR T[G;;;D]
    // g = l'indice gauche, d = l'indice droit
    int m = (g+d)/ 2;    //l'indice
    link p = create_gd(m);
    if(g==d){
        return p;
    }
    p->g = tournoi(t,g,m);
    p->d = tournoi(t,m+1,d);
    int u = p->g->info, v = p->d->info;
    if(u>v){
        p->info = u;
    }
    else{
        p->info = v;
    }
    return p;

}


int main(){
    link pars
    return 0;
}