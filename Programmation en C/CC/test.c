#include<stdio.h>


int main(){
    int t[5][5] = {{1,1,1,2,2},{1,1,1,1,1},{1,1,1,2,2},{2,1,1,2,2},{2,1,1,1,1}};
    

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    int cpt = 0;
    int k = 0, j = 0;

    while(k < 5){
        while(j < 5){
            if(t[i][j] == 1){
                
            }
        }
        
    }
    printf("y'a %d adj \n",cpt);
    return 0;
}