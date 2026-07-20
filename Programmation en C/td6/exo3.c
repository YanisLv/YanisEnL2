#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//1)
struct socle_t{
    char indice;
    int *tab_diametres;
    int nb_disques_courant;
    int nb_disques_total;
};

//2)
//création
struct socle_t* initialiser(char p, int nb_disques_total){
    struct socle_t *s = malloc(sizeof(struct socle_t));
    if(s == NULL){return NULL;}
    s->nb_disques_total = nb_disques_total;
    s->nb_disques_courant = 0;
    s->indice = p;
    s->tab_diametres = malloc(s->nb_disques_total*sizeof(int));
    if(s->tab_diametres == NULL){return NULL;}
    for(int i = 0;i<s->nb_disques_total; i++){
        s->tab_diametres[i] = 0;
    }
    return s;
}


// DETRUIRE
void destruction(struct socle_t *s){
    if(s!= NULL){
        if(s->tab_diametres != NULL){
            free(s->tab_diametres);
        }
        free(s);
    }
}

// AFFICHAGE

void affichage(struct socle_t *s){
    if(s == NULL){
        return;
    }
    
}

//4)
void hanoi(int n, struct socle_t *src, struct socle_t *inter, struct socle_t *dest){
    if(n == 1){
        
    }
}


// 3) PROGRAMME PRINCIPAL

int main(){

    int n; struct socle_t *A,*B,*C;
    printf("entrez n :\n");
    scanf("%d",&n);
    A = initialiser('A',n);
    B = initialiser('B',n);
    C = initialiser('C',n);
    destruction(A);
    destruction(B);
    destruction(C);

    return 0;
}