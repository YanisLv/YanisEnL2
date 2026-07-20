#include<stdio.h>

int main()
{
    int value, min = 9999, max=0;
    printf("entrez valeur:\n");
    if (scanf("%d", &value) != EOF) {
    min = value; //comme si on initialisait à t[0] dans le parcours d'un tableau
    max = value;
        while(scanf("%d", &value) != EOF){
            if(value>max){
                max = value;
            }
            if(value<min){
                min = value;
            }
        }
    }
    printf("la valeur maximale est %det la valeur min est %d\n",max,min);
    return 0;
}