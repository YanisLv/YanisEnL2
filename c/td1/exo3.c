#include<stdio.h>
int main()
{
    int n;
    printf("entrez une valeur entière\n");
    scanf("%d",&n);
    if(n%2==0)
        printf("la valeur est paire\n");
    else
        printf("la valeur est impaire\n");
    return 0;
}