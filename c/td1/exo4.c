#include<stdio.h>
int main()
{
    int a, b;
    printf("entrez une valeur pour a\n");
    scanf("%d",&a);
    printf("entrez une valeur pour b\n");
    scanf("%d",&b);
    if(a<0 && b<0 || a>0 && b>0)
        printf("le résultat est positif\n");
    else
        if(a<0 && b>0 || a>0 && b<0)
            printf("le résultat est négatif\n");
        else
            printf("le resultat est nul\n");
    return 0;
}