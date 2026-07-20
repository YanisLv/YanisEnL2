#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Écrire un programme C qui lit un réel (flottant) au clavier, représentant le rayon d’un
//disque, et qui calcule puis affiche l’aire de ce disque sur la sortie standard.

int main()
{
    float r, aire;
    printf("entrez rayon : \n");
    scanf("%f",&r);
    aire = M_PI * (r*r);
    printf("l'aire du disque de rayon %.2f est de %.2f \n",r,aire);

    return 0;
}