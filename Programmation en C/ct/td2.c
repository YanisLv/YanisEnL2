#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<w32api.h>
//#include<math.h>

//-- EXO 1
/*
int main(){
    int n;
    printf("n = \n");
    scanf("%d",&n);
    int res = 1, i = 1;
    while(i<= n){

        res *= i;
        i++;
    }
    printf("fact %d = %d \n",n,res);
    return 0;

}
*/
int premier(int n){
    int cpt = 0;
    if(n == 1){
        return 0;
    }
    for(int i =2; i<n;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
int parfait(int n){
    int somme = 0;
    for(int i = 1; i<n;i++){
        if(n%i == 0){
            somme += i;
        }
    }
    if(somme == n){
        return 1;
    }
    return 0;
}
//--------------- EXO 2---------------------
/*
int main(){
    int n;
    //printf("n = \n");
    //scanf("%d",&n);
    
    if(parfait(n)){
        printf("nombre parfait \n");
    }
    else{
        printf("pas parfait \n");
    }
    
    for(int i = 1; i<= 1000; i++){
        if(parfait(i)){
            printf("%d ",i);
        }
    }
    printf("\n");
    
    return 0;
}
*/

// ----------------- EXERCICE 3----------------
/*
int main(){

    int n, somme = 0, i = 0;
    while(scanf("%d",&n) != EOF){
        
        i++;
        somme +=  n;
    }
    printf("somme = %d moyenne = %d\n",somme, somme/i);

    return 0;
}
*/
/*
int main(){
    srand(time(NULL));
    int n = rand() % 100;
    int f;
    int essai = 100, i = 0;
    printf("n = %d\n",n);
    printf("devinez le nombre secret \n");
    while(i<essai && n != f){
        
        scanf("%d",&f);
        if(f>n){
            printf("c inferieur\n");
        }
        if(f<n){
            printf("c superieur\n");
        }
        i++;
    }

    if(i<n){
        printf("trouve en %d essais \n",i);
    }
    else{
        printf("loupe\n");
    }
    return 0;

}

*/

// ------------- EXERCICE 6--------
/*

int main(){
    int a,k;
    printf("entrez a et k\n");
    scanf("%d %d",&a, &k);
    int un = a;
    printf("u0 = %d, ",un);
    for(int i = 1; i<=k;i++){
        if(un % 2 == 0){
            un = un / 2;
        }
        else{
            un = 3* un + 1;
        }
        printf("u%d = %d, ",i,un);

    }
    return 0;
}
*/

//------------------  EXERCICE 8-----------------------------
int main(){
    srand(time(NULL));
    int l =9;
    int h = 2, r = 3;
    int p = 20;
    for(int i =0; i<l; i++){
        for(int j = 0; j<(l*2);j++){
            if(j<l-i || j> l+i){
                printf(" ");
            }
            else{
                if(rand()%101<=p){
                    printf("o");
                }
                else{
                    printf("^");
                }
                
            }
        }
        printf("\n");
    }
    for(int i = 0; i<h;i++){
        for(int j = 0; j<(l*2);j++){
            if(j<l-r || j > l+r){
                printf(" ");
            }
            else{
                printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}