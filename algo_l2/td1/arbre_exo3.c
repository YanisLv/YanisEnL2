#include<stdio.h>
#include<stdlib.h>
#define N 20 //  Le nb maximum de noeuds de l'arbre
int n, papa[N], feuilles[N];
// saisie d'un arbre avec le TAB DE PAPA
void saisie(int n){
    // le nbr de noeuds actuel
    for(int i = 1; i<= n; i++){
        printf("Entre stp le papa de %d \n",i);
        scanf("%d",&papa[i]);
    }
    // AFFICHAGE DE PAPA
    for(int i = 1; i<= n;i++){
        printf("la papa de %d est %d \n",i,papa[i]);
    }
    // FIN SAISIE
}

void feuille(int n){
    int i,j, nf = 0;
    for(i = 1; i<=n;i++){
        // tester si i est une feuille
        int est_feuille = 1;
        for(j = 1; j<= n;j++){
            if(papa[j] == i){
                est_feuille = 0;
                break;
            }
        }
        if(est_feuille == 1){       // i est une feuille
            feuilles[++nf] = i;
        } // FIN DE LA BOUCLE FOR i 
    }
    printf("les feuilles sont \n");
    for(int k = 1; k<= nf; k++){
        printf("%d, ",feuilles[k]);
    }
    printf("\n");
}

int monter(int f){
    // f, une feuille
    // Initialisation de k
    int k = 0;
    while(f != 1){
        f = papa[f];
        k ++;
    }
    return k;
}

int hauteur(int nf){
    // initialisation de la hauteur de l'arbre h
    int h = 0;
    for(int i = 1; i<= nf; i++){
        int a = monter(feuilles[i]);
        if(a > h){
            h = a;
        }
    }
    return h;
}

int main(){
    saisie(11);
    feuille(11);
    
    return 0;
}