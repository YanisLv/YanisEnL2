#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<ncurses>

//-------------- 1 - CREATION ET AFFICHAGE DE LA GRILLE ---------------------

//1)

struct cellule{
    int couleur;
    int traitee;
};

struct grille{
    int taille;
    struct cellule tab[30][30];
    int nb_couleur;
};

//2)

struct grille remplir_grille(int n, int nb){
    struct grille g;
    if(nb<=6){
    
    
        g.nb_couleur = nb;
        g.taille = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g.tab[i][j].couleur = rand() % nb + 1;
                g.tab[i][j].traitee = 0;
            }
        }
    }
    else{
        printf("ERREUR GRILLE CAR COULEUR > 6");
    }
    return g;
}

//3

void afficher_grille(struct grille g){

    int n = g.taille;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            switch(g.tab[i][j].couleur){
                case 1:
                    printf("\x1b[30mNOIR\x1b[0m");
                    break;
                case 2:
                    printf("\x1b[31mROUGE\x1b[0m");
                        break;
                case 3:
                    printf("\x1b[32mVERT\x1b[0m");
                    break;
                case 4:
                    printf("\x1b[33mJAUNE\x1b[0m");
                    break;
                case 5:
                    printf("\x1b[34mBLEU\x1b[0m");
                    break;
                case 6:
                    printf("\x1b[35mMAGENTA\x1b[0m");
                    break;
            }
        }
        printf("\n");
    }
}


// --------------------------2. FLOOD IT EN MODE INTERACTIF ---------------------

//1)

struct position{
    int l;
    int c;
};

//2)

void initialiser(struct position *t){

    for(int i = 0; i < 900; i++){
        t[i].l = -1;
        t[i].c =- 1;
    }
}

//3)

void ajouter(struct position *t, struct position pos){

    int i = 0;
    while((t[i].c != -1 && t[i].l != -1) && i< 900){
        i++;
    }
    t[i].l = pos.l;
    t[i].c = pos.c;
} 

//4)
struct position retirer(struct position *t){
    struct position ret;
    ret.l = t[0].l;
    ret.c = t[0].c;

    for(int i = 0; i < 900-1; i++){
        t[i].l = t[i+1].l;
        t[i].c = t[i+1].c;
    }

    return ret;
}

//5)

void afficher(struct position *t){
    int i = 0;
    while(t[i].l != -1|| t[i].c != -1){
        if(t[i+1].l == '\0' ||t[i+1].l ==-1){
            printf("(%d, %d)\n", t[i].l, t[i].c);
        }
        else{
            printf("(%d, %d),", t[i].l, t[i].c);
        }
        i++;
    }
}

//6)

void modifier_couleur(struct grille g, int couleur){
    struct position *tab;
    g.tab[0][0].traitee = 1;
    g.tab[0][0].couleur = couleur;

    tab[0].l  = 0;
    tab[0].c = 0;
    struct position tmp;
    struct position adj;
    int i = 0;
    while(tab[i].l != -1 && tab[i].c != -1){
        tmp = retirer(tab);
        g.tab[tmp.l][tmp.c].couleur = couleur;
        g.tab[tmp.l][tmp.c].traitee = 1;

        for(int k = tmp.l-1; k <=tmp.l + 1; k++){
            for(int j = tmp.c-1; j <= tmp.c + 1; j++){
                if(g.tab[k][j].couleur == g.tab[tmp.l][tmp.c].couleur){
                    adj.l = k, adj.c = j;
                    ajouter(tab,adj);
                }
            }
        }
        i++;
    }

}0

//7)

int taille_region_adjacente(struct grille g){
    int cpt = 0;
    int n = g.taille;

    int i = 0;
    int j = 0;
    while(i < n && j <)

    
}


// -------- PROGRAMME PRINCIPAL -------------
int main(){
    srand(time(NULL));
    struct grille grid = remplir_grille(6,4);
    afficher_grille(grid);
    
    struct position p[900];
    initialiser(p);
    struct position p1, p2, p3, p4;
    p1.l = 5, p1.c= 2;
    p2.l = 1, p2.c = 0;
    p3.l = 8, p3.c = 9;
    p4.l = 4, p4.c = 3;

    ajouter(p,p1);
    ajouter(p,p2);
    ajouter(p,p3);
    ajouter(p,p4);

    afficher(p);

    return 0;
}