#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Écrire un programme C qui lit deux notes réelles au clavier, puis qui calcule la moyenne
//pondérée (40%−60%), et indique si la moyenne est strictement inférieure à 10.

int main(){

    float a,b,moy;
    printf("entrez premiere note \n");
    scanf("%f",&a);
    printf("entrez deuxieme note \n");
    scanf("%f",&b);
    moy = ((a * 4) + (b * 6))/ 10;//(a*0.4) + (b*0.6);
    if(moy<10){
        printf("moyenne %.2f inferieure a 10 \n",moy);
    }
    else{
        printf("moyenne %.2f superieure a 10 \n",moy);
    }
    return 0;
}