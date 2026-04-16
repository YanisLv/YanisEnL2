#include<stdio.h>
#include<stdlib.h>

// 1.1
struct pgm{
    int height;
    int width;
    unsigned char max_value;
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
                fscanf(fic, "%d",&tmp);
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
    int tmp;
    if(fic != NULL){
        printf("oui\n");
        fprintf(fic, "%s\n","P2");
        fprintf(fic, "%d %d\n", p->width, p->height);
        fprintf(fic,"%d",p->max_value);
        for(int i =0; i<p->height; i++){
            for(int j = 0; j<p->width; j++){
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
    FILE* fic = fopen(fname,"rb");
    if(fic != NULL){
        int h, w, max_w,tmp;
        char type;
        fscanf(fic,"%s",type);
        fscanf(fic, "%d %d %d", &w, &h, &max_w);
        printf("%s \n",type);
        fgetc(fic);
        struct pgm *p = pgm_alloc(h,w,max_w);
        if(p == NULL){
            printf("erreur d'allocation\n");
            return NULL;
        }

        for(int i = 0; i<p->height; i++){
            //fread(p->t[i], sizeof(unsigned char), p->width, fic); ||ligne directement
            for(int j = 0; j<p->width;j++){
                fread(&p->t[i][j], sizeof(unsigned char),1,fic);
            }
        }
        return p;
    }
    printf("erreur d'allocation\n");
    return NULL;
}

//--1.8)

void pgm_negative(struct pgm *src, struct pgm *dst){
    int h = dst->height, w = dst->width;
    unsigned char max_v=dst->max_value;
    ;
    //dst = pgm_alloc(h,w,max_v);
    //printf("%d %d %d\n",dst->height, dst->width, dst->max_value);
    for(int i = 0; i<h;i++){
        for(int j = 0; j<w;j++){

            int tmp =src->t[i][j];
            printf("tmp = %d \n",tmp);
            dst->t[i][j] =(max_v - tmp);
        }
    }        
}


//-1.9)
void pgm_extract(char *fname, int dx, int dy, int weight, int height){
    struct pgm *pgm_t = pgm_alloc(height,weight,)
}


int main(){
    
    int h,w,max;
    struct pgm *p = pgm_read_asc("eye_ext.pgm");
    struct pgm *dst = pgm_alloc(p->height,p->width,p->max_value);
    pgm_negative(p,dst);
    for(int i = 0; i<p->height;i++){
        for(int j = 0; j<p->width; j++){
            printf("%d ",dst->t[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}