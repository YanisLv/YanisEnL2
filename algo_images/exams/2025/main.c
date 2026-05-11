#include "pgm.h"
#include "otsu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_in.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Bon travail */
    //a
    FILE *fic = fopen(argv,"r");
    if(fic == NULL){
        printf("erreur de lecture \n");
        return EXIT_FAILURE;
    }

    char format[3], buffer[255];
    int height, width, max_value;
    
    fscanf(fic,"%s",format);
    while(fgetc(fic) == '#'){
        fgets(buffer,sizeof(buffer),fic);
    }
    fscanf(fic, "%d %d %d",&width, &height, &max_value);
    pgm_t *p = pgm_alloc(width,height);
    p->max_value = max_value;

    
    return EXIT_SUCCESS;
}
