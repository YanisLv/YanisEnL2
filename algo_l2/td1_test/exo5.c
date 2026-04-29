#include<stdio.h>
#include<stdlib.h>

#define N 20 

typedef struct node{
    int info;
    struct node *g;
    struct node *d;
    struct node *next;
}node;
typedef node* Link ;


Link createnode(int info){
    Link tmp=(Link)malloc(sizeof(node));
    tmp->info=info;
    tmp->next=NULL;
    return tmp;
}
Link enfants[N];

Link insertion(Link p, int x){
    // insérer l'entier x dans l'arbre BST pointé par p
    // BASE de la récurrence
    if(p==NULL){
        return creernode(x);
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

void printTree(Link p){
    Link t = p;
    while(t!= NULL){
        printf("%d - %d \t", t->g->info, t->d->info);
        t = t->next;
    }
}


int main(){

    Link racine = NULL;
    int x;
    int i = 1;
    printf("s\n");
    while(scanf("%d",&x)!= EOF){
        printf("entrez %de nombre \n",i);
        racine = insertion(racine,x);
        i++;
    }
    //printTree(racine);
    return 0;
}