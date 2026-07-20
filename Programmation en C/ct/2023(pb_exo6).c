#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// ------------EXERCICE 2)

//1)
/*
int main(){
    int n, somme = 0;
    do{
        printf("entrez un nombre n positif :\n");
        scanf("%d",&n);
    }while(n<= 0);

    for(int i = 0; i<=n;i++){
        somme += i;
    }
    printf("le resultat des %d premiers entiers est %d \n",n,somme);
    return 0;
}
*/

/*
//2)
int main(){
    int n, somme = 0;
    int m = 0;
    do{
        printf("entrez un nombre n positif :\n");
        scanf("%d",&n);
    }while(n<= 0);
    for(int i = 0; i < n-1;i++){
        for(int k = 0; k<i*i;k++){
            printf(" ");
        }
        printf("**");
        for(int j = 0; j<i;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
*/

//---------- EXERCICE 3--------

//1) 10 car il n'y a que 10 chiffres dans [0,9]

//2)
/*
void freq(int *T, int n, float **F){
    float somme = 0, moy = 0;
    for(int i = 0; i<10;i++){
        for(int j = 0; j<n;j++){
            if(i == T[j]){
                somme ++;
            }
        }
        moy = somme / 10;
        (*F)[i] = moy;
        somme = 0;
    }
}
void afficher(float *t,int n){
    for(int i = 0; i<n;i++){
        printf("%.2f, ",t[i]);
    }
}

int main(){

    srand(time(NULL));
    int t[15] ={7,4,5,7,9,6,3,7,8,0,3,6,9,8,7};
    float *f = malloc(10*sizeof(float));
    for(int i = 0; i<10;i++){
        f[i] = 0;
    }
    freq(t,15,&f);
    afficher(f,10);
    free(f);
    return 0;
}
*/
// ---------EXERCICE 4------------
/*
//1)
struct date{
    unsigned short j,m,a;
};

//2)
void afficher_date(struct date *d){
    printf("%02u/%02u/%04u",d->j,d->m,d->a);
}

//3) il doit enlever le &

//4)

struct date *creation(unsigned short j, unsigned short m, unsigned short a)
{
    struct date *d= malloc(sizeof(struct date));
    d->j = j, d->m = m, d->a = a;
    return d;
}

int main(){
    struct date *d = creation(7,5,2002);
   afficher_date(d);
    return 0; 
} 
*/ 
// ------ EXERCICE 5---

//1)

//2) non il faudrait utiliser un pointeur de pointeur dans le prototype de la fonction car on souhaite
// modifier ce tableau or ici T est une copie locale du pointeur passé par le programme. Donc
// la fonction ne modifie que la copie locale et à la sortie de la fonction, rien n'aura changé
// la memoire est perdue

// EXERCICE 6
//1)
/*
struct list{
    int op1, op2, res;
    char art;
    struct list *next;
};

//2)
void inserer(struct list **L, int op1, int op2, int res, char art){
    struct list *N = malloc(sizeof(struct list));
    N->op1 = op1, N->op2 = op2, N->res = res, N->art = art;
    N->next = NULL;
    struct list *T = *L;
    while(T != NULL && T->next != NULL){
        T = T->next;
    }
    if(*L != NULL){
        T->next = N;
    }
    else{
        *L = N;
    }
}

//3)
void vider(struct list **L){
    struct list *T = *L, *P = NULL;
    while(T!= NULL){
        P = T->next;
        free(T);
        T = P;
    }
}
int generer_probleme(int *P){
    int depart[24] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,25,50,75,100};
    int k, posable = 0, cpt = 0;
    P = malloc(6*sizeof(int));
    for(int i = 0; i<6;i++){
        k = rand() % 24;
        cpt = 0;
        for(int j = 0; j<6;j++){
                if(P[j] == depart[k]){
                    cpt ++;
                }
            }
        if(depart[k]<25){
            if(cpt<=2){
                posable = 1;
            }
            else{
                posable =0;
            }
        }
        else{
            if(cpt<=1){
                posable = 1;
            }
            else{
                posable = 0;
            }
        }
        
    }
}
//4)


*/



// EXERCICE 7

void allocation_2d(int ***t, int n){
    *t= malloc(n*sizeof(int*));
    for(int i = 0; i<n;i++){
        (*t)[i] = malloc(n*sizeof(int));
    }
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            (*t)[i][j] = 0;
        }
    }
    
}

void afficher(int **t, int n){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int est_diagonale(int **t, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i != j){
                if(t[i][j] != 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

//3)
void liberation_2d(int ***t, int n){
    if(*t != NULL){
        for(int i = 0; i<n; i++){
            free((*t)[i]);
        }
        free(*t);
    }    
}

int main(){
    int **T = NULL;
    int tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    
    allocation_2d(&T, 3);
    afficher(T,3);
    if(est_diagonale(T,3)){
        printf("la metrice est diagonale\n");
    }
    else{
        printf("la matrice n est pa diagonale \n");
    }
    liberation_2d(&T,3);
    //afficher(T,3);
    return 0;
}

//2)

