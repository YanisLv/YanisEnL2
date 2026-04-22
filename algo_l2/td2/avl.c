#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *g;
    struct node *d;
    int height;
    // la hauteur du noeud

}node;
typedef node* Link; // notre pile contient pointeurs vers le Node

Link rotateRight(Link y){
    Link x = y->g;
    Link Tz = x->d;
    //Rotation
    x->d=y;
    y->g=Tz;
    //ROTATION TERMINEE
    //UPDATE LE NOEUD
}
//Ecrire une fonction pour tester si un ABR est AVL

int height(Link root){
    // ALGO : h(A) = 1 + max(h(Ag), h(Ad))
    //BASE
    if(root == NULL){
        return 0;
    }
    int hg = height(root->g);
    int hd = height(root->d);
    if(hg>hd){
        return 1+hg;
    }
    return 1+hd;
}
Link create_gd(int x){
    // creer un noeud avec x pour info et g = d = NULL
    Link temp = (Link)malloc(sizeof(node));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}

int AVL(Link root){
    // BASE Arbre vide est AVL
    if(root == NULL){
        return 1;
    }
    int hg = height(root->g);
    int hd = height(root->d);
    int diff = hg - hd;
    // TESTER SI DIFF APPARTIENT A [-1;+1]
    if(diff>= -1 && diff <= +1){
        //tester si ag , ad sont avl
        //AVL(root->g) && AVL(root->d)
        return 1;
    }
    return 0;
}

//FONCTION (Right ROTATION : left lourd (heavy))




int main(){
    Link r = create_gd(4);
    r->g = create_gd(3);
    r->d = create_gd(5);
    r->g->g = create_gd(2);
    r->g->g->g=create_gd(1);
    printf("TESTER AVL %d\n",AVL(r));
    return 0;
}