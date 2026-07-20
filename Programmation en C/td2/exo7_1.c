#include<stdio.h>
#include<time.h>
#include<stdlib.h> 

int main(){
    int a,k;

    printf("entrez un entier a\n");
    scanf("%d",&a);
    printf("entrez un entier k\n");
    scanf("%d",&k);
    int res = a;
    for(int i = a; i<=k; i++){
        if(res % 2 == 0){
            res = res / 2;
            printf("U(%d) = %d; ", i,res);
        }
        else{
            res = (3 * res) + 1;
            printf("U(%d) = %d; ", i,res);
        }
    }
    return 0;
}
