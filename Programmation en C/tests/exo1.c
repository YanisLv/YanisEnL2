#include<stdio.h>
#include<stdlib.h>

struct etudiant {
    char nom[30];
    char prenom[30];
    float notes[5];
};

void saisirClasse(struct etudiant c[30],int n){
    for(int i = 0; i < n; i++){
        printf("saisir prenom etudiant %d : \n",i+1);
        scanf("%s",c[i].prenom);

        printf("saisir nom etudiant %d : \n",i+1);
        scanf("%s",c[i].nom);

        for(int j = 0; j < 5; j++){
            printf("saisir note %d de etudiant %d \n",j+1,i+1);
            scanf("%f",&c[i].notes[j]);
        }

    }

}

float moyenne(struct etudiant e){
    float somme = 0, moy;
    for(int i = 0; i < 5; i++){
        somme += e.notes[i];
    }
    moy = somme / 5;
    return moy;
}

void afficher_meilleur(struct etudiant c[30], int n){
    int boss = moyenne(c[0]);
    int boss_ind = 0;
    for(int i = 1; i< n; i++){
        if(moyenne(c[i])>boss){
            boss = moyenne(c[i]);
            boss_ind = i;
        }
    }
    printf("le meilleur est %s %s\n",c[boss_ind].prenom, c[boss_ind].nom);

}



int main(){
    struct etudiant classe[30];
    saisirClasse(classe,5);
    afficher_meilleur(classe,5);
    return 0;
}