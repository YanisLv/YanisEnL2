#include<stdio.h>
int main()
{
    float taux_cnss = 0.175, taux_impot = 0.035, salaire_brut, salaire_base,prime_tech,prime_trsp,prime_1_enf,val_cnss, val_impot,prime_des_enfants,taux_trv,net,nb_enfant, nb_jours_trv;
    printf("entrez le salaire de base\n");
    scanf("%f",&salaire_base);
    printf("entrez le nombre d'enfants à charge\n");
    scanf("%f",&nb_enfant);
    printf("entrez le nb de jours travaillés\n");
    scanf("%f",&nb_jours_trv);
    printf("entrez la prime d'un enfant\n");
    scanf("%f",&prime_1_enf);
    printf("entrez la prime de technicité\n");
    scanf("%f",&prime_tech);
    printf("entrez la prime transport\n");
    scanf("%f",&prime_trsp);

    val_cnss = taux_cnss*salaire_brut;
    val_impot = taux_impot*salaire_brut;
    prime_des_enfants = prime_1_enf*nb_enfant;
    taux_trv = nb_jours_trv /26;
    salaire_brut = (salaire_base + prime_tech + prime_trsp + prime_des_enfants) * taux_trv;
    net = salaire_brut - val_impot - val_cnss;
    printf("le salaire net est de %f euros\n",net);
    return 0;
}