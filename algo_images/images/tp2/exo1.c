#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

ppm_t *ppm_alloc(int height, int width, int max_value){
    ppm_t *p = malloc(sizeof(ppm_t));
    p->height = height;
    p->width = width;
    p->max_value = max_value;
    p->pixels = malloc(height*sizeof(rgb_t*));
    for(int i = 0; i<height; i++){
        p->pixels[i] = malloc(width*sizeof(rgb_t));
    }
    return p;
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
    int tmp = fabs(x);
    if(tmp>1){
        return (double)0;
    }
    else if(x>= -1 && x<=0){
        return (double)x+1;
    }
    return (double)1-x;
}

double B2(double x){

    if(fabs(x) > 1.5)
        return 0.0;

    if(x >= -1.5 && x <= -0.5)
        return 0.5 * (x + 1.5) * (x + 1.5);

    if(x >= -0.5 && x <= 0.5)
        return 0.75 - x*x;

    return 0.5 * (x - 1.5) * (x - 1.5);
}

double B3(double x){

    x = fabs(x);

    if(x > 2.0)
        return 0.0;

    if(x <= 1.0)
        return 0.5*x*x*x - x*x + 2.0/3.0;

    return (1.0/6.0)*pow(2.0 - x, 3);
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
            double x = x0+(j-x0)*cos(-theta) - (i-y0)*sin(-theta);
            double y = y0+(j-x0)*sin(-theta)+(i-y0)*cos(-theta);

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
    if(image == NULL) return NULL;    
    ppm_t *res = ppm_alloc(Dy,Dx,image->max_value);
    if(res == NULL) return NULL;
    double midX = Dx / 2.0;
    double midY = Dy / 2.0;
    for(int i = 0; i<Dy;i++){
        for(int j = 0; j<Dx;j++){
            double x = x0 + (j - midX) / lambda;
            double y = y0 + (i - midY) / lambda;
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


//1.5 b)

ppm_t *shear(ppm_t *image, int cx, int cy, int Dx, int Dy){
    if(image == NULL) return NULL;
    ppm_t *res = ppm_alloc(Dy,Dx, image->max_value);
    if(res == NULL) return NULL;
    for(int i = 0; i<Dy; i++){
        for(int j = 0; j<Dx; j++){
            double x = (j-cx*i)/(1.0-cx*cy);
            double y = (i-cy*j)/(1.0-cy*cx);
            if (x >= 0 && x < image->width && y >= 0 && y < image->height){
                res->pixels[i][j] = interpolation_ppm(image,x,y);
            }
            else{
                res->pixels[i][j].r=0, res->pixels[i][j].g=0, res->pixels[i][j].b = 0; 
            }
        }
        
    }
    return res;
}

// EXERCICE 2 
//2.1)
struct point{
    int x,y;
};
typedef struct point point_t;

double *get_affine_transformation(point_t X_start[3],
                                  point_t X_end[3]){

    double *a = malloc(6*sizeof(double));

    double x0 = X_start[0].x;
    double y0 = X_start[0].y;

    double x1 = X_start[1].x;
    double y1 = X_start[1].y;

    double x2 = X_start[2].x;
    double y2 = X_start[2].y;

    double xp0 = X_end[0].x;
    double yp0 = X_end[0].y;

    double xp1 = X_end[1].x;
    double yp1 = X_end[1].y;

    double xp2 = X_end[2].x;
    double yp2 = X_end[2].y;

    double det =
        x0*(y1-y2)
      - y0*(x1-x2)
      + (x1*y2 - x2*y1);

    if(fabs(det) < 1e-10)
        return NULL;

    a[0] =
        (xp0*(y1-y2)+xp1*(y2-y0)+xp2*(y0-y1))/det;

    a[1] =
        (xp0*(x2-x1)+xp1*(x0-x2)+xp2*(x1-x0))/det;

    a[2] =
        (xp0*(x1*y2-x2*y1)
        +xp1*(x2*y0-x0*y2)
        +xp2*(x0*y1-x1*y0))/det;

    a[3] =
        (yp0*(y1-y2)+yp1*(y2-y0)+yp2*(y0-y1))/det;

    a[4] =
        (yp0*(x2-x1)+yp1*(x0-x2)+yp2*(x1-x0))/det;

    a[5] =
        (yp0*(x1*y2-x2*y1)
        +yp1*(x2*y0-x0*y2)
        +yp2*(x0*y1-x1*y0))/det;

    return a;
}

//2.2)
ppm_t *affine_transformation(ppm_t *image,
                             double *a)
{
    ppm_t *res =
        ppm_alloc(image->height,
                  image->width,
                  image->max_value);

    double det =
        a[0]*a[4] - a[1]*a[3];

    if(fabs(det) < 1e-10)
        return NULL;

    for(int y=0;y<image->height;y++){

        for(int x=0;x<image->width;x++){

            double xs =
                (a[4]*(x-a[2])
                -a[1]*(y-a[5]))/det;

            double ys =
                (-a[3]*(x-a[2])
                +a[0]*(y-a[5]))/det;

            if(xs >=0 && xs < image->width &&
               ys >=0 && ys < image->height){

                res->pixels[y][x] =
                    interpolation_ppm(image,xs,ys);
            }
            else{

                res->pixels[y][x].r = 0;
                res->pixels[y][x].g = 0;
                res->pixels[y][x].b = 0;
            }
        }
    }

    return res;
}

int main(){

    return 0; 