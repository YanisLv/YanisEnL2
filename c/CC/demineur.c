#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include <ncurses.h>
#include <unistd.h>
//---------1 - EXERCICE PRELIMINAIRE ----------

// 1)
void ajouter(int tab[255], int val){
    int i = 0;
    while(tab[i] != -1){
        i++;
    }
    tab[i] = val;
}

//2
int retirer(int tab[255]){
    int ret = tab[0];
    if(ret == -1){
        return -1;
    }
    int i = 0;
    while(tab[i+1] != -1){
        tab[i] = tab[i+1];
        i++;
    }
    tab[i] = -1;
    return ret;
}

//------------------- 2 - Démineur en mode texte ---------------

//1

struct Case{
    char etat;
    int nb_mines_adj;
    int mine_ou_non;
};


//2

struct grille{
    int dim_x;
    int dim_y;
    struct Case tab[50][50];
    int nb_mines;
    int nb_mines_dec;
};

//3

struct grille creer(int x, int y, int nb_total) {
    struct grille g;
    g.dim_x = x;
    g.dim_y = y;
    g.nb_mines = nb_total;
    g.nb_mines_dec = 0;

    // Initialisation 
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            g.tab[i][j].etat = 'X';
            g.tab[i][j].mine_ou_non = 0;
            g.tab[i][j].nb_mines_adj = 0;
        }
    }

    // Placement aléatoire des mines
    int tmp_x, tmp_y, place = 0;
    while (place < nb_total) {
        tmp_x = rand() % x;
        tmp_y = rand() % y;

        if (g.tab[tmp_x][tmp_y].mine_ou_non == 0) {
            g.tab[tmp_x][tmp_y].mine_ou_non = 1;
            printf("Mine placée en (%d, %d)\n", tmp_x, tmp_y);

            place++;
        }
    }

    //  mines adjacentes
    for(int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (g.tab[i][j].mine_ou_non == 1) {
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int m = j - 1; m <= j + 1; m++) {
                        if(k >= 0 && k < x && m >= 0 && m < y && !(k == i && m == j)) {
                            g.tab[k][m].nb_mines_adj++;
                        }
                    }
                }
            }
        }
    }   
    return g;
}


//4

void afficher(struct grille g){
    int x = g.dim_x;
    int y = g.dim_y;
    
    printf("x = %d, y = %d\n", x, y);

    for(int i = 0; i<=y+1; i++){
        printf("#");
    }
    printf("\n");
    for(int i = 0; i< x; i++){
        printf("#");
        
        for(int j = 0; j< y; j++){
            if(g.tab[i][j].etat == 'X'){
                printf("X");
            }
            else{
                if(g.tab[i][j].etat == 'F'){
                    printf("F");
                }
                else{
                    if(g.tab[i][j].etat == ' '){
                        printf(" ");
                    }
                    else{
                        printf("%d",g.tab[i][j].nb_mines_adj);
                    }
                }
            }
        }
        printf("#\n");
        
    }
    
    for(int i = 0; i<=y+1; i++){
        printf("#");
    }
    
}

//6
/*
void devoiler_case_vide(struct grille *g, int x, int y){
    g->nb_mines_dec ++;
    if((g->tab[x][y].etat == 'X' || g->tab[x][y].etat == 'F')){
        if(g->tab[x][y].mine_ou_non == 0)
    }
}   
*/

//--------- PROGRAME MAIN PRINCIPAL ----------//
int main(){
    /* --------- IGNORER ------------
    int t[255] = {1, 3, 0, 2, 5, -1, -1, -1};

    for(int i = 0; i<8; i++){
        printf("%d; ", t[i]);
    }
    printf("\n");
    ajouter(t,17);
    for(int i = 0; i<8; i++){
        printf("%d; ", t[i]);
    }
    printf("\n");

    int a = retirer(t);
    for(int i = 0; i<8; i++){
        printf("%d; ", t[i]);
    }
    printf("\n");
    printf("%d",a);
    srand(time(NULL)); 
    */
    

    struct grille g1 = creer(10, 10, 6);
    printf("Grille créée avec succès !\n");
    afficher(g1);
    printf("\nFin du programme.\n");

    return 0;
}

