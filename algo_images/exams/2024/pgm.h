#ifndef PGM_H
#define PGM_H

typedef struct pgm {
    int height;
    int width;
    int max_value;
    unsigned char **pixels;
} pgm_t;

pgm_t *pgm_alloc(int width, int height);
int pgm_free(pgm_t *pgm);
pgm_t *pgm_read(const char *fname);
int pgm_write(const char *fname, pgm_t *pgm);

#endif
