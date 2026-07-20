#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int n;
    int fact = 1;
    printf("n;\n");
    scanf("%d",&n);
    for(int i =1;i<n+1;i++){
        fact *= i;
    }
    printf("fact %d = %d \n",n,fact);
    return 0;
}