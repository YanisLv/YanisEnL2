// ECRIRE UNE FONCTION PERMETTANT D'AFFCIHER LES NOEUDS D'UN ARBRE BINAIRE DANS L'ORDRE BFS
#include<stdio.h>
#include<stdlib.h>
#define N 20    // la taille max du TAB


typedef struct node{
    int info;
    struct node *g, *d;
} node;

typedef struct node* link;

link Q[N];      // queue
int head, tas, tail;

// commandes d'une file : put, get, init, full

// 🛑🛑 FILE PLEINE <-> le nbr d'elts = N - 1
// si nbr d'elts = N. On ne peut pas distinguer. File pleine et vide  POURQUOI
// initialisaation de file

void init(){
    head = 0;
    tail = N - 1;
}

int full(){
    return ((tail + 2) % N == head);
}

//FILE VIDE

int empty(){
    return (head == (tail + 1) % N);
}


link create_gd(int x){
    // creer un noeud avec x pour info et g = d = NULL
    link temp = (link)malloc(sizeof(node));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}

// ENFILER 
void put(link p){
    if(full()){
        printf("stp allouer plus d'espace \n");
        exit(1);    // emergency exit
    }
    tail = (tail + 1) % N;
    Q[tail] = p;
}


// DEFILER

link get(){
    if(empty()){
        printf("file vide \n");
        exit(1);
    }
    link p = Q[head];
    head = (head +  1) % N;
    return p;
}

// BFS
void bfs(link root){
    // IMPRIMER LES NOEUDS DE A
    // DANS L'ORDRE BFS
    if(root == NULL){
        return;
    }
    init();
    put(root);
    while(!empty()){
        link root = get();
        printf("%d ",root->info);
        // ENFILER l'ENFANT GAUCHE
        // L'enfant droit si != 0
        if(root->g != NULL){
            put(root->g);
        }
        if(root->d != NULL){
            put(root->d);
        }
    }
}


int main() {
    link root = create_gd(1);
    root->g = create_gd(3);
    root->d = create_gd(2);
    root->g->g = create_gd(7);
    root->g->g->d = create_gd(8);
    root->d->d = create_gd(1);
    root->d->d->d = create_gd(6);
    root->d->d->g = create_gd(5);

    bfs(root);

    return 0;
}