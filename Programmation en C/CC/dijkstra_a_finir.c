#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//------------------- I . Représentation d’une liste de couples (sommet, valeur)-----------------

//1)
struct couple{
    int sommet, valeur;
};

//2)
struct liste_couples{
    struct couple current;
    struct liste_couples *next;
};

//3)
void inserer_couple(struct liste_couples **L, int s, int d){
    struct liste_couples *N = NULL;
    N = (struct liste_couples*)malloc(sizeof(struct liste_couples));
    N->current.sommet = s;
    N->current.valeur = d;
    N->next = NULL;
    if(*L == NULL){
        *L = N;
        return;
    }
    struct liste_couples *T = *L;
    while(T != NULL && T->next != NULL){
        T = T->next;
    }
    T->next = N;
}

//4)
struct couple extraire_couple_min_valeur(struct liste_couples **L){
    struct couple vide = { -1, -1 };

    if (*L == NULL) {
        return vide;
    }

    struct liste_couples *T = *L;

    // Initialisation du min
    struct couple min;
    min.sommet = T->current.sommet;
    min.valeur = T->current.valeur;

    // Recherche du min
    while (T != NULL) {
        if (T->current.valeur < min.valeur) {
            min.sommet = T->current.sommet;
            min.valeur = T->current.valeur;
        }
        T = T->next;
    }

    // Maintenant, on supprime ce min dans la liste
    struct liste_couples *P = *L;

    // Cas où le min est au tout début
    if (P->current.valeur == min.valeur) {
        struct liste_couples *tmp = P;
        *L = P->next;
        free(tmp);
        return min;
    }

    // Sinon, on cherche le précédent
    while (P->next != NULL && P->next->current.valeur != min.valeur) {
        P = P->next;
    }

    if (P->next != NULL) {
        struct liste_couples *tmp = P->next;
        P->next = P->next->next;
        free(tmp);
    }

    return min;
}

//5)
void mettre_a_jour_couple(struct liste_couples **L,int s, int d2){
    if(*L == NULL){
        return;
    }
    struct liste_couples *T = *L;
    while(T != NULL && T->current.sommet != s){
        T = T->next;
    }
    if(T == NULL){
        inserer_couple(L,s,d2);
    }
    else{
        //T = T->next;
        T->current.valeur = d2;
    }
}

//6)
void afficher_couples(struct liste_couples **L){
    if(L == NULL){
        return;
    }
    struct liste_couples *T = *L;
    while(T != NULL){
        printf("(%d, %d) -> ",T->current.sommet, T->current.valeur);
        T = T->next;
    }
}
//7)
void detruire_couples(struct liste_couples **L){
    if(*L == NULL){
        return;
    }
    struct liste_couples *T = *L, *P = NULL;
    while(T != NULL){
        P = T->next;
        free(T);
        T = P;
    }
}
// ----------------------- II . REPRESENTATION D'UN GRAPHE -----------------

//1)
struct graphe{
    char **noms;
    struct liste_couples **liste_ajd;
    int nb_sommets;
};
/*
//2) !!!!!!!!!!!!!!!!!!! REVENIR 🪧🛑🛑🛑🛑🛑🛑😵
struct graphe *construire_graphe(char *nom_fichier){
    int nb_sommets, i = 0,tmp_som1, tmp_som2,tmp_val;
    struct graphe *g = (struct graphe*)malloc(sizeof(struct graphe));
    FILE* fic = fopen(nom_fichier, "r");
    if(fic != NULL){
 
        fscanf(fic,"%d",&nb_sommets);
        g->noms = (char*)malloc(nb_sommets*sizeof(char*));
        for(int i = 0; i<nb_sommets; i++){
            g->noms[i] = malloc(50*sizeof(char));
            fscanf(fic,"%s", g->noms[i]);
        }
        while(fscanf(fic,"%d:%d:%d",&tmp_som1, &tmp_som2, &tmp_val) != EOF){
            inserer_couple(&g->liste_ajd,tmp_som1,tmp_val);
            g->liste_ajd->next->current.sommet = tmp_som2;
            i++;
        }
    }
    return g;
}
    */

struct graphe *construire_graphe(char *nom_fichier){
    FILE *fic = fopen(nom_fichier, "r");
    if(fic == NULL){
        return NULL;
    }
    else{
        struct graphe *g = malloc(sizeof(struct graphe));
        int nb_sommets,tmp_som1, tmp_som2, tmp_val;
        fscanf(fic,"%d",&nb_sommets);
        g->nb_sommets = nb_sommets;
        g->noms = malloc(nb_sommets*sizeof(char*));
        g->liste_ajd = malloc(nb_sommets*sizeof(struct liste_couples));
        for(int i = 0; i<nb_sommets; i++){
            g->liste_ajd[i] = NULL;
            g->noms[i] = malloc(50*sizeof(char));
            fscanf(fic,"%s",g->noms[i]);
        }
        while(fscanf(fic,"%d:%d:%d",&tmp_som1,&tmp_som2,&tmp_val) != EOF){
            inserer_couple(&(g->liste_ajd[tmp_som1]),tmp_som2,tmp_val);
            inserer_couple(&(g->liste_ajd[tmp_som2]),tmp_som1,tmp_val);
        }
        fclose(fic);
        return g;
    }
    
}
//3)
int trouver_sommet(char *nom, struct graphe *g){
    int i = 0, trouve = 0;
    while(i< g->nb_sommets && trouve == 0){
        if(g->noms[i] == nom){
            trouve = 1;
        }
        i++;
    }
    if(trouve == 1){
        return i;
    }
    return -1;
}
//4)
void afficher_graphe(struct graphe *g){
    for(int i = 0; i<g->nb_sommets; i++){
        printf("G[%d] : %s ->");
        afficher_couples(&(g->liste_ajd[i]));
        printf("\n");
    }
}

//5)
void detruire_graphe(struct graphe *g){
    if(g != NULL){
        if(g->liste_ajd != NULL){
            for(int i = 0; i<g->nb_sommets; i++){
                if(g->liste_ajd[i] != NULL){
                    detruire_couples(&(g->liste_ajd[i]));
                }
            }
            free(g->liste_ajd);

        }
        if(g->noms != NULL){
            for(int i = 0; i<g->nb_sommets; i++){
                free(g->noms[i]);
            }
            free(g->noms);
        }
        free(g);
    }

}

// --------------------- 3 - ALGORITHME DE DIJKSTRA --------------------------

//1)
struct file{
    struct liste_couples *tete, *queue;
};
//INITIALISE FILE
struct file initialiser(){
    struct file f;
    f.tete = NULL, f.queue = NULL;
}
// EST VIDE FILE
int estVide(struct file f){
    if(f.tete == NULL);
        return 1;
    else
        return 0;
}
// ENFILER ELEMENT

int enfiler(struct file f, struct couple c){
    struct liste_couples *list = malloc(sizeof(liste_couples));
    list->current = c;
    list->next = NULL;
    if(estVide(f)){
        f.tete = list;
        f.queue = list;
    }
    else{
        f.queue->next = list;
        f.queue = list;
    }
    return 1;
}

void dijkstra(struct graphe *g, int s1, int s2){
    // entree: depart, arrivee = deux entiers positifs ou nuls
    // sortie: plus courte distance pour aller de depart a arrivee
    if(g==NULL){return;}

    // INITIALISATION *VISITES ET *DISTANCE_MIN ✅

    int *visites = malloc(g->nb_sommets*sizeof(int)); // A DETRUIRE⛔
    for(int i = 0; i<g->nb_sommets; i++){
        visites[i] = 0;
    }
    
    int *distance_min = malloc(g->nb_sommets*sizeof(int)); // A DETRUIRE⛔
    for(int i = 0; i<g->nb_sommets; i++){
        distance_min[i] = 0;
    }

    // INITALISATION FILE ✅
    struct file priorite = initialiser();
    struct couple c;
    struct couple min;
    c.sommet = s1;
    c.valeur = 0;
    enfiler(priorite,c);
    distance_min[s1] = 0;
    while(estVide(priorite) == 0){
        min = extraire_couple_min_valeur(g->liste_ajd);
        visites[min.sommet] += 1;
        if(min.sommet == s2){
            break;
        }
        else{
             
        }
    }




}

// --------------------- PROGRAMME PRINCIPAL--------------------
int main(){
    struct couple c; c.sommet = 1, c.valeur = 5;
    struct couple min;
    struct liste_couples **L = (struct liste_couples**)malloc(sizeof(struct liste_couples*));
    *L = NULL;
    inserer_couple(L,1,5);
    inserer_couple(L,2,3);
    inserer_couple(L,3,10);
    inserer_couple(L,4,9);
    afficher_couples(L);
    min = extraire_couple_min_valeur(L);
    printf("\n");
    printf("le sommet minimal est %d avec une taille %d\n ",min.sommet,min.valeur);
    printf("\n");
    afficher_couples(L);
    printf("\n");
    mettre_a_jour_couple(L,9,25);
    afficher_couples(L);
    printf("\n");
    detruire_couples(L);
    printf("\n");
    afficher_couples(L);
    return 0;
}