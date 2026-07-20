#ifndef OTSU_H
#define OTSU_H

#include "pgm.h"

/* seuillage image binaire*/
pgm_t *seuillage_image_binaire(pgm_t *img, int seuil);

/* histogramme de l'image */
int histogramme(pgm_t *img, int *histogramme);

/* Affiche dans le terminal l'histogramme donné */
void afficher_histogramme(int *histogramme, int max_value, const char *nom);

/* Sauvegarde l'histogramme dans un fichier texte*/
void sauver_histogramme(int *histogramme, int max_value, const char *fname);

/* Calcul des probabilités et de la moyenne globale de l'image */
double histo_normalise_et_mu_total(pgm_t *img, double *probas);

/* recherche seuil optimal d'Otsu */
int seuil_otsu(const double *probas, double mu_total, int max_value);

/* fonction principale de binarisation utilisant la méthode d'Otsu */
pgm_t *pgm_otsu_binarize(pgm_t *img);

#endif /* OTSU_H */

