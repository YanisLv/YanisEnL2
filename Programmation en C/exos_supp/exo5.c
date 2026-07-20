#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// écrire du fonction
// qui retourne le plus grand élément du tableau.


int maximum(int t[50][50], int n, int m){
    int max = t[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            if(!(i == 0 && j == 0)){
                if(t[i][j] > max){
                    max = t[i][j];
                }
            }
        }
    }
    return max;
}

void generer_tab(int t[50][50], int n, int m){
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            t[i][j] = rand()%20;
        }
    }
}

void afficher_tab(int t[50][50], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int n,m;
    int tab[50][50];
    printf("entrez n\n");
    scanf("%d", &n);

    printf("entrez m\n");
    scanf("%d", &m);

    generer_tab(tab,n,m);
    afficher_tab(tab,n,m);
    int maxi = maximum(tab,n,m);
    printf("le maximum est %d\n",maxi);
    return 0;
}