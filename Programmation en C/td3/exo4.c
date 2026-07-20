#include<stdio.h>
#include<stdlib.h>
int compteur(char chaine[255]){
    int cpt = 0;
    while(chaine[cpt] != '\0'){
        cpt++;
    }
    return cpt;
}
void frequence(char chaine[255],int n){
    float cpt;
    float freq[255];
    for(int i = 0; i<n; i++){
        cpt = 0;
        for(int j = 0; j<n;j++){
            if(chaine[i] == chaine[j]){
                cpt++;
            }
        }
        freq[i] = (cpt/n);
    }
    for(int i = 0; i<n; i++){
        printf("%.2f, ", freq[i]);
    }

    int min = freq[0]*100, max = freq[0]*100;
    char minC = chaine[0], maxC = chaine[0];
    for(int i = 1; i<n;i++){
        if(freq[i]*100 > max){
            max = freq[i]*100;
            maxC = chaine[i];
        }
        if(freq[i]*100 < min){
            min = freq[i]*100;
            minC = chaine[i];
        }
        printf("min = %.2f\n",minC);
    }

    
    printf("\n");
    printf("la lettre la plus courante est %c et la lettre la moins courante est %c. \n",maxC, minC);

}

int main(){

    char str[255];
    printf("entrez une chaine de caracteres : \n");
    scanf("%s",&str);
    int n = compteur(str);
    frequence(str,n);
    
    return 0;
}
