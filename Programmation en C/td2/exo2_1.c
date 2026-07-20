#include<stdio.h>

int est_premier(int x){
    int cpt=0;
    if(x<2){
        return 0;
    }
    for(int i = 2; i<x;i++)
    {
        if(x%i ==0){
            cpt ++;
        }
    }
    if(cpt>0){
        return 0;
    }
    else{
        return 1;
    }
}

int est_parfait(int x)
{
    int somme=0;
    for(int i = 1; i<x;i++)
    {
        if(x%i ==0){
            somme+=i;
        }
    }
    // printf("somme = %d\n",somme); >test
    if(somme==x){
        return 1;
    }
    return 0;
}
/*------------------------------NOMBRE PREMIER------------------------------*/
/*
int main()
{
    int n;
    printf("entrez n:\n");
    scanf("%d",&n);
    
    if(est_premier(n)){
        printf("le nombre %d est premier\n",n);
    }
    else{
        printf("le nombre %d n'est pas premier\n",n);
    }
    return 0;

}
*/
/*
int main()
{
    int k;
    printf("entrez k:\n");
    scanf("%d",&k);

    for(int i = 1; i<=k;i++){
        if(est_premier(i)){
            printf("%d; ",i);
        }
    }
    return 0;
}
*/


/*-----------------------------------NOMBRE PARFAIT--------------------------------*/
/*
int main()
{
    int n;
    printf("entrez n:\n");
    scanf("%d",&n);
    if(est_parfait(n)){
        printf("le nombre est parfait\n");
    }
    else{
        printf("le nombre n'est pas parfait\n");
    }
    return 0;
}
*/
int main()
{
    int k;
    printf("entrez k:\n");
    scanf("%d",&k);

    for(int i = 1; i<=k;i++){
        if(est_parfait(i)){
            printf("%d; ",i);
        }
    }
    return 0;
}
