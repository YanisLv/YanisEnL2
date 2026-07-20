#include<stdio.h>
#include<stdlib.h>

void produit_matriciel(int m1[2][2], int m2[2][2]){
    int c[2][2]= {{0,0},{0,0}};
    for(int i = 0; i < 2;i++){
        for(int j = 0; j<2;j++){
            for(int k = 0; k<2; k++){
                c[i][j] += m1[i][k]*m2[k][j];
            }
        }
    
    }
    for(int i = 0; i<2;i++){
        for(int j = 0; j<2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}


int main()
{

    int mat1[2][2] = {{1,1},{1,0}}, mat2[2][2] = {{1,1},{1,0}};
    produit_matriciel(mat1,mat2);
    //printf("res = %ld\n",res);



    return 0;
}