#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//1)
struct lc{
    int val;
    struct lc *next;
};

//2)

struct lc *insert_tete(struct lc *L, int val){
    struct lc *N = malloc(sizeof(struct lc));
    if(!N) return L;
    N->val = val;
    N->next = L;
    return N;
}

struct lc *insert_queue(struct lc *L, int val){
    struct lc *N = malloc(sizeof(struct lc));
    struct lc *T = L;
    N->next = NULL;
    N->val = val;
    while(T != NULL && T->next != NULL){
        T = T->next;
    }
    if(L != NULL){
        T->next = N;
        return L;
    }
    return N;
}

//3)
struct lc *insert_elem(struct lc *L, struct lc *T, int val) {
    struct lc *N = malloc(sizeof(struct lc));
    if (!N) return L;  // sécurité

    N->val = val;

    // Cas 1 : insertion en tête
    if (L == T) {
        N->next = L;
        return N;
    }

    // Cas 2 : chercher le précédent
    struct lc *P = L;
    while (P != NULL && P->next != T) {
        P = P->next;
    }

    // Cas 3 : T n'est pas dans la liste
    if (P == NULL) {
        // À toi de décider quoi faire : ici je n'insère pas.
        free(N);
        return L;
    }

    // Cas 4 : insertion normale
    N->next = T;
    P->next = N;
    return L;
}


void afficher(struct lc *L){
    struct lc *T = L;
    while(T != NULL){
        printf("%d > ",T->val);
        T = T->next;
    }
    printf("NULL\n");
}

struct lc* suppimer(struct lc *L, struct lc *N){
    struct lc *T = L;
    while(T!= NULL && T->next != N){
        T = T->next;
    }
    if(T!= NULL && L != NULL){
        T->next = N->next;
        free(N);
    }
    return L;
}
int main(){

    struct lc *L = NULL, *M;
    L = insert_tete(L,12);
    L = insert_queue(L,213);
    M = insert_queue(L,25);
    L = insert_elem(L,M,5);
    afficher(L);
    struct lc *n = L->next;
    L = suppimer(L,n);
    afficher(L);
    return 0;
}