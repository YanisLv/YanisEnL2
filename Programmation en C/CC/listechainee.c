#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//1)
struct liste_chainee{
    int valeur;
    struct liste_chainee *next;
};

//2)

//--- INSERTION EN TETE
struct liste_chainee *insert_tete(struct liste_chainee *liste, int n){
    struct liste_chainee *new = NULL;
    new = (struct liste_chainee*)malloc(sizeof(struct liste_chainee));
    new->valeur = n;
    new->next = liste;
    return new;
}

// --- INSERTION EN QUEUE

struct liste_chainee *insert_queue(struct liste_chainee *liste, int n){
    struct liste_chainee *new = NULL, *T = liste;
    new = (struct liste_chainee*)malloc(sizeof(struct liste_chainee));
    new->valeur = n;
    new->next = NULL;
    while(T!= NULL && T->next != NULL){
        T = T->next;
    }
    if(liste!= NULL){
        new->next = T->next;
        T->next = new;
        return liste;
    }
    else{
        return new;
    }
    
}

//---INSERTION AVANT UN ELEMENT IDENTIFIE PAR UN POINTEUR SUR UNE CELLULE

struct liste_chainee *insert_elem(struct liste_chainee *liste, struct liste_chainee *T,int n){
    struct liste_chainee *new = NULL, *P = liste;
    new = (struct liste_chainee*)malloc(sizeof(struct liste_chainee));
    new->valeur = n;
    new->next = NULL;

    if(liste == NULL){
        return new;
    }
    if(liste == T){
        return insert_tete(liste,n);
    }
    while(P->next != T){
        P= P->next;
    }
    P->next = new;
    new->next = T;
    return liste;

}// A REVOIRRRRRRRRRRRRR !!!!!!!!!!!!!

//3)

void afficher(struct liste_chainee *liste){
    struct liste_chainee *T = liste;
    while(T!= NULL){
        printf("%d > ",T->valeur);
        T = T->next;
    }
    //printf("NULL \n");
}

//4)
int nb_elem(struct liste_chainee *liste){
    struct liste_chainee *T = liste;
    int nb = 0;
    while(T != NULL){
        nb ++;
        T = T->next;
    }
    return nb;
}

//5)
struct liste_chainee *supprimer_elem(struct liste_chainee *liste, struct liste_chainee *T){
    struct liste_chainee *P = liste;
    
    while(P != NULL && P->next != T){
        P = P->next;
    }

    if(P->next != T){
        return NULL;
    }
    P->next = T->next;
    free(P->next);
}

int main(){

    struct liste_chainee *test = NULL;
    test = insert_tete(test,90);
    test = insert_tete(test,40);
    test = insert_tete(test,213);
    struct liste_chainee *d = test->next;
    afficher(test);
    printf("\n");
    supprimer_elem(test,d);
    afficher(test);
    printf("\n");

    printf("il y a %d elements dans la liste chainee \n",nb_elem(test));
    return 0;
}