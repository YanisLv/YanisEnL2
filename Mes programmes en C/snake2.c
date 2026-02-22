#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#define WindowsXP _WIN32_WINNT_WINXP
#define MAX(X, Y) ((X > Y) ? (X) : (Y))
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

// -----------------------------------------------------------------------------
#define SIZE_X 60
#define SIZE_Y 30
#define M_SIZE_X_Y MAX(SIZE_X, SIZE_Y)
#define X      5
#define Y      5

#define LENGTH            4
#define NB_POMMES         20
#define NB_OBSTACLES      6
#define SIZE_MAX_OBSTACLE 10

#define NORTH  1
#define EAST   2
#define SOUTH  4
#define WEST   8
//1
struct position
{
    short x,y;
};


//2
void initialiser(struct position T[], int n)
{
    int i = 0;
    for(int i = 0; i < n; i ++)
    {
        T[i].x = -1;
        T[i].y = -1;
    }
}

//3
void ajouter(struct position T[], int n, struct position p)
{
    for(int i = 0; i < n; i ++)
    {
        if(T[i].y != -1 && T[i].y != -1)
        {
            T[i+1].x = p.x;
            T[i+1].y = p.y;
        } 
    }
}

// 4
void retirer(struct position T[], int n)
    {   
        int tmp;
        T[tmp].x = T[0].x;
        T[tmp].y = T[0].y;
        for(int i = 0; i< n-1; i++)
        {
            T[i].x = T[i+1].x;
            T[i].y = T[i+1].y;
        }
    return (T[tmp].x, T[tmp].y);
    }
    

//5
void appartient(struct position T[], int n,struct position p)
{
    for(int i = 0; i<n; i++)
    {
        if(T[i].x == p.x && T[i].y == p.y)
        {
            return i;
        }
        else
        return -1;
    }
}
// ----------------------------------------------------------------------------------//
            //          2. Manipulation de la grille de jeu         //

//1
struct serpent
{
    struct position T[SIZE_X*SIZE_Y];
    int longueur;
    int direction;
};

//2

struct serpent creer_serpent(struct position P, int L, int D)
{
    struct serpent serpent;
    L = serpent.longueur;
    D = serpent.direction;
    initialiser(serpent.T, SIZE_X*SIZE_X);
    
    struct position H = P;
    if(D == NORTH)
    {
        H.y = MIN(H.y + (L-1), SIZE_Y-1);
    }
    else if(D == SOUTH)
    H.y = MAX(H.y - (L-1), 0);
  else if(D == EAST)
    H.x = MAX(H.x - (L-1), 0);
  else if(D == WEST)
    H.x = MIN(H.x + (L-1), SIZE_X - 1);
  
  for(int i = 0; i < L; i++) {
    ajouter(serpent.T, SIZE_X*SIZE_Y, H);
    if(D == NORTH)
      H.y = H.y - 1;
    else if(D == SOUTH)
      H.y = H.y + 1;
    else if(D == EAST)
      H.x = H.x + 1;
    else if(D == WEST)
      H.x = H.x - 1;
  }
  return serpent;
}

// 3) ----------------------------------AFFICHER GRILLE------------------------------------

void afficher_grille(struct serpent s, struct position p)
{  
    //---------- INITIALISATION DE LA GRILLE-----------//
    char grille[SIZE_X][SIZE_Y];
    for(int i = 0; i < SIZE_X; i++)
    {
        for(int j = 0; j < SIZE_Y; j++)
        {
            grille[i][j] = ".";                                
        }
    }

   // ------------ PLACER SERPENT DANS LA GRILLE -------------//

    for(int i = 0; i < s.longueur -1; i ++)
    {
        int x = s.T[i].x;
        int y = s.T[i].y;

        if(x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
        {
            grille[x][y] = "o";
        }
    }

    //------------trouver tête serpent ----------//

    int tete_x = s.T[s.direction - 1].x;
    int tete_y =s.T[s.direction - 1].y;


    //--------PLACER TETE SERPENT-----------------//
    if(tete_x >= 0 && tete_x < SIZE_X && tete_y >= 0 && tete_x < SIZE_Y)
    {
        grille[tete_x][tete_y] = 'O';
    }
    // -----------AFFICHER GRILLLEEE FINALE ----------
    for(int i = 0; i < SIZE_X; i++)
    {
        for(int j = 0; i< SIZE_Y; j ++)
        {
            printf("%c", grille[i][j]);
        }
        printf("\n");
    }

}


// 4) ---------------------------------FONCTION AVANCER -------------------------------------


void avancer(struct serpent *s)
{
    
    struct position nvltete = s->T[s->longueur-1];
    switch(s->direction)
    {
        case NORTH:
            nvltete.y -=1;
        case SOUTH:
            nvltete.y +=1;
            break;
        case EAST:
            nvltete.x += 1;
            break;
        case WEST:
            nvltete.x -= 1;
            break;
    }
    ajouter(s->T, SIZE_X*SIZE_X, nvltete);
    retirer(s->T, SIZE_X* SIZE_Y);    
}


// 5) ---------------------------- FONCTION CHANGER DIRECTION -------------------------------

void changer_direction(int D, struct serpent *s)
{
    struct serpent *serpent;
    struct serpent *direction_actuelle = s->direction;
    if((D==NORTH && s->direction == SOUTH) ||
    (D == SOUTH && s->direction == SOUTH) ||
    (D == EAST && s->direction == WEST)||
    (D == WEST && s->direction ==EAST))
    {
        return;
    }      
    else
    {
        s->direction = D;

    }
}


// 6) ------------------------------------- CREER DES POMMES 🍎 ---------------------------------
void creer_pommes(struct position T[])
{
    // ------INITIALISATION------
    srand(time(NULL));

    //--------stocker pommes--------
    for(int i = 0; i < 20; i++)
    {
        T[i].x = rand() % (SIZE_X);
        T[i].y = rand() % (SIZE_Y);
    }
}

// 7) ---------------------------------------- MANGER !!🍕😋----------------------------------



void creer_pomme(struct position T[], int index) {
    T[index].x = rand() % SIZE_X;
    T[index].y = rand() % SIZE_Y;

}

int manger(struct position T[], struct position tete) 
{
    // Parcourir le tableau de pommes
    for (int i = 0; i < NB_POMMES; i++) 
    {
        // Si la tête du serpent est sur une pomme
        if (T[i].x == tete.x && T[i].y == tete.y) 
        {
            // Créer une nouvelle pomme pour remplacer celle qui a été mangée
            creer_pomme(T, i);
        }
            // Retourner 1 pour indiquer que le serpent a mangé une pomme
            return 1;
    }
}

// 8) --------------------------------- FONCTION REDIMENSIONNER ---------------------------------
struct serpent redimensionner_serpent(struct serpent s)
{
    s.longueur += 1;
    return s;
}
// 9) ---------------------------- structure obstacle --------------------------------------------

struct obstacle
{
    struct position O[10];
    int longueur;
    int direction;
};


// 10) ---------------------------------creer_obstacle--------------------------------------
struct obstacle creer_obstacle(struct position p, int L, int D)
{
    struct obstacle o;
    o.longueur = L;
    o.direction = D;
    for(int i = 0; i < L; i++)
    {   
        o.O[i];
        switch(D)
        {
            case EAST:
                //instruct;
                p.x+=1;
                break;
            case WEST:
                //instruct;
                p.x -= 1;
                break;
            case NORTH:
                // instruct;
                p.y += 1;
                break;
            case SOUTH:
                // instruct;
                p.y -= 1;
                break;
         }   
   }

   return o;
}

//-----------CREER DES OBSTACLES -----------

void creer_obstacles(struct obstacle o[])
{
    struct position p; // position départ 
    srand(time(NULL));
    int hasard_L = rand() % 6;
    int hasard_D = 1 + rand()%(1 - 4 + 1);
    p.x = rand() % SIZE_X; // Position x aléatoire entre 0 et SIZE_X - 1
    p.y = rand() % SIZE_Y;
    for(int i = 0; i < 6; i++)
    {
        int hasard_L = rand() % 6;
        int hasard_D = 1 + rand()%(1 - 4 + 1);
        o[i] = creer_obstacle(p,hasard_L,hasard_L);    
    }
}

// 11) ----------------------------------------PERCUTER مسكين------------------------------------------

int percuter(struct obstacle o[], struct serpent s)
{
    for (int i = 0; i < 6; i++) {
        struct position pos_obstacle = o[i].O; // Position de départ de l'obstacle

    struct position tete = s.T[s.longueur-1];
    for(int i = 0; i < SIZE_X*SIZE_Y; i++)
    {
        if(o.O[i].x && tete.x && o.O[i].y && tete.y)
        {
        return 1;
        }
    }
    return 0;
}

// --------------III) ---------------------Snake en mode graphique----------------------------------/

