#include<stdio.h>
#include<stdlib.h>
//#include<ncurses>

// --------- 1. MANIPULATION DES COORDONNES -------//

//1)
struct position{
	int x;
	int y;
};

//2)

void initialiser(struct position tab[], int n) {

	for (int i = 0; i < n; i++) {
    	tab[i].x = -1;
    	tab[i].y = -1;
	}
}

//3
int compteur(struct position tab[100]){
	int i = 0;
	while(tab[i].x != '\0'){
    	i++;
	}
	return i;
}


void ajouter(struct position tab[100], struct position valide){
	int i = 0;
	int n = compteur(tab);
	while(i<n &&tab[i].x != -1){
    	i++;
	}
	if(tab[i].x == -1){
    	tab[i].x = valide.x;
    	tab[i].y = valide.y;
	}
}

//4

struct position retirer(struct position *tab){
	struct position ret;
	ret.x = tab[0].x;
	ret.y = tab[0].y;
    
	int i = 0;
	while(i != '\0'){
    	tab[i].x = tab[i+1].x;
    	tab[i].y = tab[i+1].y;
    	i++;
	}
    
	return ret;
}

//5
int appartient(struct position *tab, struct position valide){
	int i = 0;
	int n = compteur(tab);
	while(i < n && (tab[i].x != valide.x)){
    	i++;
	}
	if(tab[i].x == valide.x && tab[i].y == valide.y){
    	return i;
	}
	else{
    	return -1;
	}
}
//------------- 2 - MANIPULATION DES COORDONNES ---------------

//1)
struct serpent{
    struct postition[1800];
    char direction;
    int longueur;
};


//2)
struct serpent creer()



int main(){
	struct position t[100];
	initialiser(t,10);
	struct position valide;
	valide.x = 2;
	valide.y = 3;
	ajouter(t,valide);
	return 0;
}




