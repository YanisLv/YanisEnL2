#include<stdio.h>
#include<stdlib.h>
//------ 1) Définition des pixels et des images.----------

//1
struct pixel{
    short r;
    short g;
    short b;
};

struct image_ppm{
    int largeur;
    int hauteur;
    short val_max;
    struct pixel tab_pix[512][512];

};

//2
void charger_ppm(char ppm[255], struct image_ppm* image){
    short tmp;
    FILE* fic = fopen(ppm,"r");
    if(fic != NULL){
        fseek(fic,3,SEEK_SET);
        fscanf(fic, "%d", &image->largeur);
        fscanf(fic, "%d", &image->hauteur);
        fscanf(fic, "%d", &image->val_max);

        for(int i = 0; i < image->hauteur; i++){
            for(int j = 0; j < image->largeur; j++){
                fscanf(fic,"%d %d %d",&image->tab_pix[i][j].r, &image->tab_pix[i][j].g,&image->tab_pix[i][j].b);
            }
        }
    }
    fclose(fic);
}


//3

void copier_ppm(char img1[255], char img2[255], struct image_ppm* image1, struct image_ppm* image2){
    charger_ppm(img1, &image1);
    
}




//--- MAIN---
int main(){
    struct image_ppm image;
    charger_ppm("lena.ppm",&image);
    return 0;
}