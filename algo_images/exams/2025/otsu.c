#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pgm.h"
#include "otsu.h"

/*Question 1*/
pgm_t *seuillage_image_binaire(pgm_t *img, int seuil) {
    if(img == NULL) return NULL;
    pgm_t *p = pgm_alloc(img->width,img->height);
    if(p == NULL) return NULL;
    p->max_value = img->max_value;
    for(int i = 0; i<p->height; i++){
        for(int j = 0; j<p->width; j++){
            if(img->pixels[i][j] <seuil){
                p->pixels[i][j] = 0;
            }
            else{
                p->pixels[i][j] = 255;
            }
        }
    }
    return p;
}

/*Question 2*/
int histogramme(pgm_t *img, int *histogramme) {
    return 0;
}

/*Question 3*/
void afficher_histogramme(int *histogramme, int max_value, const char *nom) {
}

/*Question 4*/
void sauver_histogramme(int *histogramme, int max_value, const char *fname) {
}


/**************************************************************************/
/*Question 5 : test des fonctions precedentes */
/*Compléter le fichier main.c */
/**************************************************************************/

/**************************************************************************/
/*Question 6 : vérification*/
/*Effectuer les traitements et les vérifications demandées*/
/**************************************************************************/

/*Question 7*/
double histo_normalise_et_mu_total(pgm_t *img, double *probas) {
    return 0.0;
}

/*Question 8*/
int seuil_otsu(const double *probas, double mu_total, int max_value) {
    return 0;
}

/*Question 9*/
pgm_t *pgm_otsu_binarize(pgm_t *img) {
    return NULL;
}


/*************************************************************************/
/*Question 10 : test des fonctions de l'algorithme d'Otsu */
/*Compléter le fichier main.c */
/**************************************************************************/

/**************************************************************************/
/*Question 11 : vérification*/
/*Effectuer les traitements et les vérifications demandées*/
/**************************************************************************/