#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
//--------------------EXERCICE 2-------------------
/*
int puissance(int x, int n){
    int res = 1;
    for(int i = 0; i<n;i++){
        res *= x;
    }
    return res;
}



int main(){
    int trouve = 0;
    int n, tmp = 0;
    do{
        printf("entrez un entier > ou = a 1\n");
        scanf("%d",&n);
    }while (n <1);
    int i = 0, k = 0;
    while(tmp< n){
        tmp = puissance(2,i);
        if(tmp<= n){
            k = tmp;
        }
        i++;
    }
    printf("la plus grande puissance inf ou = a %d est %d (2exp%d)\n",n,k);
    return 0;
}


*/
//-------------- EXERCICE 3--------------
/*
void ligne(int n, char k){
    for(int i = 0; i<n; i++){
        printf("%c",k);
    }
}


int main(){
    int h = 3, c = 2;
    int i = 0, k = 0, m = 0;
    for(i = 0; i<h;i++){
        for(int j = 0; j<2;j++){
            ligne(n-1-i,' ');
        }
    }
    return 0;
}
*/
/*
int ps(int x, int y){
    int somme = x+y;
    int produit = x*y;
    return somme, produit;
}

int main(){
    int somme,pro = ps(4,4);
    printf("%d %d",somme,pro);
    return 0;
}

*/


//--------------- EXERCICE 5----------------------


void remplir(long long *t, int n)
{
    long long somme = 1;
    t[0] = 1;

    for (int i = 1; i < n; i++)
    {
        t[i] = i * somme;
        somme += t[i];
    }
}

void afficher(long long t[20])
{
    for (int i = 0; i < 20; i++)
        printf("%lld ", t[i]);
    printf("\n");
}
/*
int main()
{
    long long t[20] = {0};

    afficher(t);
    remplir(t);
    afficher(t);

    return 0;
}


// void remplir(int *t, int n)

*/

//---------------------- EXERCICE 6--------------------------
/*
int dicho(int t[4], int n, int e){
    int g = 0, d = n-1,  m;
    while(g<=d){
        m = (g+d)/2;
        if(t[m] == e){
            return 1;
        }
        if(t[m]>e){
            d = m-1;
        }
        else{
            g = m + 1;
        }
    }
    return -1;
}

int recherche(int t[3][4], int e){
    for(int i = 0; i<4;i++){
        if(dicho(t[i], 4, e) == 1){
            return 1;
        }
    }
    return -1;
}


int main(){
    int t[3][4] = {{1,5,23,24},{32,47,56,57},{60,71,82,90}};
    if(recherche(t,82) == 1){
        printf("trouve \n");
    }
    else{
        printf("pas trouve \n");
    }
}

*/

//-------------------- EXERCICE 9-----------------------

int main(){
    long long int n, *t= NULL;
    do{
        printf("veuillez entrer un entier > ou = a 1 \n");
        scanf("%lld",&n);
    }while(n<1);
    t = malloc(n*sizeof(long long int));
    for(int i = 0; i<n;i++){
        t[i] = 0;
    }
    remplir(t,n);
    for(int i = 0; i<n;i++){
        printf("%lld ",*(t+i));
    }
    free(t);
    printf("\n");
    return 0;
}