#include<stdio.h>
#include<stdlib.h>
#define N 20 

typedef struct node{
    int info;
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

void saisie(int n){
    for(int i =1; i<=n;i++){
        enfants[i] = NULL;
    } 
    for(int i =1; i<=n;i++){
        int ne;
        printf("saisir le nb d'enfants de %d\n",i);
        scanf("%d",&ne);
        for(int k = 1; k<=ne;k++){
            int x;
            printf("saisie enfant %d de %d",k,i);
            scanf("%d",&x);
            Link tmp = createnode(x);
            tmp->next = enfants[i];
            enfants[i]= tmp;
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


int main(){
    int n=11;
    saisie(11);
    affichage (11);
   
    return 0 ;
}