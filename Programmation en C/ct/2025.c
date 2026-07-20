#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//EXERCICE 1
//1 le programme fait un trianble rectangle de valeurs de j qui s'incrémente 
// a chaque ligne (effet escalier )

//0
//0 1
//0 1 2
//0 1 2 3
/*

//2)
int main(){
    int a,b;
    printf("entrez a et b \n");
    scanf("%d %d",&a, &b);
    if(a>b){
        printf("le resultat est positif\n");
    }
    else if(a<b){
        printf("le resultat est negatif \n");
    }
    else{
        printf("le resultat est nul \n");
    }
    return 0;
}
*/
// EXERCICE 2
//1)
/*
int jeu(){
    int mise;
    printf("entrez vote mise :\n");
    scanf("%d",&mise);
    int secteur = rand() % 8 + 1;
    if(secteur == 1){
        mise = mise * 2;
        return mise;
    }
    else{
        //printf("secteur %d rouge appuyez sur CTRL D pour relancer ... \n",secteur);
        //scanf("\n");
        secteur = rand() % 8 + 1;
        if(secteur <5){
            mise += 6;
            return mise;
        }
        else{
            mise = 0;
        }
    }
    return mise;
}

//2)
float gain_moyen(int n){
    float moy;
    int somme = 0;
    int g;
    int i=0;

    //
    while(i<n){
        g = jeu();
        somme += g;
        i++;
    }
    //
    for(i = 0; i<n;i++){
        g = jeu();
        somme += g;
    }

    moy = (float)somme/(float)n;
    return moy;
}


int main(){
    srand(time(NULL));
    int n, mise, game;
    printf("entrez le nombre de parties :\n");
    scanf("%d",&n);
    printf("entrez votre mise :\n");
    scanf("%d",&mise);
    for(int i = 0; i<n;i++){
        game = jeu();
        printf("gain = %d e \n",game);
    }
    return 0;
}
*/ 

// EXERCICE 3

//1)


//EXERCICE 4
/*
//1)
int zoo_zoo_land(int n){
    int valeur = 0;
    int k = 0;
    int *t = malloc(n*sizeof(int));
    for(int i = 0; i<n;i++){
        t[i] = 0;
    }
    int i = 0;
    while(i<n){
        valeur = rand() % 9 + 1;
        printf("valeur rand = %d \n",valeur);
        if(i == 0 || valeur > t[k-1]){
            t[k] = valeur;
            k++;
        }
        else{
            t[k-1] = valeur;
        }
        i++;
    }
    for(int i = 0; i<n;i++){
        printf("%d ",t[i]);
    }
    free(t);
    return k;
}
void afficher(int *t,int n){
    for(int i = 0; i<n;i++){
        printf("%d ",t[i]);
    }
}

int main(){
    srand(time(NULL));
    int indice = zoo_zoo_land(10);
    printf("l'indice max calcule est %d \n",indice);
    return 0;
}
*/

// EXERCICE 5)
/*
//1)

int prefixe(int *t1, int n1, int *t2, int n2){
    if(n1>n2){
        return 0;
    }
    for(int i = 0; i<n1;i++){
        if(t1[i] != t2[i]){
            return 0;
        }
    }
    return 1;
}
*/


// EXERCICE 6
//1°


// EXERCICE 7
//1°

struct list{
    int i;
    struct list *succ;
};

void ajouter(int n, struct list **L){
    struct list *N = NULL;
    N =  malloc(sizeof(struct list));
    N->i = n;
    N->succ = NULL;
    struct list *T = *L;
    
    while(T!= NULL && T->succ!= NULL){
        T = T->succ;
    }
    if(*L != NULL){
        T->succ = N;
    }
    else{
        *L = N;
    }
}


void afficher(struct list *L){
    struct list *T = L;
    while(T != NULL){
        printf("%d > ",T->i);
        T = T->succ;
    }
    printf("NULL\n");
}

void detruire(struct list **L){
    if(L != NULL){
        struct list *N = NULL;
        struct list *T = *L;
        while(T != NULL){
            N = T->succ;
            free(T);
            T = N;
        }
    }
}

int main(){
    struct list *L = NULL;
    ajouter(5, &L);
    ajouter(5,&L);
    ajouter(9,&L);
    afficher(L);

    return 0;
}