#include "pgm.h"
#include "otsu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int max(int a, int b, int c)
{
    int m = a;

    if (b > m)
        m = b;

    if (c > m)
        m = c;

    return m;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_in.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Bon travail */
    //a)
    FILE *fic = fopen(argv[1],"r");
    if(fic == NULL){
        printf("erreur de lecture \n");
        return EXIT_FAILURE;
    }

char format[3];
    fscanf(fic, "%s", format);
    int height, width, max_value;
    // On consomme les espaces/retours à la ligne après le P2
    int c = fgetc(fic);
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
        c = fgetc(fic);
    }

    // Si on tombe sur un #, on saute la ligne
    if (c == '#') {
        char buffer[255];
        fgets(buffer, sizeof(buffer), fic);
        c = fgetc(fic); // On lit le caractère suivant après le commentaire
    }

    // TRÈS IMPORTANT : On remet le caractère lu (le '5' de 512) dans le flux
    ungetc(c, fic);

    // Maintenant fscanf peut lire les 3 nombres correctement
    if (fscanf(fic, "%d %d %d", &width, &height, &max_value) == 3) {
        printf("Succès ! Dimensions : %d x %d, Max : %d\n", width, height, max_value);
    }
    pgm_t *p = pgm_alloc(width,height);
    p->max_value = max_value;
    if(p == NULL) return EXIT_FAILURE;
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width;j++){
            unsigned int tmp;
            fscanf(fic, "%u",&tmp);
            p->pixels[i][j] = (unsigned char)tmp;
        }
    }

    fclose(fic);
    pgm_t *bin64 = seuillage_image_binaire(p,64);
    pgm_t *bin128 = seuillage_image_binaire(p,128);
    pgm_t *bin192 = seuillage_image_binaire(p,192);

    //c)

    //64
    FILE *fic1 = fopen("bin64.pgm","w");
    if(fic1 != NULL){
        fprintf(fic1, "P2\n");
        fprintf(fic1,"%d %d\n",bin64->width, bin64->height);
        fprintf(fic1,"%d\n",bin64->max_value);
        for(int i = 0; i<bin64->height;i++){
            for(int j = 0; j<bin64->width;j++){
                fprintf(fic1,"%hhu ",bin64->pixels[i][j]);
            }
            fprintf(fic1,"\n");
        }
    }
    fclose(fic1);

    //128
    FILE *fic2 = fopen("bin128.pgm","w");
    if(fic2 != NULL){
        fprintf(fic2, "P2\n");
        fprintf(fic2,"%d %d\n",bin128->width, bin128->height);
        fprintf(fic2,"%d\n",bin128->max_value);
        for(int i = 0; i<bin128->height;i++){
            for(int j = 0; j<bin128->width;j++){
                fprintf(fic2,"%hhu ",bin128->pixels[i][j]);
            }
            fprintf(fic2,"\n");
        }
    }
    fclose(fic2);

    //192

    FILE *fic3 = fopen("bin192.pgm","w");
    if(fic3 != NULL){
        fprintf(fic3, "P2\n");
        fprintf(fic3,"%d %d\n",bin192->width, bin192->height);
        fprintf(fic3,"%d\n",bin192->max_value);
        for(int i = 0; i<bin192->height;i++){
            for(int j = 0; j<bin192->width;j++){
                fprintf(fic3,"%hhu ",bin192->pixels[i][j]);
            }
            fprintf(fic3,"\n");
        }
    }
    fclose(fic3);

    //d)
    int *hist64 = malloc(256*sizeof(int));
    int h1 = histogramme(bin64, hist64);

    int *hist128 = malloc(256*sizeof(int));
    int h2 = histogramme(bin128, hist128);

    int *hist192 = malloc(256*sizeof(int));
    int h3 = histogramme(bin192, hist192);
    max(h1,h2,h3);
    sauver_histogramme(hist64,256,"bin64.txt");
    sauver_histogramme(hist128,256,"bin128.txt");
    sauver_histogramme(hist192,256,"bin192.txt");
    
    return EXIT_SUCCESS;
}
