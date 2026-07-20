#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Exercice 1)
// Le programme lit les 3 notes d'une matières puis va calculer la moyenne pondérée avec 25 % pour les cc1 et cc2 et 50% pour le CT
//puis va vérifier les 2 cas : inférieur a 10 ou supérieur puis affiche le résultat de la note et du cas.

//2)


/*
int main(){

    int a,b;
    printf("entrez les valeurs a et b\n");
    scanf("%d %d",&a,&b);

    if((a<0 && b>0) || (a>0 && b<0)){
        printf("le résultat est négatif\n");
    }
    else if (a == 0 || b ==0)
    {
        printf("le résultat est nul \n");
    }
    else{
        printf("le résultat est positif");
    }
    
    return 0;
}
*/

// EXERCICE 2)

//1) 
/*
int main(){

    int n,fact=1;
    float e=0;

    printf("entrez un entier n : \n");
    scanf("%d",&n);
    
    for(int i = 0; i<=n;i++){
        fact = 1;
        for(int j = 1; j<i+1;j++){
            fact *= j;
        }
        e += 1./fact;
    }
    printf("expo %d vaut %.2f", n, e);
    
    return 0;
}
*/
//2)

int factorielle(int x){
    int facto = 1;
    if(x <= 0) return facto;
    for(int i = 1; i<x+1; i++){
        facto *= i;
    }
    return facto;
}

//3)
/*
int main(){

    int n;
    printf("entrer entier n : \n");
    scanf("%d",&n);

    int i = 0,f;
    float res = 0;
    while(i<n+1){
        f = factorielle(i);
        res += 1. / f;
        printf("%.2f ",res);
        
        i++;
    }
    printf("\n");
    printf("expo %d vaut %.2f", n, res);

    return 0;
}
*/

//- EXERCICE 3)

//1)
/*
void crepe(int *t,int n){

    for(int i = n-1; i>=0;i--){
        int esp = n-t[i];
        for(int j = 0; j<esp;j++){
            printf(" ");
        }
        for(int k = 0; k<t[i];k++){
            printf("*");
        }
        printf("|");
        for(int k = 0; k<t[i];k++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0;i<n;i++){
        printf("-");
    }
    printf("+");
    for(int i = 0;i<n;i++){
        printf("-");
    }
    printf("\n");

}


int main(){

    int tab[255];
    int i = 0;
    do{
        printf("entrer une valeur pour t%d \n",i);
        scanf("%d", &tab[i]);
        i++;
    }while(i<10);
    crepe(tab,10);
    return 0;
}
*/
// EXERCICE 4)
/*
//1) le tableau est de taille 8 (car échiquier de taille 8x8)

//2)
void initialiser(int *t){
    for(int i = 0; i<8; i++){
        t[i] = -1;
    }
}
//3)
void print(int *t){
    printf("{");
    for(int i = 0; i<8; i++){
        if(i == 7){
            printf("%d",t[i]);
        }
        else{
            printf("%d, ",t[i]);
        }
    }
    printf("}");
}

//4)
int check(int *t, int i){
    int ligne_i = t[i] / 8;
    int colonne_i = t[i] % 8;
    for(int j = 0; j<8; j++){
        if(j != i && t[i] != -1){
            if(t[j]/ 8 == ligne_i || t[j] % 8 == colonne_i){
                return 0;
            }
            if(t[j]>t[i]){
                if((t[j] - t[i])% 9 == 0 || (t[j] - t[i])% 7 == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main(){

    int t[8] = {0, 12, 23, 29, 34, 46, 49, 59};
    int bool;
    for(int i = 0; i<8;i++){
        bool = check(t,i);
        if(bool == 1){
            printf("oui\n");
        }
        else{
            printf("non\n");
        }
    }
    return 0;
}
*/

//EXERCICE 5
//1) On souhaite retourner un pointeur sur un tableau (ou du moins
// sur la premier valeur d'un tableau fait 2 erreurs :
// la premiere son programme semble vouloir retourner la valeur en t[0] stockée dans tmp
// alors que le proto souhaite renvoyer un pointeur d'int
// la deuxieme est que tmp est déclaré en int et non pas en pointeur d'int
// de plus utiliser & est faux car une valeur ptr
// pointe deja vers une adresse memoire
//2)
/*
int *foos(int n){
    int *t = malloc(n*sizeof(int));
    for(int i = 0; i<n;i++){
        t[i] = i;
    }
    return t;
}
//3)
void foo(int **t, int n){
    *t = malloc(n*sizeof(int));
    for(int i = 0; i<n;i++){
        (*t)[i] = i;
    }
}

int main(){

    int *tab = NULL;
    foo(&tab,10);
    for(int i = 0;i<10;i++){
        printf("%d ",tab[i]);
    } 
    printf("\n");

    return 0;
}

*/
// EXERCICE 6

/*
//1)
int marche(int *t, int n){
    int i = 0;
    while(i<n && (t[i]>t[i+1] || ((t[i-1] > t[i]) && (t[i-1]-t[i]>t[i]-t[i+1])))){
        i++;
    }
    return i;
}

int main(){
    srand(time(NULL));
    int n;
    printf("entrez n : \n");
    scanf("%d",&n);
    int *tab = malloc(n*sizeof(n));
    for(int i = 0; i<n;i++){
        tab[i] = rand() %21;
    }
    for(int i = 0; i<n;i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    int bille = marche(tab,n);
    printf("la bille s'est arretee a la %de marche \n",bille);
    free(tab);
    return 0;
}
*/
//--- EXERCICE 7

//1)

void allouer_triangle(int ***t, int n){
    *t = malloc(n*sizeof(int*));
    for(int i = 0; i<n;i++){
        (*t)[i] = malloc((i+1)*sizeof(int));
    }
    
    //1)
    for(int i = 0;i<n;i++){
        (*t)[i][0] = 1;
        (*t)[i][i] = 1;
    }
    //2)
    for(int i = 1; i<n;i++){
        for(int j = 1; j<i;j++){
            (*t)[i][j] = (*t)[i-1][j-1] + (*t)[i-1][j];
        }
    }
}
//2)
void afficher(int **t, int n){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<i+1;j++){
            printf("%d ", (t)[i][j]);
        }
        printf("\n");
    }
}

void liberer(int **tab,int n){
    if(tab!= NULL){
        for(int i = 0; i<n;i++){
            if(tab[i] != NULL){
                free(tab[i]);
            }
        }
        free(tab);
    }
}

//3)
int main(){

    int **tab = NULL;
    allouer_triangle(&tab, 5);
    afficher(tab,5);
    liberer(tab,5);
    afficher(tab,5);
    return 0;
}


