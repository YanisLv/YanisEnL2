#include <stdio.h>
#include<stdlib.h>
#define N 20 

typedef struct node{
    int info;
    struct node *next;
}node;
typedef node* Link ;
//creer un nouveau noeud pour stocker info
Link createnode(int info){
    Link tmp=(Link)malloc(sizeof(node));
    tmp->info=info;
    tmp->next=NULL;
    return tmp;
}
Link enfants[N];
void saisie(int n){
    //initialisation de tableau de l'arbre de pointeurs enfants n<N=20 enfants[1]=enfants[2]=...NULL
    //pas d'enfants 
    for (int i=1; i<=n; i++){
        enfants[i]=NULL;
        //fin d'initialisation
    }
    //saisie des enfants
    for (int  i=1 ; i<=n ; i++){
        //saisie du nombre enfants de i 
        int ne; //nombre d'enfants
        printf("entrez le nombre d'enfants de %d=", i);
        scanf("%d", &ne);
        //saisie des enfants de i
        for(int j=1; j<=ne ; j++){
            //les enfants sont entrés dans l'ordre inverse
            printf("entrez les enfants %d=\n", j);
            int e ; 
            scanf("%d", &e);
            Link t ;
            t=createnode(e);
            //attache t à la tête de l'enfants [i]
            t-> next=enfants[i];
            enfants[i]=t;
        }
    }
}
void afficher(int i, int l){
    int cpt = 0;
    for(int j = 1; i<= l; j++){
        printf("===");
    }
    printf("%d\n",i);
    for(Link t = enfants[i];t != NULL; t = t->next){
        afficher(t->info,l+1);
    }
}

int main(){
    //saisie(7);
    afficher(1,0);
    return 0;
}
