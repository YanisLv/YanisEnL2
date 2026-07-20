#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//------------------EXERCICE 2----------------------
/*

int main(){
    int n;
    do{
        printf("entrez un entier superieur ou egal a 1\n");
        scanf("%d",&n);
    }while(n<1);

    int i = 1;
    while(i<=n){
        printf("(");
        int j = 1;
        while(j<=i){
            printf("%d",j);
            j++;
        }
        printf(")");
        i++;
    }
    return 1;
}
*/

//------------------EXERCICE 3-------------
/*
int factorielle(int k, int fact2k){
    return (fact2k)*(2*(k+1))*(2*(k+2));
}

int pow_x(float x, float xexp2k){
    return (x*x)*xexp2k;
}


*/


//-------------- EXERCICE 4---------------------
/*

void somme_produit(int a, int b, int *S, int *P){
// il faut passer l'adresse de S et P en paramètre pour pouvoir les modifier et les renvoyer
// dans le main. Et pas seulement  passer S et P en copie car après l'exécution de la fonction
// on aura une perte de memoire de S et P

    *S = a+b, *P = a*b;
}

int main(){
    int a = 17, b = 18, S = 0, P = 0;
    somme_produit(a,b,&S,&P); // "&" car on passe l'adresse de S et P
    printf("S = %d et P = %d \n",S,P);
    return 0;
}

*/

//------------ EXERCICE 5----------------

/*
void afficher(int *t, int n){
    for(int i = 0; i<n;i++){
        printf("%d ",*(t+i));
    }
    printf("\n");
}

void tri(int t[10]){
    int nb_0 = 0, nb_1 = 0, min, max, val_min, val_max;
    for(int i = 0; i<10;i++){
        if(t[i] == 0){
            nb_0 += 1;
        }
    }
    for(int i = 0; i<10; i++){
        if(i<nb_0){
            t[i] = 0;
        }
        else{
            t[i] = 1;
        }          
    }
}
void tri_selection(int *t, int n){
    int j, tmp;
    for(int i = 1; i<n;i++){
        tmp = t[i];
        j = i;
        while(t[j-1]>tmp && j>0){
            t[j] = t[j-1];
            j = j-1;
        }
        t[j] = tmp;
    }
}

int main(){
    int t[10] = {0,1,1,0,1,0,0,1,1,0};
    afficher(t,10);
    tri_selection(t,10);
    afficher(t,10);
    return 0;
}

*/
/*-------------------- EXERCICE 6*/

// variable dont la valeur est l'adresse mémoire d'une autre variable

// --> a = 4 et *ptr = 4, et b = 2
// --> a = 1, *ptr = 1 et b = 2
// --> 0, 0 2s
/*
 int
 main(void) {
int a = 2, b = a;
 int * ptr = &a;
 *ptr = a * (*ptr);
 printf("--> a= %d et *ptr= %d... et b= %d\n", a, *ptr, b);
 a = ((*ptr)--);
 printf("--> a= %d et *ptr= %d... et b= %d\n", a, *ptr, b);
 a = (*ptr--) - 1;
 printf("--> a= %d et *ptr= %d... et b= %d\n", a, *ptr, b);
 return 0;
}
*/ 

//-------------------EXERCICE 7*************
