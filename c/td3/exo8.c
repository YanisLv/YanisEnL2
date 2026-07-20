#include<stdio.h>
#include<stdlib.h>

int main()
{

    int n;
    int **P = NULL;
    printf("entrez n>0 pour triangle de Pascal\n");
    scanf("%d",&n);
    P = (int**)malloc((n+1)*sizeof(int*));
    if(P != NULL){
        for(int i = 0; i<=n;i++){
            P[i] = (int*)malloc(n*sizeof(int));
        }
        // ------ INITIALISATION---------
        for(int i = 0; i <= n;i++){
            P[i][0] = 1;
            for(int j = 1; j < n; j++){
                P[i][j] = 0;
            }
        }

        //----- MANIPULATION ----------

        for(int i = 1; i <= n; i++){
            for(int j = 1; j<n; j++){
                P[i][j] = P[i-1][j-1]+ P[i-1][j];
            }
        }



        //------ AFFICHAGE--------//
        for(int i = 0; i <= n; i++){
            for(int j = 0; j<n; j++){
                if(P[i][j] != 0)
                    printf("%d ",P[i][j]);
            }
            printf("\n");
        }

        //--------- LIBERATION MEMOIRE--------
        for(int i = 0; i<=n;i++){
            free(P[i]);
        }
        free(P);
    }

    
    

    scanf("%d",&n);

    


    return 0;
}