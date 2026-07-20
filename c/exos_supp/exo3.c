#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// Écrire une fonction : 
// qui remplit B avec la transposée de A.

void transpose(int A[50][50], int B[50][50], int n, int m){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = A[j][i];
        }
    }
}
void afficher_tableau(int t[50][50], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int a[50][50] = {{1,5,8},{2,6,1},{4,7,6},{3,9,0}};
    int b[50][50];
    transpose(a,b,4,3);
    afficher_tableau(a,4,3);
    afficher_tableau(b,3,4);
    return 0;
}