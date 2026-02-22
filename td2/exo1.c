#include <stdio.h>
#include<stdlib.h>
// COPIER COLLER LE CODE DE EXO 4 TD1.
// SAISIR D'UN ARBRE GENERAL AVEC LISTES CHAÎNEES DE SES ENFANTS
// ECRIRE LE CODE EN C PERMETTANT D'AFFICHER LES NOEUDS L'ORDRE BFS(parcours par niveau). AFFICHER LES NOEUDS SELON LEUR NIVEAU
//EN DEDUIRE LA HAUTEUR DE L'ARBRE
// NETTOYER LA MEMOIRE


//------------------ EXO 4 TD 1 -------------------⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔// 
#define N 20 


typedef struct node{
    int info;
    struct node *suivant;
}node; // RACCOURCI

typedef node* link;
//creer un nouveau noeud pour stocker info
link createnode(int info){
    link tmp=(link)malloc(sizeof(node));
    tmp->info=info;
    tmp->suivant=NULL;
    return tmp;
}
link enfants[N];//tableau de pointeurs vers le noeud 
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
            link t ;
            t=createnode(e);
            //attache t à la tête de l'enfants [i]
            t->suivant=enfants[i];
            enfants[i]=t;
        }
    }
}
/*
void affichage(int n){
    for (int i=1; i<=n; i++){
        //affichage de chaque enfants de i
        link t=enfants[i];
        if (t==NULL){
            printf("pas d'enfants de %d",i);
        }
        else{
            //parcourir la list de l'enfants[i] en imprimant le contenu de l'info
            for( ; t!=NULL; t=t->suivant){
                printf("%d\t", t->info);
            printf("\t");
            }
        }
        printf("\n");
    }
}
*/
void prefixe(int i){
    printf("%d  ",i);
    link t=enfants[i];
    for ( ; t!=NULL;t=t->suivant){
        prefixe(t->info);
    }
}
void postfixe(int i){
    link t= enfants[i];
    for( ; t!=NULL; t=t->suivant){
        postfixe(t->info);
    }
    printf("%d\t",i);
}

void infixe (int i){
    link t= enfants[i];
    if (t!=NULL){
        infixe(t->info);
        t=t->suivant;
    }
    printf("%d\t",i);
    while (t!=NULL){
        infixe(t->info);
        t=t->suivant;
    }
}
/*
int main(){
    int n=11;
    saisie(11);
    affichage(11);
    prefixe(1);
    printf("\n");
    postfixe(1);
    printf("\n");
    infixe(1);
    printf("\n");
    return 0 ;
}
*/
//----------------- FIN EXO 4 TD  1 ⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔//


// Ecrivons les opérations d'une file


link head, tail;     // Definition de file

// intialisation 
// file = vide

void init(){
    head = NULL;
}

int file_vide(){
    return head == NULL;
}

void enfiler(int x){
    if(file_vide()){
        head = createnode(x);
        tail = head;
    }
    else{
        link t = createnode(x);
        // ATTACHER T A LA FIN DE FILE
    }
}

int defiler(){
    if(file_vide()){
        printf("RADIN D'ELEMENTS A DEFILER\n");
        exit(1);
    }
    int x = head->info;
    link t = head;
    head = head->suivant;
    free(t);
    return x;
}
int L[N]; //LEVEL
void BFS(int i){
    //i=racine de l'arbre //  
    init() ;  //initialisation de la file 
    enfiler(i);  
    L[i] = 0 ; //niveau racine =0
    while(!file_vide())
    {
        int j = defiler() ;
        //enfiler tout les enfants de j //
        for(link t =enfants[j];t!=NULL ;t=t->suivant)
        {
            enfiler(t->info) ;
            L[t->info] = L[j]+1 ;
        }
    }
}


// LA HAUTEUR DE L'ARBRE = max de TABLEAU L
int hauteur(int n){
    // initialisation
    int h = 0;
    // parcours de tab L
    for(int i = 1; i<= n; i++){
        if(h<L[i]){
            h = L[i];
        }
    }
    return h;
}


// AFFICHER LES NOEUDS SELON LEUR NIVEAU

void affichage(int n){
    int h = hauteur(n);
    for(int niveau = 0; niveau<= h;niveau++){
        //AFFICHER LES NOEUDS DE NIVEAU
        for(int i = 1; i<= n; i++){
            if(L[i] == niveau){
                printf("%d ",i);
            }
            printf("\n");
        }
    } 
}


int main(){
    int n;
    printf("entrer valeur de n\n");
    scanf("%d",&n);
    saisie(n);
    BFS(n);
    affichage(n);
    return 0;
}