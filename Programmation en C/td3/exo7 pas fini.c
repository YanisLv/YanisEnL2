#include<stdio.h>
#include<stdlib.h>

void fibonacci(int n){
    int fibo[2][2] = {{1,1},{1,0}};
    int c[2][2]= {{0,0},{0,0}};
    for(int i = 0; i < 2;i++){
        for(int j = 0; j<2;j++){
            for(int a =0;a<n-1;a++){ 
            
                for(int k = 0; k<2; k++){
                    c[i][j] += fibo[i][k]*fibo[k][j];
                }
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
{sss
    int n;
    printf("entrez n pour fibo\n");
    scanf("%d",&n);
    fibonacci(n);

    return 0;
}