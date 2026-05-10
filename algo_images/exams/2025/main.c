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
    
    return EXIT_SUCCESS;
}
