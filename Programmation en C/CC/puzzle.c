#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//------------ I - MODELISATION DES PIECES ET DE LA GRILLE-----------------

//1)

struct piece{
    int **tab;
    int l,h;
    int couleur;
    int x,y;
};

struct grille{
    int k;
    int n,m;
    struct piece **piece;
    int **t;
};

//2) 
// Créer pièce

struct piece *creer_piece(int x, int y, int l, int h,int couleur){
    struct piece *p = NULL;
    p = (struct piece*)malloc(sizeof(struct piece));
    p->tab = (int **)malloc(h*sizeof(int*));
    if(p->tab != NULL){
        for(int i = 0; i < h; i++){
            p->tab[i] = (int*)malloc(l*sizeof(int));
        }
    }
    
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            p->tab[i][j] = 0;
        }
    }
        
    p->x = x, p->y = y, p->l = l; p->h = h, p->couleur = couleur;
    return p;
    
}
// Detruire pièce

void detruire_piece(struct piece *p){
    if(p != NULL){
        for(int i = 0; i<p->h; i++){
            free(p->tab[i]);
        }
        free(p->tab);
        free(p);
    }
}

//3)

struct grille *creer_grille(int n, int m, int k){
    struct grille *g = NULL;
    g->k = k;
    g->n = n;
    g->m = m;
    g = (struct grille*)malloc(sizeof(struct grille));
    g->t = (int**)malloc(n*sizeof(int*));
    if(g->t != NULL){
        for(int i = 0; i<n; i++){
            g->t[i] = (int*)malloc(m*sizeof(int*));
            for(int j = 0; j<m; j++){
                g->t[i][j] = -1;
            }
        }
    }
    g->piece = (struct piece**)malloc(k*sizeof(struct piece*));
    for(int i = 0; i<k; i++){
        g->piece[i] = NULL;
    }
    
    return g;

}

//4)

void detruire_grille(struct grille *g){
    if(g!= NULL){
        if(g->piece != NULL){
            for(int i = 0; i<g->k; i++){
                detruire_piece(g->piece[i]);
            }
            free(g->piece);
        }
        if(g->t != NULL){
            for(int i = 0; i<g->n;i++){
                free(g->t[i]);
            }
            free(g->t);
        }
    }
    free(g);
}

//------------------------- 2 - CHARGEMENT ET AFFICHAGE TEXTE DU PUZZLE-----------------------------

//1)
struct grille *charger_puzzle(char *nom){
    int n,m,k,i=0,tmp = 0;
    int x,y,couleur,l,h;
    int *tp = NULL;
    struct grille *g= NULL;
    FILE* fic = fopen(nom, "r");
    if(fic != NULL){
        fscanf(fic,"%d",&n);
        fscanf(fic,"%d",&m);
        fscanf(fic,"%d",&k);
        g = creer_grille(n,m,k);
        while(i<k){
            fscanf(fic,"%d",&l);
            fscanf(fic,"%d",&h);
            for(int j = 0; j<l*h; j++){
                tp = (int*)malloc((l*h)*sizeof(int));
            }
                if(tp != NULL){
                    fscanf(fic,"%d",&tp[i]);
            fscanf(fic, "%d",&couleur);
            
            g->piece[i] = creer_piece(-1,-1,l,h,couleur);
            for(int i1 = 0; i1<h; i1++){
                for(int j1 = 0; j1<l;j1++){
                        g->piece[i]->tab[i1][j1] = tp[i1*l + j1];
                        }
                    }
                
            }
            
            
            i++;
        }
    }
    
    return g;
}

//--- PROGRAMME PRINCIPAL

int main(){

    return 0;
}