#include<stdio.h>
int main()
{
    int i,val;
    float somme,moy; // voir pk il faut mettre somme en float pour afficher le résultat exact
    for(i=1;i<=4;i++)
    {
        printf("saisissez votre %dème valeur\n",i);
        scanf("%d",&val);
        somme = somme + val;
    }
    moy = somme / 4;
    printf("la moyenne pour ces 4 valeurs est de %f\n",moy);
    return 0;
}