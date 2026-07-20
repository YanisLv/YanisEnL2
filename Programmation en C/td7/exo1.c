#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//1)
int compteur(char *nom_fichier){
    int i = 0, lignes = 0, mots = 0;
    char tmp;
    FILE *fic = fopen(nom_fichier, "r");
        if(fic == NULL){
            return 0;
        }
        lignes = 1;
        while(fscanf(fic,"%c",&tmp) != EOF){
            if(tmp != ' '){
                i++;
            }
            if(tmp == '\n'){
                lignes  = lignes +1 ;
            }
            if(tmp == ' '){
                mots++;     // FAUX !
            }
        }
        printf("il y a %d lignes et %d mots \n",lignes,mots);
        return i;
    fclose(fic);
}

//2)




int main(){

    int a= compteur("texte.txt");
    printf("il y a %d caracteres dans le fichier\n",a);
    
    return 0;
}