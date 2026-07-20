#include<stdio.h>
#include<stdlib.h>

void tri_bulle(int *t, int n){
    int tmp;
    for(int j = 0; j < n; j++){
        for(int i = 0; i <n-1; i++){
            if(t[i]<t[i+1]){
                tmp = t[i];
                t[i] = t[i+1];
                t[i+1] = tmp;
            }
        }  
    }
}

void afficher(int *t, int n){

    for(int i = 0; i<n; i++){
        printf("%d",t[i]);
    }
    printf("\n");
}


int main(){
    
    int t[255]= {8,2,9,4,1};
    afficher(t,5);
    tri_bulle(t,5);
    afficher(t,5);
    return 0;
}