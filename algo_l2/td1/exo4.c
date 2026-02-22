#include <stdio.h>
#include<stdlib.h>
//definition de structure des noeuds 
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
Link enfants[N];//tableau de pointeurs vers le noeud 
//saisie de l'arbre sous la forme de liste chainee des enfants sous chaque noeud .
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
void affichage(int n){
    for (int i=1; i<=n; i++){
        //affichage de chaque enfants de i
        Link t=enfants[i];
        if (t==NULL){
            printf("pas d'enfants de %d",i);
        }
        else{
            //parcourir la list de l'enfants[i] en imprimant le contenu de l'info
            for( ; t!=NULL; t=t->next){
                printf("%d\t", t->info);
            printf("\t");
            }
        }
        printf("\n");
    }
}
void prefixe(int i){
    printf("%d  ",i);
    Link t=enfants[i];
    for ( ; t!=NULL;t=t->next){
        prefixe(t->info);
    }
}
void postfixe(int i){
    Link t= enfants[i];
    for( ; t!=NULL; t=t->next){
        postfixe(t->info);
    }
    printf("%d\t",i);
}

void infixe (int i){
    Link t= enfants[i];
    if (t!=NULL){
        infixe(t->info);
        t=t->next;
    }
    printf("%d\t",i);
    while (t!=NULL){
        infixe(t->info);
        t=t->next;
    }
}
int main(){
    int n=11;
    saisie(11);
    affichage (11);
    prefixe(1);
    printf("\n");
    postfixe(1);
    printf("\n");
    infixe(1);
    printf("\n");
    return 0 ;
}