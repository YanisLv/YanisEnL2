#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//--------------1,2)
int naiveopt(char *t, char *m){
    int cmp = 0;
    int lm = strlen(m);
    int lt = strlen(t);
    int i = 0;
    while(i<= lt-lm){
        int k = 0;
        while(k<lm){
            cmp++;
            if(m[k] == t[i+k]){
                k++;
            }
            else{
                break;
            }
        }
        if(k == lm){
            printf("Nombre total de comparaisons : %d\n", cmp);
            return i;
        }
        else{
            if(k==0){
                i++;
            }
            else{
                i +=k+1;
            }
            
        }
        //printf("%d\n",i);
    }
    printf("Nombre total de comparaisons : %d\n", cmp);
    return -1;
}

//--------- 3)
//Pour t = "abceababccabcdabb" et m = "abcd" avec la 
// naive on a 17 comparaisons or avec la naiveopt on a 14 comparaisons

int main(){
    char* t = "abceababccabcdabb";
    char *m = "abcd";
    
    if(naiveopt(t,m) == -1){
        printf("le motif n'est pas present dans le texte \n");
    }
    else{
        printf("le motif est present, le premier est indice est a %d \n",naiveopt(t,m));
    }
    
    return 0;
}