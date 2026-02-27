#include<stdio.h>
#include<stdlib.h>

// structure d'un noeud
typedef struct node{
    int info;
    struct node *next;
    struct node *g;
    struct node *d
}node;
typedef node* Link;

typedef struct node* Link{
    lien creerNoeud(int valeur);
    // creer un noeud et stocket valeur et initialiser g = d = NULL
    lien nouveauNoeud = (lien)malloc(sizeof(node));

    nouveauNoeud->info = valeur;
    nouveauNoeud->g = NULL;
    nouveauNoeud->d = NULL;
    return nouveauNoeud;
}

lien insertion(lien p, int x){
    // insérer l'entier x dans l'arbre BST pointé par p
    // BASE de la récurrence
    if(p==NULL){
        return creerNoeud(x);
    }
    if(x<p->info){  //aller vers la gauche
        //inserer x a gauche
        p->g = insertion(p->g,x);
    }
    else if(x>p->info){    //aller vers la droite
        // insérer x a droite
        p->d = insertion(p->d,x);
    }
    return p;   // on n'insere pas les entiers égaux
    
}


//copier et coller
// print Tree
int main(){
    int x;
    lien racine= NULL;
    while(scanf("%d",&x) != EOF){
        racine = insertion(racine,x);
    }
    printTree(racine,0);
    return 0;
}