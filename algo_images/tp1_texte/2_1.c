#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------1)

int naive(char *m, char *t){
    int cmp = 0;
    int indice;
    int lm = strlen(m);
    int lt = strlen(t);
    for(int i = 0; i<= lt-lm;i++){
        int k = 0;
        cmp ++;
        while(k<lm && m[k] == t[i+k]){
            
            k++;
            cmp += k;
        }
        if(k == lm){
            printf("%d comparaisons \n",cmp);
            return i;
        }
    }
    printf("%d comparaisons \n",cmp);
    return -1;
}
int naive2(char *m, char *t){
    int indice;
    int lm = strlen(m);
    int lt = strlen(t);
    for(int i = 0; i<= lt-lm;i++){
        if(strncmp(t+i,m,strlen(m)) == 0){
            return i;
        }
    }
    return -1;
    
}

//-------------2)
struct list{
    int x;
    struct list *next;
};
struct list *naive_occ(char *m, char *t) {
    int lm = strlen(m);
    int lt = strlen(t);
    
    // CRITIQUE : Initialiser L ET T à NULL
    struct list *L = NULL; 
    struct list *T = NULL;

    for (int i = 0; i <= lt - lm; i++) {
        int k = 0;
        while (k < lm && m[k] == t[i + k]) {
            k++;
        }
        
        if (k == lm) {
            struct list *N = malloc(sizeof(struct list));
            // Toujours vérifier si le malloc a réussi dans un vrai projet
            if (N == NULL) return L; 

            N->x = i;
            N->next = NULL;

            if (L == NULL) {
                L = N;
                T = L;
            } else {
                T->next = N;
                T = N;
            }
        }
    }
    return L;
}
void print(struct list* L){
    struct list *T = L;
    while(T!= NULL){
        printf("%d -> ",T->x);
        T = T->next;
    }
    printf("\n");
}

//-------------3)

int naive_aff(char *m, char *t){
   int lm = strlen(m);
    int lt = strlen(t);
    int cmp = 0; 
    for (int i = 0; i <= lt - lm; i++) {
        int k = 0;
        while (k < lm) {
            cmp++;
            if (m[k] == t[i + k]) {
                k++;
            } else {
                break;  // pour sortir du while car comparaison fausse
            }
        }
        if (k == lm) {
            printf("Nombre total de comparaisons : %d\n", cmp);
            return i; // Retourne l'indice trouvé
        }
    }

    printf("Nombre total de comparaisons : %d\n", cmp);
    return -1;
}

//-------------4)



int main(){
    char* t = "tototlo";
    char *m = "lo";
    
    if(naive_aff(m,t) == -1){
        printf("le motif n'est pas present dans le texte \n");
    }
    else{
        printf("le motif est present, le premier est indice est a %d \n",naive_aff(m,t));
    }
    /*
    struct list *tab = naive_occ(m,t);
    print(tab);
    printf("\n");
    */
    return 0;
}