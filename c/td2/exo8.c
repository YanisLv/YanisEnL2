#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#include<math.h>
int main()
{
    int l, h,r,p;

    printf("entrez hauteur sapin l\n");
    scanf("%d",&l);
    printf("entrez rayon du tronc\n");
    scanf("%d",&r);
    printf("entrez un hauteur du tronc h\n");
    scanf("%d",&h);
    printf("entrez probabilité boules de noel p\n");
    scanf("%d", &p);

    
    int aleatoire = rand()%100+1;

    printf("Hauteur du sapin = %d\n \n",l);
    for(int i = 0; i<=l; i++){
        for(int k = 0; k<= l-1-i;k++){          // COMPRENDRE LE K FACON ESCALIER
            printf(" ");
        }
        for(int j = 0; j <= i*2; j++){
            if(rand()%101<=p){
                printf("o");
            }
            else{
                printf("^");
            }
            
            
        }

        printf("\n");
    }

    for(int i = 0; i<h; i++){
        for(int j = 0; j<((l*2)/r); j++){
            printf(" ");
        }
        for(int k = 0; k< r*2; k++){
            printf("+");
        }
        printf("\n");
    }

    return 0;
}
