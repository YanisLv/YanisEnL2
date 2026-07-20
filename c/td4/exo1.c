#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float perimetre(int rayon){
    return 2 * M_PI * rayon;
}

int main()
{
    int r;
    float res;
    printf("entrez le rayon (en cm) d'un cercle \n");
    scanf("%d",&r);
    res = perimetre(r);
    printf("le perimetre du cercle de rayon %d cm est %.2f cm", r,res);
    return 0;
}