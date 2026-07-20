#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    srand(time(NULL));
    int aleatoire = rand()%101;
    printf("%d\n", aleatoire);
    int n,i=0, essais = 10;
    printf("entrez le nombre\n");
    while(i < essais){
        scanf("%d",&n);
        if(n==aleatoire){
            printf("bravo en %d essais\n",i+1);
            return 0;
            
        }
        else{
            if(n< aleatoire){
                printf("plus grand, réessayez\n");
            }
            else{
                printf("plus petit, réessayez\n");
            }
        }
        i++;
    }

    printf("raté le nb etait %d\n",aleatoire);
    
    return 0;
}