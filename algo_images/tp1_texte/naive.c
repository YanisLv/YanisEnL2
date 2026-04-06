#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int naive(char *motif, char *texte){
    int cmp = 0;
    int lm = strlen(motif);
    int lt = strlen(texte);
    for (int i = 0; i <= lt - lm; i++) {
    int k = 0;
        while(k < lm && texte[i + k] == motif[k]) {
            cmp++;
            k++;
        }   
    if (k == lm) return 1; // Trouvé
    if (k < lm) cmp++; // On compte aussi la comparaison qui a fait échouer le while
}
    printf("%d comparaisons\n",cmp);
    return -1;
}

int main(){
    char* t = "tototo";
    char *m = "ti";
    if(naive(m,t) == 1){
        printf("le motif y est bien present \n");
    }
    else{
        printf("le motif n'est pas present dans le texte \n");
    }
    return 0;
}