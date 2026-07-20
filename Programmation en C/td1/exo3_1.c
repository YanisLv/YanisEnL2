#include<stdio.h>
int main()
{
    int a,b;
    printf("entrez une valeur pour a\n");
    scanf("%d",&a);
    printf("entrez une valeur pour b\n");
    scanf("%d",&b);
    if (a>=b)
        printf("vrai\n");
    else
        printf("faux\n");
    return 0;
}