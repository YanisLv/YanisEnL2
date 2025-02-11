//----------------------------------FLOOD-IT----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 30
#define MAX_C  6

#define RESET_ALL    "\x1b[0m"

#define BLACK        "\x1b[30m"
#define RED          "\x1b[31m"
#define GREEN        "\x1b[32m"
#define YELLOW       "\x1b[33m"
#define BLUE         "\x1b[34m"
#define MAGENTA      "\x1b[35m"
#define CYAN         "\x1b[36m"
#define WHITE        "\x1b[37m"


//1) ----------------------------- STRUCTURE CELLULE-------------------------------------
struct  cellule
{
    char couleur;
    char traitee;
};

//structure grille
struct grille
{
    struct cellule grille[MAX_N][MAX_N];
    int N, C;
};

//2)----------------------------FONCTION REMPLIR GRILLE ----------------------------------
void remplir_grille(int N, int C)
{
    srand(time(NULL));
    struct grille grille;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; i < N; i++)
        {
            grille.grille[i][j].couleur = rand() % MAX_C-1;
            grille.grille[i][j].traitee = 0;
        }
    }
}

//3) ---------------------------------FONCTION AFFICHER GRILLE -----------------------------------
void afficher_grille(struct grille grille)
{
    for(int i = 0; i < MAX_N; i++)
    {
        for(int j = 0; j < MAX_N; i++)
        {
            switch(grille.grille[i][j].couleur)
            {
                case 0:
                    printf("\x1b[30mNOIR\x1b[0m");
                    break;
                case 1:
                    printf("\x1b[31mROUGE\x1b[0m");
                    break;
                case 2:
                    printf("\x1b[32mVERT\x1b[0m");
                    break;
                case 3:
                    printf("\x1b[33mJAUNE\x1b[0m");
                    break;
                case 4:
                    printf("\x1b[33mJAUNE\x1b[0m");
                    break;
                case 5:
                    printf("\x1b[35mMAGENTA\x1b[0m");
                    break;
                case 6:
                    printf("\x1b[36mCYAN\x1b[0m");
                    break;
                default:
                    printf("\x1b[37mBLANC\x1b[0m");
                    break;
            }
            //printf("%d", grille.grille[i][j]);
        }
    printf("\n");
    }
}

//) II ) -------------------------------Flood It en mode interactif------------------------------

//1) ---------------------------------STRUCTURE POSITION----------------------------------------------

struct position
{
    int l;
    int c;
};

// 2)------------------------------------FONCTION INITIALISER-------------------------------------
//---- STRUCTURE TABLEAU (????)----

//struct tableau
//{
//    struct position T[MAX_N*MAX_N];
//    int V;
//    int I;
//};

//----- FONCTION INITAILISER-----
void initialiser(struct position p[MAX_N*MAX_N])
{
    for(int i = 0; i < MAX_N* MAX_N; i++)
    {
        p[i].l = -1;
        p[i].c = -1;
    }
}


// 3) ------------------------FONCTION AJOUTER  ------------------------------------------------
void ajouter(struct position p[MAX_N*MAX_N], struct position a)
{
    int existe_pas = 0;
    for(int i = 0; i < MAX_N; i ++)
    {
        if(p[i].c != a.c && p[i].l != a.l)
        {
            existe_pas = 1;
        }
    }
    if(existe_pas ==1)
    {
        for(int i = 0; i < MAX_N* MAX_N; i++)
        {           
            if(p[i].c == -1 && p[i].l == -1)
            {
                p[i-1].c = a.c;
                p[i-1].l = a.l;
            }
        }
    }
}

//4) ---------------------------------FONCTION RETIRER -------------------------------------------------
struct position retirer(struct position p[MAX_N*MAX_N])
{
    struct position tmp ={p[0].c, p[0].l};

    for(int i = 0; i < (MAX_N*MAX_N)-1; i++)
    {
        p[i].c = p[i+1].c;
        p[i].l = p[i+1].l;
    }
    return tmp;
}

//5) ----------------------------------FONCTION AFFICHER-------------------------------------------
void afficher(struct position p[MAX_N*MAX_N])
{
    for(int i = 0; i < MAX_N*MAX_N; i++)
    {
        if(p[i].c != -1 && p[i].l != -1)
        {
            printf("%d %d ->", p[i].l, p[i].c);
        }
    }
}

//6) -------------------------------MODIFIER COULEUR ----------------------------------------------

struct grille modifier_couleur(char C,struct grille G)
{
    //
    struct position p[MAX_N*MAX_N];
    struct position tmp;
    int couleur_orignale = G.grille[0][0].couleur, i, j;
    if(C != couleur_orignale)
    {
        initialiser(p);
        ajouter(p,p[0]);
        while(p[0].c != -1 && p[0].l != -1)
        {
            tmp = retirer(p);
            if(G.grille[tmp.l][tmp.c].traitee == 0 && G.grille[tmp.l][tmp.c].couleur == couleur_orignale)
            {
                G.grille[tmp.l][tmp.c].traitee = 1;
                G.grille[tmp.l][tmp.c].couleur = C;
                if(tmp.l != 0)
                    tmp.l = tmp.l-1;
	                ajouter(p, tmp);
	            if(tmp.l != G.N-1)
                    tmp.l = tmp.l+1;
	                ajouter(p,tmp);
	            if(tmp.c != 0)
                    tmp.l = tmp.l-1;
	                ajouter(p, tmp);
	            if(tmp.c != G.N-1)
                    tmp.l = tmp.l+1;
	                ajouter(p,tmp);
            }
        }
    }
    for(i = 0; i < G.N; i++)
        for(j = 0; j < G.N; j++)
        G.grille[i][j].traitee = 0;
  return G;
}


//)8)= ----------------------------------FONCTION TAILLE REGION ADJACENTE ----------------------------------

int taille_region_adjacente(struct grille G)
{
    struct position tmp;
    struct position T[MAX_N*MAX_N];
    int n = 0;
    int i,j;
    tmp = retirer(T);
    while(T[0].l != -1 && T[0].c != -1)
    {
        tmp = retirer(T);
        if(G.grille[tmp.l][tmp.c].traitee == 0 && G.grille[tmp.l][tmp.c].couleur == G.grille[0][0].couleur)
            {
                G.grille[tmp.l][tmp.c].traitee = 1;
                n+=1;
            }
        if(tmp.l !=0)
        {
            tmp.l = tmp.l-1;
            ajouter(T,tmp);
        }
        if(tmp.l != G.N-1)
        {
            tmp.l = tmp.l+1;
            ajouter(T,tmp);
        }
        if(tmp.c !=0)
        {
            tmp.c = tmp.c -1;
            ajouter(T,tmp);
        }
        if(tmp.c != G.N-1)
        {
            ajouter(T,tmp);
        }
    for(i = 0; i < G.N; i++)
        for(j = 0; j < G.N; j++)
            G.grille[i][j].traitee = 0;
    
}
    return n;
}

//8) -------------------------- JOUER FLOUD IT -----------------------------------------------------
void jouer_floodit(struct grille G, int K)
    {
        int choix;
        int nb_coup=0;
        int taille = 0;
        printf("-------------------------VOUS JOUEZ A FLOODIT. ACTIVISON © ---------------------------\n");
        do
        {
            afficher_grille(G);
            printf("Entrez unr couleur %d ou %d pour quitter \n", G.C-1, G.C);
            scanf("%d", &choix);
            if(choix!= G.C)
            {
                G = modifier_couleur(G.C,G);
    
                taille = taille_region_adjacente(G);
            }
            nb_coup +=1;
        }while(nb_coup < K && taille < G.N* G.N && choix != G.C);
        if(choix == G.C)
        {
            printf("vous avre quiité\n");    
        }
        else if(nb_coup==K)
        {
            printf("vous avez usé de vos coups\n");
        }
        else
        {
            printf("Bravo vous avre gagné en %d coups \n",nb_coup);
            afficher_grille(G);
        }
    }



//III - -------------------------------------------------------------------------------------
//1)-----------------------------------------------------------
void calculer_frontiere(struct grille G, struct position frontiere[MAX_N*MAX_N])
{
    int nb_coup = 0;
    struct position tmp;
    struct position t[MAX_N*MAX_N];
    initialiser(t);
    initialiser(frontiere);
    while(t[0].l != -1 && t[0].c != -1)
    {
        tmp = retirer(t);
        if(G.grille[tmp.l][tmp.c].traitee == 0)
        {
            if(G.grille[tmp.l][tmp.c].couleur == G.grille[0][0].couleur)
            {
                G.grille[tmp.l][tmp.c].traitee = 1;
                if(tmp.l != 0)
                    tmp.l = tmp.l-1;
	                ajouter(t, tmp);
	            if(tmp.l != G.N-1)
                    tmp.l = tmp.l+1;
	                ajouter(t, tmp);
	            if(tmp.c != 0)
                    tmp.c = tmp.c-1;
	                ajouter(t, tmp);
	            if(tmp.c != G.N-1)
                    tmp.c = tmp.c+1;
	                ajouter(t, tmp);
            }
            else
            {
                G.grille[tmp.l][tmp.c].traitee = 1;
	            ajouter(frontiere, tmp);
            }
            
        }
    for(int i = 0; i < G.N; i++)
        for(int j = 0; j < G.N; j++)
            G.grille[i][j].traitee = 0;
    
}
