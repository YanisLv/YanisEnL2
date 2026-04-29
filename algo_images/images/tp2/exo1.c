#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 


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
    
}

int main(){

    return 0; 
}