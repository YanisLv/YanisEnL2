#include<stdio.h>
#include<stdlib.h>

// 1.1
struct pgm{
    int height;
    int width;
    int max_value;
    unsigned char **t;
};

// 1.2
struct pgm *pgm_alloc(int height, int width, int max_value){
    struct pgm* p = malloc(sizeof(struct pgm));
    p->height = height;
    p->width = width;
    p->max_value = max_value;
    p->t = malloc(height * sizeof(struct pgm *));
    for(int i = 0; i<width; i++){
        p->t[i] = malloc(sizeof(struct pgm));
    }
    return p;
}

// 1.3

void pgm_free(struct pgm *p){
    if(p != NULL){
        if(p->t != NULL){
            for(int i = 0; i<p->height; i++){
                if(p->t[i] != NULL){
                    free(p->t[i]);
                }
            }
        }
        free(p);
    }      
}

//1.4



