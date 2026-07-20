#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float delta, s1,s2;
    printf("entrez a\n");
    scanf("%d",&a);
    printf("entrez b\n");
    scanf("%d",&b);
    printf("entrez c\n");
    scanf("%d",&c);
    delta = (b*b) - 4*a*c;
    if(delta==0)
    {
        s1 = (-b/2*a);
        printf("l'équation n'admet qu'une solution X = %f\n",s1);
    }
    else
    {
        if(delta>0)
        {
            s1 = (-b-sqrtf(delta))/ 2*a;
            s2 = (-b+sqrtf(delta))/ 2*a;
            printf("l'équation admet 2 solutions. X1 = %f et X2 = %f\n",s1,s2);
        }
        else
            printf("l'équation n'admet aucune solution\n");
    }
    return 0;

}