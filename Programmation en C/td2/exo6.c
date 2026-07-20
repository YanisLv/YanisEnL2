#include<stdio.h>
int main(){
    int a,b,r=0;
    printf("entrez a et b \n");
    scanf("%d %d",&a,&b);
    while(b!=0){
        if(b % 2 == 0){
            a *= 2;
            b /= 2;
        }
        else{
            b -= 1;
            r += a;
        }

    }
    printf("le resultat de la multiplication masriya est %d \n",r);
    return 0;
}