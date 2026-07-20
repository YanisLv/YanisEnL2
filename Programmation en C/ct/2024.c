#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#include<math.h>

// exercice 1--------------
// il affiche n lignes de valeurs qui affichent pour chaque ligne les valeurs entre 0 et i
// et saute une ligne entre chaque ligne
//0
//0 1
//0 1 2
// 0 1 2 3

/*

//-------------------- EXERCICE 2--------------

int jeu(int mise){
    int gain = 0;
    printf("la roue est tournee une premiere fois ...\n");
    int secteur= rand() % 8 +1;
    if(secteur == 1){
        printf("secteur %d ! votre misee est doublee \n",secteur);
        gain = mise * 2;
        return gain;
    }
    else{
        printf("secteur %d la roue est a nouveau tournee ..\n ",secteur);
        secteur = rand() % 8 + 1;
        if(secteur <=4){
            printf("secteur %d zone rouge ! +6euros\n",secteur);
            gain = mise+ 6;
            return gain;
        }
        else{
            printf("hors zone rouge votre mise est perdue :(\n");
            return 0;
        }
    }
}
float moyen(int mise, int n){
    float somme = 0, moy = 0;
    for(int i = 0;i <n;i++){
        somme += jeu(mise);
    }
    moy = somme / n;
}

int main(){
    srand(time(NULL));
    int mise;
    int n = 6;
    printf("entrez la mise \n");
    scanf("%d",&mise);
    float gain = moyen(mise,n);
    printf("le gain moyen est %.2f \n",gain);
    return 0;
}
*/
// ------------- EXERCICE 4-------------------
/*
int zoo_zoo_land(int t[20]){
    int tmp;
    int incr = 0;
    for(int i = 0; i<10;i++){
        tmp = rand() % 9 + 1;
        if(i == 0 || tmp>t[i-1]){
            t[i] += tmp;
            incr ++;
        }
        else{
            t[i-1] = tmp;
        }
    }
    return incr;
}


int main(){
    srand(time(NULL));
    int t[20];
    for(int i = 0; i<20;i++){
        t[i] = 0;
    }
    int zzl = zoo_zoo_land(t);
    printf("l'indice le plus haut calcule est %d \n",zzl);
    return 0;

}

*/

//----- EXERCICE 5 -----------
int prefixe(int *t1, int n1, int *t2, int n2){
    if(n2>=n1){
        printf("invalide n1 > n2 \n");
        return 0;
    }
    for(int i = 0; i<n1; i++){
        if(t1[i] != t2[2]){
            return 0;
        }
    }
    return 1;
}


int main(){
    if(prefixe(T1, n1, T2, n2))
        printf("Le tableau T1 est un prefixe du tableau T2.\n");
    else
        printf("Le tableau T1 n’est pas un prefixe du tableau T2.\n");

}


//---------EXERCICE 7-----------------
struct list{
    int i;
    struct list *succ;
};

void ajouter(struct list *L, int n){
    struct list *T = L;
    struct list *N = malloc(sizeof(struct list));
    N->succ = NULL;
    N->i = n;
    while(T != NULL && T->succ := NULL;){
        T = T->succ;
    }
    if(L != NULL){
        T->succ = N;
    }
    else{
        L = N;
    }
}

