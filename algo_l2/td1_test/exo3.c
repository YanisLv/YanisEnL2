#include <stdio.h>
#include <stdlib.h>
#define N 12 //le nombre maximum de noeud 
int n , nf, papa[N], feuille[N];

void saisie(int n){
    for(int i = 1; i<=n;i++){
        printf("entrez papa de %d\n",i);
        scanf("%d",&papa[i]);
    }
    //affichage
    for(int i = 1; i<=n;i++){
        printf("le papa de %d est %d \n", i,papa[i]);
    }
}

void trouver_feuilles(int n){
    nf = 0;
    for(int i = 1; i<=n;i++){
        int est_feuille = 1;
        for(int j = 1; j<=n;j++){
            if(papa[j] == i){
                est_feuille = 0;
                break;
            }
        }
        if(est_feuille == 1){
            feuille[++nf] = i;
        }
    }
    printf("fini\n");
}

int monter(int f){
    int h = 0;
    while(f!= 1){
        f = papa[f];
        h ++;
    }
    return h;
}

int hauteur(int nf){
    int max = 0,tmp=0;
    for(int i = 2;i<=nf;i++){
        tmp = monter(feuille[i]);
        if(tmp>max){
            max = tmp;
        }
    }
    return max;
}

int main(){
    saisie(N);
    trouver_feuilles(N);
    for (int i=1; i<=nf; i++){
        printf("%d \t", feuille[i]);
    }
    int h = hauteur(nf);
    printf("la hauteur est %d \n",h);
    return 0;
}