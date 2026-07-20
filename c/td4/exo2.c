#include<stdio.h>
#include<stdlib.h>

double distance(double xa, double ya, double xb, double yb){

    return abs(xb-xa)+abs(yb-ya);
}

int main(){

    double x1, y1, x2, y2;
    printf("entrez les coordonnees de a et b\n");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    double res = distance(x1, y1, x2, y2);
    printf("la distance entre a et b est de %.2lf\n",res);
    return 0;
}