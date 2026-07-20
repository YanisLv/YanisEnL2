#include<stdio.h>

int est_permute(int n, int t[n]){
    int permute = 1, vu = 0;
    
    for(int i = 0; i<n; i++){
        if(t[i]<0 || t[i]>= n){
            permute = 0;
        }
    }

    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(j!=i){
                if(t[i] == t[j]){
                    permute = 0;
                }
            }
        }
    }
    return permute;

}

int main()
{

    int t[10];

    for(int i = 0; i<10; i++){
        printf("entrez la %de valeur :\n",i+1);
        scanf("%d", &t[i]);
    }

    int verif = est_permute(10,t);
    
    if(verif == 1){
        printf("le tableau est bien une permutation\n");
    }
    else{
        printf("le tableau n'est pas une permutation\n");
    }

    return 0;
}