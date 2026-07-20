#include<stdio.h>
#include <stdio.h>

void damier(int t, int c) {
    int i, j;
    for (i = 0; i < t * c; i++) { 
        for (j = 0; j < t * c; j++) { 
            // On alterne les motifs selon la "parité" du bloc courant
            if ( ((i / c) + (j / c)) % 2 == 0 )
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }
}

int main() {
    int t = 4, c = 2;
    damier(t, c);
    return 0;
}



/*
void damier(int t, int c){
    for(int j = 0; j< t; j++){
        if(j%t == 0){
            for(int k = 0; k < c; k++){
                for(int i = 0; i < t; i++){
                    if((i%c) == 0){
                        printf("XX");
                    }
                    else{
                        printf("..");
                    }
                }
                printf("\n");
            }
        }
        else{
            for(int k = 0; k < c; k++){
                for(int i = 0; i < t; i++){
                    if((i%c) == 0){
                        printf("..");
                    }
                    else{
                        printf("XX");
                    }
                }
                printf("\n");
            }
        }
        
   }

}
*/
/*
void damier(int t, int c){
    for(int k = 0; k<c;k++){
        for(int i = 0; i < c; i++){
            for(int j = 0; j< t/2;j++){
                printf("XX");
                printf("..");
            }
            printf("\n");
        }
        for(int i = 0; i < c; i++){
            for(int j = 0; j< t/2;j++){
                printf("..");
                printf("XX");
            }
            printf("\n");
        }
    }
}

*/
void damier(int t, int c){
    for(int i = 0; i < t; i=i+1){
        if((i%t == 0)){
            for(int j = 0; j < c; j++){
                printf("X");
            }
        }
        else{
            for(int j = 0; j < c; j++){
                printf(".");
            }
        }
    }
}




int main()
{
    damier(4,2);
    return 0;
}