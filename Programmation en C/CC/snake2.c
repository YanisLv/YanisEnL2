#include<stdio.h>
#include<stdlib.h>
//#include<ncurses>

// --------- 1. MANIPULATION DES COORDONNES -------//

//1)
struct position{
    int x,y;
};

//2)
void initialiser(struct position *t, int n){

    for(int i = 0; i < n; i++){
        t[i].x = -1;
        t[i].y = -1;
    }
}

//3)

void ajouter(struct position *t, struct position p, int n){
    int i = 0;
    while(i < n && t[i].x != -1){
        i++;
    }
    if(t[i].x == -1){
        t[i].x = p.x;
        t[i].y = p.y;
    }   
}

//4)
struct position retirer(struct position *t, int n){
    struct position ret;
    ret.x = t[0].x;
    ret.y = t[0].y;

    for(int i = 0; i < n-1; i++){
        t[i].x = t[i+1].x;
        t[i].y = t[i+1].y;
    }
    t[n-1].x = -1;
    t[n-1].y = -1;
    return ret;
}


//5)
int appartient(struct position *t, struct position p, int n){
    
    int i = 0;
    for(int i = 0; i < n; i++){
        if(t[i].x == p.x && t[i].y == p.y){
            return i;
        }
    }
    return -1;
}

// ----------------------- 2. MANIPULATION DE LA GRILLE DE JEU------------------

//1)

struct serpent{
    struct position *file;
    char *direction;
    int longueur;
};

//2)
struct serpent creer_serpent(struct position tete, int longueur, char *direction, int l, int h){
    struct serpent snake;
    struct position tmp;
    snake.direction = direction;
    for(int i = 0; i < longueur-1; i++){
        tmp.x = tete.x;
        tmp.y = (tete.y - longueur + i + 1);
        ajouter(snake.file,tmp,l*h);
    }
    ajouter(snake.file, tete,l*h);
    return snake;
}

//3)
void afficher_grille(struct serpent snake, int l, int h){
    for(int i = 0; i < l; i++){
        printf("-");
    }
    printf("\n");
    for(int i = 0; i < l;i++){
        for(int j = 0 ; j< h; j++){
            for(int k = 0; k < snake.longueur; k++){
                if(snake.file[k].x == i && snake.file[k].y == j){
                    printf("s");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}


// MAIN ------------------------------- PROGRAMME PRINCIPAL-------------------
int main(){

    int t[7] = {2,1,4,8,9,7,5};
    for(int i = 0; i < 7-1; i++){
        t[i] = t[i+1];
    }
    t[6] = -1;
    for(int i = 0; i < 7; i++){
        printf("%d ", t[i]);
    }
    struct serpent s;
    struct position p[15] = {(1, 9),(1, 8),(1, 7),(1, 6),(2, 6)};
    s.file = p;
    s.longueur = 5;
    afficher_grille(s,10,10);

    return 0;
}