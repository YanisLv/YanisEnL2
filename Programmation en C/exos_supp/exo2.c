#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Écrire une fonction :
// qui retourne 1 si la matrice carrée mat est symétrique, 0 sinon.
// Tester dans le main plusieurs exemples.

int est_symetrique(int t[100][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(t[i][j] != t[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    int t1[100][100] = {{1,5,3},{5,2,6},{3,6,7}};
    int t2[100][100] = {{1,5,3},{5,2,6},{3,1,0}};

    int v1 = est_symetrique(t1,3);
    int v2 = est_symetrique(t2,3);
    if(v1 == 1){
        printf("la matrice t1 est symetrique \n");
    }
    else{
        printf("la matrice t1 n'est pas symetrique \n");
    }

    if(v2 == 1){
        printf("la matrice t2 est symetriqueq \n");
    }
    else{
        printf("la matrice t2 n'est pas symetrique \n");
    }

    return 0;
}