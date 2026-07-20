#include<stdio.h>
#include<stdlib.h>

//1)
struct une_date{
    int jour, mois, annee;
};

//2)

int main(){
    struct une_date date;
    int j,m,a;
    printf("entrez le jour\n");
    scanf("%d",&j);
    printf("entrez le mois\n");
    scanf("%d",&m);
    printf("entrez l'annee\n");
    scanf("%d",&a);
    date.jour = j;
    date.mois = m;
    date.annee = a; 
    printf("la date saisie est le %02d/%02d/%d \n", date.jour, date.mois,date.annee);
    return 0;
}