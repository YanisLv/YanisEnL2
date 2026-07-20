#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void ecrire(char *nom_fichier){
    char texte[255];
    int i = 0;
    printf("entrez votre texte a inserer dans votre fichier : \n");
    scanf("%s",texte);
    FILE *fic = fopen(nom_fichier, "w");
    if(fic != NULL){
        fprintf(fic,"%s",texte);
    }
}

void ecrire_bin(char *nom_fichier){
    int a[5] = {17,20,23,6,25};
    int i = 0;
    FILE *fic = fopen(nom_fichier,"wb");
    if(fic != NULL){
        int ret = fwrite(a,sizeof(int),5,fic);
        printf("%d element on ete lue avec succes \n",ret);
    }
}

void lire_bin(char *nom_fichier){
    int a[19];
    FILE *fic = fopen(nom_fichier, "rb");
    int ret = fread(a,sizeof(int),19,fic);
    printf("Nombre d elements : %d \n", ret);
    for(int i = 0; i<ret;i++){
        printf("%d ",a[i]);
    }
    fclose(fic);
}

int main(){

    //ecrire("fichier_texte.txt");
    //ecrire_bin("tmp.bin");
    lire_bin("tmp2.bin");
    return 0;
};