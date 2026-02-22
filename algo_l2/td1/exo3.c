#include <stdio.h>
#include <stdlib.h>
#define N 20 //le nombre maximum de noeud 
int n , nf, papa[N], feuille[N];
//saisie d'un arbre avec le tab de papa
void saisie(int n ){// n le nombre de noeuds actuel 
    for (int i=1; i <=n; i++){
        printf("entrez le papa de %d \n", i);
        scanf("%d",&papa[i]);
    }
    //affichage de papa 
    for(int i=1; i<=n;i++){
        printf("le papa de %d est %d \n", i, papa[i]);
    }//fin de la saisie 
}

void feuilles(int n){
    nf=0;
    for (int i=1; i<=n;i++){
        //tester si i est une feuille 
        int est_feuille=1;
        for (int j =1;j<=n; j++){
            if (papa[j]==i){
                est_feuille=0;
                break;
            }
        }
        if (est_feuille==1){
            feuille[++nf]=i;
        }
        //fin de la boucle for(i=1...)
    }
}
int monter(int f){
    //f est une feuille , initialisation de h
    int h=0;
    while (f!=1){
        f=papa[f];
        h++;
    }
    return h;
}
int hauteur(int nf){
    //initialisation de la hauteur de l'arbre h
    int h=0;
    for (int i=1; i<=nf;i++){
        int a =monter(feuille[i]);
        if (a>h){
            h=a;
        }
    }return h;
}
int main(){
    n=11;
    saisie(11);
    feuilles(11);
    for (int i=1; i<=nf; i++){
        printf("%d \t", feuille[i]);
    }
    monter(7);
    printf("\nle maximum des arcs est : %d \n",hauteur(7) );
    return 0;
}
