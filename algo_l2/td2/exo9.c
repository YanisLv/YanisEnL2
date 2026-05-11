 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

// PARCOURS PRE-FIXE D'UN ARBRE BINAIRE
typedef struct node{
    int info;
    struct node *g;
    struct node *d;
}node;
typedef node* Link; // notre pile contient pointeurs vers le Node
// DEF DE PILE

Link create_gd(int x){
    // creer un noeud avec x pour info et g = d = NULL
    Link temp = (Link)malloc(sizeof(node));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}


typedef struct pile{
    Link p[N]; //tab de ptrs
    int head;
}pile;
pile *s; // s = stack
// INITIALISAITON DE PILE
pile *s1;
pile *s2;

void init(){
    s->head = -1;
}
int pile_vide(){
    return s->head == -1;
}
void push(Link t){
    // empiler t
    // tester pile plein
    if(s->head == N - 1){
        printf("manque de place dans la file");
        exit(1);
    }
    s->p[++s->head] = t;
}

Link pop(){
    //TESTER PILE VIDE
    if(s->head == -1){
        printf("pile vide \n");
        exit(1);
    }
    return s->p[s->head--];
}

void prefixe(Link root){
    // ECRIRE DANS L'ORDRE PREFIXE LES NOEUDS DE L'ARBRE POINTÉ PAR ROOT
    if(root == NULL){
        push(root);
        while(!pile_vide()){
            Link root = pop();
            printf("%d ",root->info);
            if(root->d != NULL){
                push(root->d);
            }
            if(root->g != NULL){
                push(root->g);
            }
        }
    }
}



void infixe(Link root)
{
    
    Link courant = root ;
    while(courant != NULL || !pile_vide())
    {
        while(courant != NULL)
        {
            push(courant) ;
            courant = courant -> g ;
        }
        courant = pop();
        printf("%d ",courant->info);
        courant = courant->d ;
    }  
}

void postfixe(Link root){
    // AFFICHER DANS L'ORDRE POSTFIXE
    // LES NOEUDS DE L'ARBRE BINAIRE
    // DECLARER DE 2 PILES / STACK S1/S2
    if(root == NULL){
        return;
    }
    push(&s1);
    while(!pile_vide(&s1)){
        Link courant = pop(&s1);
        push(&s2, root);
        // push l'enfant 
    }
    
}

int main(){
    s = (pile*)malloc(sizeof(pile));
    Link root = NULL ;
    init();
    root = create_gd(50);
    root -> g = create_gd(20);
    root -> d = create_gd(10);
    root -> g -> d = create_gd(5);
    root -> d -> g = create_gd(2);
    infixe(root);
    return 0;
}