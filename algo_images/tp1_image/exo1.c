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
    p->t = malloc(height * sizeof(unsigned char *));
    for(int i = 0; i<height; i++){
        p->t[i] = malloc(width*sizeof(unsigned char));
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



struct pgm *pgm_read_asc(char *fname){
    int height, width, max_value;
    int tmp;
    FILE *fic = fopen(fname,"r");
    if(fic != NULL){
        char buffer[256];
        fgets(buffer, sizeof(buffer), fic);  // pour sauter p2 et le commentaires inutiles
        fgets(buffer, sizeof(buffer), fic);
        //fscanf(fic, "%*[^\n]\n"); > 2ème façon
        //fscanf(fic, "%*[^\n]\n"); > 2ème façon
        fscanf(fic, "%d",&width);
        fscanf(fic, "%d",&height);
        fscanf(fic, "%d",&max_value);
        struct pgm *p = pgm_alloc(height, width, max_value);
        for(int i = 0; i<height; i++){
            for(int j = 0; j<width; j++){
                fscanf(fic, "%c",&tmp);
                p->t[i][j] = (unsigned char)tmp;
            }
        }
        fclose(fic);
        return p;
    }
    printf("erreur d'allocation \n");
    return NULL;
}


//1.5

int pgm_write_asc(char *fname, struct pgm *p){
    FILE *fic = fopen(fname,"w");
    if(fic != NULL){
        fprintf(fic, "%s\n","P2");
        fprintf(fic, "%d %d\n", p->width, p->height);
        for(int i =0; i<p->height; i++){
            for(int j = 0; p->width; j++){
                fprintf(fic, "%c", p->t[i][j]);
            }
        }
        fclose(fic);
        return 1;
    }
    return 0;
}

// 1.6
struct pgm *pgm_read_bin(char *fname){
    
}

int main(){
    int h,w,max;
    struct pgm *p = pgm_read_asc("eye_s_asc.pgm");
    if(p != NULL){
        printf("height = %d, width = %d, max = %d\n",
               p->height, p->width, p->max_value);
    }
    else{
        printf("ça marche pas ntm\n");
    }
    for(int i = 0; i<p->height; i++){
        for(int j = 0; j<width;)
    }
    return 0;
}