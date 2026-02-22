#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
// ----------------------------------------------- DEMINEUR -------------------------------------------------


//PARTIE I°) ------------------------------------1. Exercice préliminaire--------------------------------
//1) ----------------FONCTION AJOUTER -------------------------------------------------------
void ajouter(int tab[],int n, int k)
{
    for(int i = 0; i < n; i++)
    {
        if(tab[i] == -1)
        {
            tab[i] = k;
        }
    }
}

//2) -----------------/FONCTION RETIRER ---------------------------------------------
int retirer(int tab[],int n)
{
    int tmp = tab[0];
    for(int i = 0 ; i < n-1; i++)
    {
        tab[i] = tab[i+1];
    }
    // tab[n-1] = -1;
    return tmp;
}


//PARTIE II° -------------------------------------------Démineur en mode texte-----------------------
//1) ----------------STRUCTURE CASE-----------------------
struct une_case
{
    int etat;
    int mines_adj;
    int mine_ou_non;
    int marque;
    int devo;
}; 

//2)-----------------GRILLE DEMINEUR STRUCTURE----------------------------
struct grille
{
    int l;
    int c;
    struct une_case t[256][256];
    int nb_mines;
    int nb_mines_dec;
};
struct file
{
    int l;
    int c;
    int x;
    int y;
    struct grille file[];
};

//3)--------------------------FONCTION CREER ---------------------------------------------
struct grille creer(int l, int c, int mines)
{
    srand(time(NULL));
    struct grille g;
    g.l = l;
    g.c = c;
    g.nb_mines = mines;
    int mines_faits = 0;
    int alea_i;
    int alea_j;


    //initialisation
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            g.t[i][j].etat = 0;
            g.t[i][j].mines_adj = 0;
            g.t[i][j].mine_ou_non = 0;
            g.t[i][j].marque = 0;
            g.t[i][j].devo = 0;
        }
    }


    // PLACEMENT ALEATOIRE
    while(mines_faits < g.nb_mines)
    {
        alea_i = rand() % l;
        alea_j = rand() % c;
        if(g.t[alea_i][alea_j].mine_ou_non ==0)
        {
            g.t[alea_i][alea_j].mine_ou_non = 1;
            mines_faits += 1;
         
    

    // - MISE A JOUR ADJACENTES
            for(int i = alea_i-1; i <= alea_i+1; i ++)
            {
                for(int j = alea_j-1; j <= alea_j+1; j++)
                {  
                    if(i >= 0 && i< l && j >=0 && j< c)
                    {
                        g.t[i][j].mines_adj += 1;
                    }
                }
            }
        }
    }
    return g;
}

//4)------------------FONCTION AFFICHER ---------------------------------------
//void afficher(struct grille g, int l, int c)
//{
//    g.l = l;
//    g.c = c;
//    for(int i = 0; i < l; i ++)
//    {
//        for(int j = 0; j < c; j++)
//        {
//            if(g.t[i][j].devo == 0)
//            {
//                if(g.t[i][j].marque == 0)
//                {
//                    printf("X");
//                }
//                else
//                {
//                    printf("F");
//                }
//            }
//            else
//            {
//                if(g.t[i][j].mines_adj == 0)
//                {
//                    printf(" ");
//                }
//                else
//                {
//                    printf("%d", g.t[i][j].mines_adj);
//                }
//            }
//        
//        }
//        printf("\n");
//    }

//}
void afficher(struct grille g, int l, int c) {
    printf("Test d'affichage de la grille\n");
    printf("Dimensions : %d x %d\n", l, c);
}



//--6) --------------------------FONCTION DEVOILER CASE VIDE -------------------------
//void devoiler_case_vide(struct grille g, int x, int y)
//{
//    if(g.t[x][y].devo == 1)
//    return;

//    else
//    {
//        g.t[x][y].devo = 1;
//        if(g.t[x][y].mine_ou_non == 1)
//        {
//            printf("PERDU LE JEU S'ARRETE \n");
//            return;
//        }
//        else
//        if(g.t[x][y].mines_adj > 0)
//        {
//            g.t[x][y].devo = 1;
            
//        }
        
//    }
//}

void devoiler_case(struct grille *g, int x, int y) {
    // Vérifier les limites de la grille
    if (x < 0 || x >= g->l || y < 0 || y >= g->c) {
        return;  // Hors de la grille
    }

    // Si la case est déjà dévoilée ou marquée d'un drapeau, on ne fait rien
    if (g->t[x][y].devo || g->t[x][y].marque) {
        return;
    }

    // Vérifier si la case contient une mine
    if (g->t[x][y].mine_ou_non) {
        printf("Vous avez découvert une mine ! Vous avez perdu.\n");
        return;  // Arrêter le jeu ici ou définir un indicateur de fin de partie
    }

    // Dévoiler la case
    g->t[x][y].devo = 1;

    // Si la case contient des mines adjacentes, afficher le nombre de mines et arrêter la récursion
    if (g->t[x][y].mines_adj > 0) {
        return;
    }

    // Si la case est vide (sans mines adjacentes), continuer la récursivité sur les cases adjacentes
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if ((i != x || j != y) && i >= 0 && i < g->l && j >= 0 && j < g->c) {
                devoiler_case(g, i, j);  // Appel récursif pour les cases adjacentes
            }
        }
    }
}

//7) --------------------------

int main() {
    struct grille g = creer(3, 3, 1); // Essayez avec une grille plus petite
    printf("Grille créée avec dimensions : %d x %d\n", g.l, g.c);

    afficher(g, g.l, g.c); // Appel de `afficher`
    return 0;
}

 
