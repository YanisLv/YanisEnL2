#include <stdio.h>
#include<stdlib.h>
#define N 20 
typedef struct node_gd{
    int info;
    struct node_gd *g;
    struct node_gd *d;
}node_gd;
typedef node_gd* Link;



Link create_gd(int x){
    // creer un noeud avec x pour info et g = d = NULL
    Link temp = (Link)malloc(sizeof(node_gd));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}
Link enfants[N];//tableau de pointeurs vers le noeud 



Link lookup(Link r, int x){
    // Rechercher l'entier x dans l'arbre BST pointé par r

    if(r== NULL || r->info == x){
        return r;
    }
    if(x<r->info){      // chercher dans l'arbre gauche
        return lookup(r->g, x);
    }
    else{   // Rechercher dans l'autre arbre   
        return lookup(r->d, x);  // appel récur
    } 
}

// FAIRE FOCNTION NON RÉCURSIVE

/*chercher l'entier x dans l'arbre BST dont la racine pointée par p*/

Link lookup_nonrec(Link p, int x){
    while(p!= NULL){
        if(p->info == x){
            return p;
        }
        if(x < p->info){
            p = p->g;   // chercher dans l'arbre droit
        }
        else{
            p = p->d;   // chercher dans l'arbre droit
        }
    }
    return NULL;
}


void imprimerAB(Link r,int niveau){         // lokmane
    if(r!=NULL){
        //AFFICHER Ad avec l'indentation niveau+1
        imprimerAB(r->d,niveau+1);
        //imprimer r avec indent niveau
        for(int i=0;i<niveau;i++){
            printf("   ");
        }  
        printf("%d \n",r->info);
        //AFFICHER Ag avec indentation niveau ++
        imprimerAB(r->g,niveau+1);
        
    }

}
Link max(Link p){
    // cherche le noeud
    // le plus a droite de l'arbre pointé par p cette fonction est utilisée
    // pour supprimer un noeud avec 2 enfants
    while(p->d != NULL){
        p = p->d;
    }
    return p ;
}
Link insertion(Link p, int x){      // exo 6
    // insérer l'entier x dans l'arbre BST pointé par p
    // BASE de la récurrence
    if(p==NULL){
        return create_gd(x);
    }
    if(x<p->info){  //aller vers la gauche
        //inserer x a gauche
        p->g = insertion(p->g,x);
    }
    else if(x>p->info){    //aller vers la droite
        // insérer x a droite
        p->d = insertion(p->d,x);
    }
    return p;   // on n'insere pas les entiers égaux
    
}
Link delete(Link p, int x){
        // supprimer le noeud contenant x
        // dans l'arbre pointé par p
        if(p == NULL){
            return NULL;
        }
        if(x<p->info){
            p->g = delete(p->g, x);     // RECUR DANS L'ARBRE GAUCHE
        }
        else if(x>p->info){
            p->d = delete(p->d,x);      // RECUR DANS L'ARBRE DROIT
        }
        else{       // EGALITÉ ON A TROUVÉ
            if(p->g == NULL){
                Link t = p->d;
                free(p);
                return t;
            }
            if(p->d == NULL){
                Link t = p->g;
                free(p);
                return t;
            }
            // CAS 1 : x a au plus 1 enfant
            Link t = max(p->g);
            // copier info de t dans p
            p->info = t->info;
            p->g = delete(p->g, t->info);
        }
        return p;
}




int main(){
    // créer l'arbre ci-contre
    Link r = create_gd(50);
    r->g = create_gd(30);
    r->g->g = create_gd(10);
    r->g->d = create_gd(40);
    r->d = create_gd(60);
    r->d->d=create_gd(70);
    r->d->g=create_gd(55);
    imprimerAB(r,0);
    // L'ARBRE BST CI-CONTRE EST CRÉE
    int x = 30;
    if(lookup_nonrec(r,x) != NULL){
        printf("%d est a l'adresse %d\n",x,r);
    }
    else{
        printf("non trouve \n");
    }
    delete(r,50);
    imprimerAB(r,0);
    

    return 0;
}