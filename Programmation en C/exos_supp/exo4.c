#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// Ecrire un programme qui vérifie si une grille 9×9 de Sudoku est valide :
//Chaque ligne contient des entiers entre 1 et 9, sans doublons.
//Chaque colonne contient aussi des entiers entre 1 et 9, sans doublons.

int ligneValide(int grille[9][9], int i){
    for(int k = 0; k < 9; k++){
        for(int j = 0; j < 9; j++){
            if(k!= j){
                if(grille[i][j] == grille[i][k]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int colonneValide(int grille[9][9], int i){
    for(int k = 0; k < 9; k++){
        for(int j = 0; j < 9; j++){
            if(k!= j){
                if(grille[j][i] == grille[k][i]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int sudokuValide(int grille[9][9]){
    for(int i = 0; i < 9; i++){
        if(colonneValide(grille,i) == 0 || ligneValide(grille,i) == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int s1[9][9] = {{5,3,4,6,7,8,9,1,2},{6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,9}
    };

    int s2[9][9] = {{3,3,4,6,7,8,9,1,2}, // <- doublon '3' dans la ligne
    {6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,9}
    };
    int s3[9][9] = {
    {8,2,7,1,5,4,3,9,6},
    {9,6,5,3,2,7,1,4,8},
    {3,4,1,6,8,9,7,5,2},
    {5,9,3,4,6,8,2,7,1},
    {4,7,2,5,1,3,6,8,9},
    {6,1,8,9,7,2,4,3,5},
    {7,8,6,2,3,5,9,1,4},
    {1,5,4,7,9,6,8,2,3},
    {2,3,9,8,4,1,5,6,7}
    };

    int s4[9][9] = {
    {4,1,7,3,6,9,8,2,5},
    {6,3,2,1,5,8,9,4,7},
    {9,5,8,7,2,4,3,1,6},
    {8,2,5,4,3,7,1,6,9},
    {7,9,1,5,8,6,2,3,4},
    {3,4,6,9,1,2,7,5,8},
    {2,8,9,6,7,5,4,9,1}, // erreur volontaire : doublon '9' dans la ligne
    {1,7,4,2,9,3,6,8,5},
    {5,6,3,8,4,1,9,7,2}
    };
    int s5[9][9] = {
    {2,9,5,7,4,3,8,6,1},
    {4,3,1,8,6,5,9,2,7},
    {8,7,6,1,9,2,5,4,3},
    {3,8,7,4,5,9,2,1,6},
    {6,1,2,3,8,7,4,9,5},
    {5,4,9,2,1,6,7,3,8},
    {7,6,3,5,2,4,1,8,9},
    {9,2,8,6,7,1,3,5,4},
    {1,5,4,9,3,8,6,7,2}
    };

    int s6[9][9] = {
    {5,3,4,6,7,8,9,1,2},
    {6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,1} // doublon '1' dans le dernier bloc 3x3
    };



    int v1 = sudokuValide(s1);
    int v2 = sudokuValide(s2);
    int v3 = sudokuValide(s3);
    int v4 = sudokuValide(s4);
    int v5 = sudokuValide(s5);
    int v6 = sudokuValide(s6);

    if(v1 == 1){
        printf("sudoku 1 valide \n");
    }
    else{
        printf("sudoku 1 invalide\n");
    }

    if(v2 ==1){
        printf("sudoku 2 valide \n");
    }
    else{
        printf("sudoku 2 invalide \n");
    }

    if(v3 ==1){
        printf("sudoku 3 valide \n");
    }
    else{
        printf("sudoku 3 invalide \n");
    }

    if(v4 ==1){
        printf("sudoku 4 valide \n");
    }
    else{
        printf("sudoku 4 invalide \n");
    }

    if(v5 ==1){
        printf("sudoku 5 valide \n");
    }
    else{
        printf("sudoku 5 invalide \n");
    }

    return 0;
}