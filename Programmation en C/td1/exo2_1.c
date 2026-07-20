#include<stdio.h>

int main()
{
    float franc,euro;
    printf("entrez votre somme en francs\n");
    scanf("%f",&franc);
    euro = (franc/6.55957);
    printf("la somme %f équivaut à %f euros\n",franc,euro);
    return 0;
}