#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 
struct capteur{
    float temperateure;
    int actif;
};


void initialiser_grille(struct capteur g[20][20], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            g[i][j].temperateure = (rand() % 50 ) - 10;
            g[i][j].actif = rand()%2;
        }
    }
}

void affichage(struct capteur g[20][20], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j].actif == 1 ){
                printf("%d  ");
            }
            else{
                printf("--  ");
            }
        }
        printf("\n");
    }
}

float temperatureMoyenne(struct capteur g[20][20], int n){
    int somme = 0;
    for(int i =0; i<n;i++){
        for(int j = 0; j<n;j++){
            if()
        }
    }
}

int main(){

    return 0;
}