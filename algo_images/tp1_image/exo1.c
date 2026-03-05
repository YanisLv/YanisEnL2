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



struct pgm *pgm_write_asc(char *fname){
    int height, width, max_value;
    FILE *fic = fopen(fname,"r");
    if(fic != NULL){
        char buffer[256];
        fgets(buffer, sizeof(buffer), fic);  // pour sauter p2 et le commentaires inutiles
        fgets(buffer, sizeof(buffer), fic);
        //fscanf(fic, "%*[^\n]\n"); > 2ème façon
        //fscanf(fic, "%*[^\n]\n"); > 2ème façon
        fscanf(fic, "%d",height);
        fscanf(fic, "%d",width);
        fscanf(fic, "%d",max_value);
        struct pgm *p = pgm_alloc(width, height, max_value);
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

        return 0;
}