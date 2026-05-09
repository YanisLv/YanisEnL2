#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1
#define N 1


struct pgm{
    int height;
    int width;
    unsigned char max_value;
    unsigned char **t;
};
typedef struct pgm pgm_t;


struct rgb{
    unsigned char r,g,b;
};
typedef struct rgb rgb_t;


struct ppm{
    int height, width, max_value;
    rgb_t **pixels;
};
typedef struct ppm ppm_t;

ppm_t *ppm_alloc(height, width, max_value){
    ppm_t *p = malloc(sizeof(ppm_t));
    p->height = height;
    p->width = width;
    p->max_value = max_value;
    p->pixels = malloc(height*sizeof(rgb_t));
    


}

// EXERCICE 1
double B0(double x){
    int tmp = abs(x);
    if(tmp>0.5){
        return (double)0;
    }
    else if(tmp <0.5){
        return (double)1;
    }
    return (double)0.5;
}

double B1(double x){
    int tmp = abs(x);
    if(tmp>1){
        return (double)0;
    }
    else if(x>= -1 && x<=0){
        return (double)x+1;
    }
    return (double)1-x;
}

double B2(double x){
    int tmp = abs(x);
    if(tmp>1){
        return 0;
    }
    else if(x>= -1.5 && x<= -0.5){
        return (double)0.5*((x+1.4)*(x+1.4));
    }
    else if(x>= -0.5 && x<=0.5){
        return (double)0.75*(x*x);
    }
    else if(x>= 0.5 && x<=1.5){
        return (double)0.5*((x-1.5)*(x-1.5));
    }
}

double B3(double x){
    int tmp = abs(x);
    if(tmp>2){
        return 0;
    }
    else if(tmp>= 0 && tmp<=1){
        return (double)1/pow(tmp,3) - pow(x,2) + 2/3;
    }
    else if(tmp>=0.5 && tmp <=2){
        return (double)1/6*pow(2-tmp,3);
    }
}

double (*B[4])(double) = {B0, B1, B2, B3};

unsigned char interpolation_pgm(pgm_t *image, double x, double y){
    int i, j;
    double res = 0.0;

    int xmin = floor(x - 2);
    int xmax = ceil(x + 2);
    int ymin = floor(y - 2);
    int ymax = ceil(y + 2);

    for (i = xmin; i <= xmax; i++) {
        for (j = ymin; j <= ymax; j++) {

            /* Vérification des bornes */
            if (i >= 0 && i < image->width &&
                j >= 0 && j < image->height) {

                double wx = B[N](x - i);
                double wy = B[N](y - j);

                res += image->t[j][i] * wx * wy;
            }
        }
    }

    /* Clamp entre 0 et 255 */
    if (res < 0) res = 0;
    if (res > 255) res = 255;

    return (unsigned char)(res);
}


//1.3)
rgb_t interpolation_ppm(ppm_t *image, double x, double y) {
    int i, j;

    double res_r = 0.0;
    double res_g = 0.0;
    double res_b = 0.0;

    int xmin = floor(x - 2);
    int xmax = ceil(x + 2);
    int ymin = floor(y - 2);
    int ymax = ceil(y + 2);

    for (i = xmin; i <= xmax; i++) {
        for (j = ymin; j <= ymax; j++) {

            if (i >= 0 && i < image->width &&
                j >= 0 && j < image->height) {

                double wx = B[N](x - i);
                double wy = B[N](y - j);
                double w = wx * wy;

                rgb_t p = image->pixels[j][i];

                res_r += p.r * w;
                res_g += p.g * w;
                res_b += p.b * w;
            }
        }
    }

    /* Clamp */
    if (res_r < 0) res_r = 0; if (res_r > 255) res_r = 255;
    if (res_g < 0) res_g = 0; if (res_g > 255) res_g = 255;
    if (res_b < 0) res_b = 0; if (res_b > 255) res_b = 255;

    rgb_t result;
    result.r = (unsigned char)(res_r);
    result.g = (unsigned char)(res_g);
    result.b = (unsigned char)(res_b);

    return result;
}

//1.4)
pgm_t *rotation_pgm(pgm_t *image, double theta, int x0, int y0){

    pgm_t *res = malloc(sizeof(pgm_t));
    res->width = image->width;
    res->height = image->height;
    res->max_value = image->max_value;
    res->t = malloc(res->height * sizeof(unsigned char *));
    for (int i = 0; i < res->height; i++) {
        res->t[i] = malloc(res->width * sizeof(unsigned char));
    }

    for(int i = 0; i<image->height; i++){
        for(int j = 0; j<image->width; j++){
            double x = x0+(j-x0)*cos(theta) - (i-y0)*sin(theta);
            double y = y0+(j-x0)*sin(theta)+(i-y0)*cos(theta);

            if (x >= 0 && x < image->width &&
                y >= 0 && y < image->height) {

                res->t[i][j] = interpolation_pgm(image, x, y);
            } else {
                res->t[i][j] = 0;
            }
        }
    }
    return res;
}

//1.5
ppm_t *zoom(ppm_t *image, double lambda, int x0, int y0, int Dx, int Dy){    
    ppm_t *res = malloc(sizeof(ppm_t));
    res->height = Dy;
    res->width = Dx;
    res->max_value = 255;
    res->pixels = malloc(Dy*sizeof(rgb_t*));
    for(int i = 0; i<Dy; i++){
        res->pixels[i] = malloc(Dx*sizeof(rgb_t));
    }

    for(int i = 0; i<Dy;i++){
        for(int j = 0; j<Dx;j++){
            double x = x0 + lambda*(i-x0);
            double y = y0 + lambda*(j-y0);
            if (x >= 0 && x < image->width &&
                y >= 0 && y < image->height){

                res->pixels[i][j] = interpolation_ppm(image,x,y);
            }
            else{
                res->pixels[i][j].r=0, res->pixels[i][j].g=0, res->pixels[i][j].b = 0; 
            }    
            
        }
    }
    return res;
}
int main(){

    return 0; 