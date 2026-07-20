// ecrire une fonction 
// qui retourne 1 si tous les éléments hors diagonale sont nuls, sinon 0.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int estDiagonale(int t[10][10], int n){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            if(i != j){
                if(t[i][j] != 0){
                    return 0;
                }
            }
        }
    }
    return 1;
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
    int tab1[10][10]{{5,0,0},{0,9,0},{0,0,8}};
    afficher_tab(tab1,3,3);
    if(estDiagonale(tab1,3) == 1){
        printf("la matrice 1 est diagonale \n");
    }
    else{
        printf("la matrice 1 n'est pas diagonale \n");
    }
    return 0;
}