#include<stdio.h>
#include<stdlib.h>

// 1)

int **alloc(int n, int m){
    int **tab = NULL;
    tab = (int**)malloc(n*sizeof(int*));

    if(tab != NULL){
        for(int i = 0; i < n; i++){
            tab[i] = (int*)malloc(m*sizeof(int));
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                tab[i][j] = 0;
            }
        }
    }
    return tab;
}

//2)
void alloc_sr(int *** tab, int n,int m){
    //tab = NULL;
    *tab = (int**)malloc(n*sizeof(int*));
    
    if(tab != NULL){
        for(int a = 0; a<n; a++){
            (*tab)[a] = malloc(m*sizeof(int));
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                (*tab)[i][j] = 0;
            }
        }
    }
        
}

//3 et 4))

int **produit_matriciel(int **a, int **b, int n){ // penser a faire matrice n*m
    int **res = NULL;
    res = malloc(n*sizeof(int*));
    
    if(res != NULL){
        for(int i = 0; i < n; i++){
            res[i] = malloc(n*sizeof(int));
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n;j++){
                res[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int k = 0; k < n;k++){
            for(int j = 0; j<n; j++){
                res[i][j] +=  a[i][k] * b[k][j];
            }
        }
    }

    return res;

}

//5)
void transposee(int ***tab,int n, int m){
    int tmp;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m; j++){
            tmp = (*tab)[i][j];
            (*tab)[i][j] = (*tab)[j][i];
            (*tab)[j][i] = tmp;
        }
    }
}

void afficher(int **tab, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
int main(){
    
    int n = 3,m;
    /*  1), 2)
    printf("entrez n : \n");
    scanf("%d",&n);
    
    printf("entrez m : \n");
    scanf("%d",&m);
    int **tab = alloc(n,m);
    //afficher(tab,n,m);
    int **tab2 = NULL;
    alloc_sr(&tab2,n,m);
    afficher(tab2,n,m);
    free(tab);
    free(tab2);
    */
    // PRODUIT MATRICIEL
    int **A = alloc(n,n);
    int **B = alloc(n,n);
    int **T = alloc(n,n);
    printf("Matrice A\n");
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            printf("entrez la valeur pour A[%d][%d] \n",i+1,j+1);
            scanf("%d",&A[i][j]);
        }  
    }

    printf("Matrice B\n");
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            printf("entrez la valeur pour B[%d][%d] \n",i+1,j+1);
            scanf("%d",&B[i][j]);
        }  
    }
    printf("Matrice qu'on va transposee :\n");
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            printf("entrez la valeur pour T[%d][%d] \n",i+1,j+1);
            scanf("%d",&T[i][j]);
        }  
    }
    afficher(T,n,n);
    transposee(&T,n,n);
    afficher(T,n,n);

/*
    for(int i =0;i<n;i++){
        for(int j = 0; j<n;j++){
            t1[i][j] = tmp1[i][j];
            t2[i][j] = tmp2[i][j];
        }
    }
    */
    int **t3 = produit_matriciel(A,B,n);

    //afficher(t3,n,n);

    return 0;
}

