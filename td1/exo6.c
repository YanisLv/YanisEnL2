#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//definition de structure des noeuds 
#define N 20 
typedef struct Node {
    struct Node* left;
    struct Node* right;
    int info;
}Node;
//algo : n = le nombre de noeuds : creer un noeud affecter 1 er entier n au champs info de ce noeud 
//construire un arbre à gauche de ce noeuds dont le nombre de noeuds ng = n/2 (d'une maniére recursive)
//construire un arbre à droite de ce noeuds dont le nombre de noeuds nd = n-ng-1 (d'une maniére non recursive) 
typedef Node* lien;
//construire un arbre de n noeuds 
lien arbre(int n){
    if (n==0){// fais néant 
        return NULL;
    }
    int ng= n/2;
    int nd= n-ng -1;
    //lire un entier entré depuis le clavie
    int x;
    scanf("%d", &x);
    lien t= (Node*)malloc(sizeof(Node));
    t->info=x;
    t->left= arbre(ng);
    t->right = arbre(nd);
    return t;
}
void imprimer( lien r,int niveau){
    if (r!=NULL){
        //afficher l'indent niveau+1
        imprimer(r->right , niveau+1);
        //imprimer r avec indent niveau
        for (int i=0 ; i<niveau ; i++){
            printf("\t");
        }
        printf("--->");
        printf("%d\n", r->info);
        //afficher ag avec indent niveau +1
        imprimer(r->left, niveau+1);
    }
}
lien arbrep(int t[], int debut, int fin){
    //creer un arbre avec les entiers du tableau t[debut ...fin]
    //divide and conquer 
    if (debut>fin){
        return NULL; //condition terminal
    }
    int milieu = (debut+fin)/2;
    lien p = (Node*)malloc(sizeof(Node));
    p->info=t[milieu];
    p->left=arbrep(t, debut, milieu -1);
    p->right=arbrep(t, milieu +1 ,fin);
    return p;
}
int compare(const void *a , const void *b){
    return *(int*)a-*(int*)b;
}
//ecrire une petite fonction 
int hauteur(int t, int compteur){
    /* Base = a != NULL , h=-1*/
    /* Recursion : h=1 +max(h(ag),h(ad))*/
    int h=-1;
    
}
int main(){
    //river function 
    lien racine ;
    int x;
    int n; //n=ce nbr de noeud arbre parfaitement equilibré
    /*printf("entrez un entier pour n \n");
    scanf("%d", &n);
    racine = arbre(n);
    imprimer(racine,0); //niveau de racine =0*/
    int t[]={7,2,1,0,4,3,11,12,9,6,8,5,13 };
    //taille de tableau 
    //t
    n=sizeof(t)/sizeof(t[0]);
    
    //utiliser quicksort (comment l'appeler)
    //qsort(le nom de tableau, la taille du tableau, la taille d'un objet, la fonction de comparaison )
    qsort(t,n,sizeof(int), compare);
    //voir le tableau pour le croire voir le tableau
    for (int i=1 ; i<=n ; i++){
        printf("%d\n", t[i]);
    }
    lien r = arbrep(t,0,n-1);
    imprimer(r,0);
    return 0;
}