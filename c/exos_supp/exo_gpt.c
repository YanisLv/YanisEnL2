#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// calcule la moyenne des éléments de la ligne ligne du tableau tab.
//Dans le main, afficher la moyenne de chaque ligne.

//💡 Bonus : ajouter une fonction afficherTableau pour afficher le tableau joliment.

float moyenne_Ligne(int tab[100][100], int n, int m, int ligne){
        float moy, somme = 0;
        for(int i = 0; i < m; i++){
            somme += tab[ligne][i];
        }
        moy = somme / m;
    
    return moy;
}

void creer_tableau(int t[100][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            t[i][j] = rand() % 26;
        }
    }
}

void afficher_tableau(int t[100][100], int n, int m){
    for(int i += 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int n, m, tab[155][100];
    float moy_tmp;
    printf("entrer un entier n pour lignes \n");
    scanf("%d",&n);
    printf("entrer un entier m pour colonnes : \n");
    scanf("%d",&m);
    creer_tableau(tab,n,m);
    afficher_tableau(tab,n,m);
    
    for(int i = 0; i < n; i++){
        moy_tmp = moyenne_Ligne(tab,n,m,i);
        printf("la moyenne des valeurs de la ligne %d est %.2f \n", i+1,moy_tmp);
    }

    
    return 0;
}
