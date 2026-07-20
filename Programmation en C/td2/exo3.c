#include<stdio.h>

int main()
{
    int value, somme = 0, i=0;
    float moy;
    printf("entrez valeur:\n");

    while(scanf("%d", &value) != EOF){
        somme+= value;
        i ++;
    }
    if (i > 0) {
        printf("somme = %d\n", somme);
        moy = (float)somme / i;
        printf("la moyenne pour %d avec %d valeurs est de %.2f \n", somme,i,moy);
    }
    else{
        printf("aucune valeur saisie\n");
    }
    return 0;

}