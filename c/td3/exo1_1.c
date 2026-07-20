#include<stdio.h>
//1)

void afficher_tableau(int *t, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", t[i]);
    }
    printf("\n");
}

//2)
int min_tab(int *t, int n){
    int min = t[0];
    int ind_min = 0;
    for(int i = 1; i < n; i++){
        if(t[i]<min){
            min = t[i];
            ind_min = i;

        }
    }
    return ind_min;
}

int max_tab(int *t, int n){
    int max = t[0];
    int ind_max = 0;
    for(int i = 1; i < n; i++){
        if(t[i]>max){
            max = t[i];
            ind_max = i;

        }
    }
    return ind_max;
}

//3)

int rech_val(int *t, int k, int n){
    int cpt = 0;
    for(int i = 0; i < n; i++){
        if(t[i] < k){
            cpt++;
        }
    } 
    return cpt;
}

//4)
//---- VERSION AVEC COPIE DE TABLEAU---
void decale(int *t, int n, int k){
    int t2[10];

    for(int i = 0; i < n; i++){
        t2[i] = t[i];
    }
    for(int i = 0; i < n; i++){
        t[i] = t2[(k+i)%n];
    }
    
}

void decale2(int *t, int n, int k){
    int tmp;
    for(int i = 0; i < n-k; i++){
        if(i<k-1){
            tmp = t[i];
            t[n-k+i+1] = tmp;
        }
        t[i] = t[(k+i)%n];
    }
}
int main(){
    
    int n, t[5], cpt = 0;
    
    for(int i = 0; i<5; i++){
        printf("entrez la %de valeur : \n", i+1);
        scanf("%d", &t[i]);
    }
    afficher_tableau(t,5);
    /*
    printf("entrez une valeur a rechercher\n");
    scanf("%d",&n);
    int rech = rech_val(t,n,10);
    
    int mini = min_tab(t,10);
    int maxi = max_tab(t,10);
    printf("il y a %d val plus petit que %d\n", rech,n);
    printf("l'indice de la valeur minimale est %d et celle maximale est %d \n",mini,maxi);

    */

    decale2(t,5,2);
    
    afficher_tableau(t,5);
    


    


    return 0;
}