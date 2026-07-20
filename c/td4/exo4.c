#include<stdio.h>
void ascii_art(int n){
    for(int i = 0; i < n; i++){
        printf("*");
    }
    printf("\n");
}

int main(){   
    int n;
    printf("entrez n :\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        ascii_art(n);
    }
   return 0;
}