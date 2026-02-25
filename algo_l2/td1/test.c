#include<stdio.h>
#include<stdlib.h>

#define N 20
int n, feuilles[N], papa[N];

// EXO 3 TD1

void saisie(int n){
    for(int i = 1;i <= n; i++){
        printf("entrez le papa de %d, \n",i);
        scanf("%d",&papa[i]);
    }
    //affichage
    for(int i=1; i<= n;i++){
        printf("le papa de %d est %d\n ", i,papa[i]);
    }
}

void nb_feuilles(int n){
    int nf = 0;
    for(int i = 1; i<= n; i++){
        // tester si i feuille
        int est_feuille = 1, j = 1;
        while(j<= n && est_feuille != 0){
            if(papa[j] == i){
                est_feuille = 0;
            }
            j++;
        }
        if(est_feuille){
            feuilles[++nf] = i;
        }
    }
    printf("les feuilles sont \n");
    for(int k = 1; k<= nf; k++){
        printf("%d, ",feuilles[k]);
    }
    printf("\n");
}

int monter(int f){
    int a = 0;
    while(f != 1){
        f =  papa[f];
        a++;
    }
    return a;
}

int hauteur(int nf){
    int h = 0,tmp;
    for(int i = 1; i<= nf; i++){
        tmp = monter(feuilles[i]);
        if(tmp>h){
            h = tmp;
        }
    }
    return h;
}
// ---------------------------EXO 4 TD1----------------------------

typedef struct node{
    int info;
    struct node *next;
}node;

typedef node* Link;
Link enfants[N];

Link create_node(int info){
    Link tmp = malloc(sizeof(node));
    tmp->info = info;
    tmp->next = NULL;
    return tmp;
}

void saisie_arbre(int n){
    for(int i = 1; i<= n; i++){
        enfants[i] = NULL;
        int ne;
        printf("entrez nombre d'enfants de %d\n",i);
        scanf("%d",&ne);
        for(int j = 1; j<= ne; j++){
            int e;
            printf("entrez l'enfant %d\n",j);
            scanf("%d",&e);
            Link t = create_node(e);
            t->next = enfants[i];
            enfants[i] = t;
        }
    }
}

void affichage(int n){
    for(int i = 1; i<= n; i++){
        Link t = enfants[i];
        if(t==NULL){
            printf("pas d'enfant pour %d \n",i);
        }
        for(; t != NULL; t= t->next){
            printf("%d\t", t->info);
        }
        printf("\n");
    }
}


int main(){

    saisie_arbre(11);
    affichage(11);
    return 0;

}