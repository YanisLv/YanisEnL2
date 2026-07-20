#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// Écrire une fonction :
// Une matrice carrée est magique si la somme de chaque ligne, 
//chaque colonne et les deux diagonales est la même.


int estMagique(int t[10][10], int n){
    int sommeLigne = 0, sommeCol = 0, sommeDiag = 0, sommeDiag2 = 0, tmp = 0, somme_ref = 0;
    
    for(int i = 0; i<n;i++){
        somme_ref += t[0][i];
    }
    printf("somme ref = %d \n",somme_ref);
    for(int i = 1; i <n;i++){
        sommeLigne = 0;
        for(int j = 0; j<n;j++){
            sommeLigne += t[i][j];
        }
        printf("somme ligne = %d \n",sommeLigne);
        if(sommeLigne != somme_ref){
            return 0;
        }
    }

    for(int i = 0; i < n;i++){
        sommeCol = 0;
        for(int j = 0; j < n;j++){
            sommeCol += t[j][i];
        }
        printf("somme col = %d \n",sommeCol);
        if(somme_ref != somme_ref){
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        sommeDiag = 0;
        for(int j = 0; j < n; j++){
            if(i == j){
                sommeDiag += t[i][j];
            }
        }
        printf("somme diag1 = %d \n",sommeDiag);
        if(sommeDiag != somme_ref){
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        sommeDiag2 = 0;
        for(int j = n-1; j >= 0; j--){
            if(i == (n-1 - i)){
                sommeDiag2 += t[i][j];
            }
        }
        printf("somme diag2 = %d \n",sommeDiag2);
        if(sommeDiag2 != somme_ref){
            return 0;
        }
    }
    return 1;

}

int main(){

    int t[10][10] = {{2,5,7},{2,1,0},{3,8,4}};
    int non_magique = estMagique(t,3);
    int t2[10][10] = {{2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };
    
    int magique =estMagique(t2,3);
    /*
    if(non_magique == 1){
        printf("le carre est magique \n");
    }
    else{
        printf("le carre n'est pas magique \n");
    }
    */

    if(magique == 1){
        printf("le carre est magique \n");
    }
    else{
        printf("le carre n'est pas magique \n");
    }

    return 0;
}