#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//------------------- I . Modélisation des véhicules et configurations-----------------

//1)
struct vehicule{
    int ligne, colonne;
    int longueur;
    char orientation;
    char nom;
};

struct configuration{
    struct vehicule tab_vehicules[16];
    int prec;
    int vehicule_mouv;//      |
    char direction_mouv;//     >   MOUVEMENT
    int longueur_mouv; //     |
};

//2)

struct rush_hour{
    struct configuration *tab_config;
    int current, size, max,nb_vehicule;
};

//3)
void increase_size(struct rush_hour *R, int n){
    if(R == NULL){
        return;
    }
    if(R->tab_config == NULL){
        R->tab_config = malloc(n*sizeof(struct configuration));
        R->size = n;
    }
    else{
        int x = n+R->size;
        struct configuration *t = malloc(x*sizeof(struct configuration));
        for(int i = 0; i<R->size; i++){
            t[i] = R->tab_config[i];
        }
        free(R->tab_config);
        R->tab_config = t;²
        R->size = x;
    }

}


//------------------------------ 2 - LECTURE ET AFFICHAGE-----------------------//

//1)
struct rush_hour* allocate(char *fichier){
    struct rush_hour *R = malloc(sizeof(struct rush_hour));
    int i = 0;
    int ligne, colonne,longueur;
    char orientation, nom;
    FILE *fic = fopen(fichier, "r");
    if(fic == NULL){
        printf("erreur fichier \n");
        return NULL;
    }
    R->tab_config = malloc(sizeof(struct configuration));
    while(fscanf(fic,"%d %d %d %c %c", &ligne, &colonne,&longueur,&orientation,&nom) != EOF){
        R->tab_config[0].tab_vehicules[i].ligne = ligne;
        R->tab_config[0].tab_vehicules[i].colonne = colonne;
        R->tab_config[0].tab_vehicules[i].longueur = longueur;
        R->tab_config[0].tab_vehicules[i].orientation = orientation;
        R->tab_config[0].tab_vehicules[i].nom = nom;
        i++;
    }
    R->current = 0, R->size = 1; R->max = 1;
    return R;
}
//2)
void desallocate(struct rush_hour *R){
    if(R!= NULL){
        if(R->tab_config != NULL){
            free(R->tab_config);
        }
        free(R);
    }
}

//3)
void print(struct rush_hour *R){
    if(R == NULL){return;}
    int curr = R->current;
    int nb_fois = 0, oui = 0;
    printf("+");
    for(int i = 0; i<6;i++){
        printf("-");
    }
    printf("+\n");
    
   char tab[6][6];
   for(int i = 0; i<6;i++){
        for(int j = 0; j<6; j++){
            tab[i][j] = '.';
        }
   }


   for(int i = 0; i<6;i++){
        for(int j = 0; j<6;j++){
            for(int k = 0; k<6;k++){
                if(R->tab_config[curr].tab_vehicules[k].ligne == i && R->tab_config[curr].tab_vehicules[k].colonne == j&& R->tab_config[curr].tab_vehicules[k].orientation == 'h'){
                    for(int m = 0; m<R->tab_config[curr].tab_vehicules[k].longueur;m++){
                        tab[i][j+m] = R->tab_config[curr].tab_vehicules[k].nom;
                    }
                }
                if(R->tab_config[curr].tab_vehicules[k].ligne == i && R->tab_config[curr].tab_vehicules[k].colonne == j&& R->tab_config[curr].tab_vehicules[k].orientation == 'v'){
                    for(int m = 0; m<R->tab_config[curr].tab_vehicules[k].longueur;m++){
                        tab[i+m][j] = R->tab_config[curr].tab_vehicules[k].nom;
                    }
                }

            }
        }
   }

   for(int i = 0; i<6;i++){
    printf("|");
        for(int j = 0; j<6;j++){
            printf("%c",tab[i][j]);
        }
        printf("|\n");
   }

    printf("+");
    for(int i = 0; i<6;i++){
        printf("-");
    }
    printf("+\n");
}

//----------------------  3  - ROTATION AUTOMATIQUE--------------------

//1)

struct configuration *move(struct rush_hour *R, int k, int d,int l){
    if(R== NULL){
        return NULL;
    }
    struct configuration *C = malloc(sizeof(struct configuration));
    if(R->tab_config[R->current].tab_vehicules[k].orientation == 'h'){
        if(R->tab_config[R->current].tab_vehicules[k].colonne + l < 6){
            for(int j = 0; j<R->nb_vehicule; j++){
                if(j!=k){
                    if(R->tab_config[R->current].tab_vehicules[k].ligne+ != )
                }
            }
        }
    }
}

int main(){
    struct rush_hour *r = allocate("rush_hour.txt");
    print(r);
    return 0;
}

