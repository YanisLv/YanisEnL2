#include <stdio.h>
#include<stdlib.h>
#define N 20 
typedef struct node_gd{
    int info;
    struct node_gd *g;
    struct node_gd *d;
}node_gd;
typedef node_gd* Link;



Link create_gd(int x){
    // creer un noeud avec x pour info et g = d = NULL
    Link temp = (Link)malloc(sizeof(node_gd));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}
Link enfants[N];//tableau de pointeurs vers le noeud 


Link lookup(Link r, int x){
    if(r == NULL || r->info == x) return r;

    if(x>r->info){
        return lookup(r->d,x);
    }
    else{
        return lookup(r->g,x);
    }
} 

//3

Link lookup_non_rec(Link r, int x){
    while(r != NULL){
        if(r->info == x){
            return r;
        }
        else{
            if(x>r->info){
                r = r->d;
            }
            else{
                r = r->g;
            }
        }
    }
    return NULL;

}