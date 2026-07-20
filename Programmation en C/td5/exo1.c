#include<stdio.h>
#include<stdlib.h>



// 1)
int *allou(int n){
    int *tab = NULL;
    tab = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        tab[i] = 0;
    }

    
    return tab;
}
// 2)
void allou2(int **tab, int n){
    //int *tab = NULL;
    *tab =malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        (*tab)[i] = 0;
    }
    //return tab;
}
void afficher(int *tab, int n){
    for(int i = 0; i < n; i++){
        printf("%d  ",tab[i]);
    }
}


int main(){

    int n = 10, *tab = allou(n);
    int *tab2= NULL;
    
    afficher(tab, n);
    printf("\n");
    allou2(&tab2,n);
    afficher(tab2,n);
    printf("\n");
    free(tab);
    free(tab2);
    afficher(tab2);
    return 0;
}

