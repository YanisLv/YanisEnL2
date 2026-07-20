#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//--------- EXERCICE 2

//1) AUTRE METHODE OBLIGEEEE 🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑
/*
int main(){
    int n = 4;
    int k = n-1;
    printf("[");
    for(int i = 1; i<n*2;i++){
        if(i <=n){
            printf("%c",'0'+i);
        }
        else{
            printf("%c",'0'+k);
            k--;
        }
    }
    printf("]\n");
    return 0;
}
*/

//2)
/*
int main(){
    int n = 4, tmp;
    for(int i = 1; i<n+1;i++){
        printf("[");
        tmp = i;
        for(int j = 1; j<(i*2);j++){
            if(j<i){
                printf("%d",j);
            }
            else{
                printf("%d",tmp);
                tmp = tmp -1;
            }
        }
        printf("]");
    }

    return 0;
}


*/

// ---------------- EXERCICE 3 -------

//1)

float scalaire(float *u, float *v, int n){
    float res = 0.;
    for(int i = 0; i<n;i++){
        res += u[i] * v[i];
    }
    return res;
}
/*

int main(){
    srand(time(NULL));
    int n;
    printf("entrez n : \n");
    scanf("%d",&n);
    float u[n], v[n];
    for(int i = 0; i<20;i++){
        u[i] = (float)(rand()% 10);
        v[i] = (float)(rand()% 10);
    }
    float ps = scalaire(u,v,n);
    printf("le resultat du produit scalaire de u et v est %.2f",ps);
    return 0;
}


*/

//------------------ EXERCICE 4--------------


//------------------ EXERCICE 5--------------

// La fonction reçoit bien le pointeur en copie, l'alloue, la modifie mais ne fait aucun
// changement dans celui du main. Il l'a modifié que ce pointeur locale a la fonction
// celui du main vaut toujours NULL.
// il aurait fallu utiliser un pointeur de pointeur.
/*
void allouer(int **T, int n){
    int i;
    *T = malloc(sizeof(int));
    for(int i = 0; i<n;i++){
        (*T)[i] = 0;
    }
}

int main(){
    int *T = NULL;
    allouer(&T,17);
    for(int i = 0; i < 17; i++)
        printf("%d ", T[i]);
    printf("\n");
    free(T);

}
*/

// Il aurait fallu ici aussi utlisé un pointeur de pointeur car on cherche de base à 
// modifier une structure fonction void donc l'utilisation d'un pointeur est la plus pertinente
// pour pouvoir modifier la structure pointée au main et pas juste localement
// ensuite la structure contient elle même un pointeur d'entier donc pour modifier les valeurs
//de *T il faut procéder de même car en modifiant T dans la fonction on va avoir une perte
// de la memoire car T n'est pas bien pointée;

// ------------- Exercice 7. Tri à bulle sur une liste doublement chaînée


//1)

struct list{
    int n;
    struct list *next;
    struct list *prec;
};



//2)
/*
int longueur(struct list *L){
    int i = 0;
    struct list *T = L;
    
    while(T != NULL){
        T = T->next;
        i++;
    }
    
    return i;
}


//3)

struct list *element(struct list *L, int i){
    int trouve = 0;
    if(longueur(L)<i){
        return NULL;
    }
    if(i == 0){
        return L;
    }
    int k = 0;
    struct list *T = L;
    while(k<i && T != NULL µµ*&& T->next != NULL*µµ){
        k++;
        T = T->next;
    }
    return T;
}

//4)

int echanger(struct list *L, int i){
    struct list *elem = element(L, i);
    if(elem == NULL || elem->next == NULL){
        return 0;
    }
    struct list *N = malloc(sizeof(struct list));
    struct list *T = L;
    while(T!=NULL && T->next != elem){
        T = T->next;
    }
    T = T->next;

    N = T->next;
    N = T;
    T = N;
    return 1;
}

void afficher(struct list *L){
    struct list *T = L;
    while(T != NULL){
        printf("%d ", T->n);
        T = T->next;
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct list *L1, *L2, *L3, *L4, *L5, *L6;

    
    L1 = malloc(sizeof(struct list));
    L2 = malloc(sizeof(struct list));
    L3 = malloc(sizeof(struct list));
    L4 = malloc(sizeof(struct list));
    L5 = malloc(sizeof(struct list));
    L6 = malloc(sizeof(struct list));
    L1->n = 10;
    L2->n = 20;
    L3->n = 40;
    L4->n = 50;
    L5->n = 60;
    L6->n = 70;

    L1->prec = NULL;
    L1->next = L2;

    L2->prec = L1;
    L2->next = L3;

    L3->prec = L2;
    L3->next = L4;
    
    L4->prec = L3;
    L4->next = L5;

    L5->prec = L4;
    L5->next = L6;

    L6->prec = L5;
    L6->next = NULL;


    struct list *p = L1;
    afficher(p);
    printf("%d\n", longueur(p));
    echanger(p, 3);
    afficher(p);
    
    free(L3);
    free(L2);
    free(L1);

    return 0;
}
*/


///------------------ EXERCICE 8-------------------



int sous_tableau(int *a, int *b, int n, int p){
    int i = 0, j = 0, cpt = 0, k = 0;

    for(i = 0; i<n; i++){
        k = 0;
        //j = 0;
        while(j<n && a[i] == b[j]){
            k ++;
            j
        }
    }
}
