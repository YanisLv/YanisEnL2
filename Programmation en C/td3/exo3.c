#include<stdio.h>
#include<stdlib.h>
//-----------EXO 3.1 à 3.2 ---------------///
void compteur_alpha(char chaine[255], int n){

    char alphamin = 'a';
    char alphamaj = 'A';
    int cpt = 0;
    for(int i = 0; i < 26; i++){
        cpt = 0;
        for(int j = 0; j<n; j++){
            if(chaine[j] == alphamin){
                cpt ++;
            }
        }
        printf("%c = %d, ",alphamin, cpt);
        alphamin ++;
    }

    for(int i = 0; i < 26; i++){
        cpt = 0;
        for(int j = 0; j<n; j++){
            if(chaine[j] == alphamaj){
                cpt ++;
            }
        }
        printf("%c = %d, ",alphamaj, cpt);
        alphamaj ++;
    }
}
//3)

void renverser(char chaine[255], int n){
    int i = 0;
    int j = n-1;
    char tmp;
    while(i < j){
        tmp = chaine[i];
        chaine[i] = chaine[j];
        chaine[j] = tmp;
        i++;
        j--;
        
    }

    for(int i = 0; i<n; i++){
        printf("%c",chaine[i]);
    }
}

//4)

int compteur(char chaine[], char c, int n){
    int cpt = 0;
    for(int i = 0; i < n; i++){
        if(chaine[i] == c){
            cpt++;
        }
    }
    return cpt;
}

//5)

int rech_ind(char chaine[], char c, int n){
    for(int i = 0; i < n; i++){
        if(chaine[i] == c){
            return i;
        }
    }
    return -1;
}

//6)

int compare(char s1[], char s2[], int n1, int n2){
    int n = n1;
    if(n1>n2){
        n = n2;
    }
    int i = 0;
    while(i < n){
        if(s1[i] == s2[i]){
            i++;
        }
        else{
            if(s1[i]>s2[i]){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
    if(n1 == n2){
        return 0;
    }
    else{
        if(n1>n2){
            return 1;
        }
    }
    return -1;
}

int main()
{
    char str[255], s1[255], s2[255];
    /*
    printf("entrez votre chaine de caracteres:\n");
    scanf("%s",str);
    */
    printf("entrer premiere chaine de caractre \n");
    scanf("%s", &s1);
    printf("entrer 2e chaine de caractre \n");
    scanf("%s", &s2);
    int i1 = 0;
    while(s1[i1] != '\0'){
        i1++;
    }

    int i2 = 0;
    while(s2[i2] != '\0'){
        i2++;
    }

    int comp = compare(s1,s2,i1,i2);
    if(comp == 0){
        printf("meme taille lexico\n");
    }
    else{
        if(comp == 1){
            printf("s1 > s2\n");
        }
        else{
            printf("s2 > s1\n");
        }
    }
    /*compteur_alpha(str,i);
    printf("il y a %d caracteres\n", i);
    renverser(str,i);
    char s = 'i';
    int cpt = compteur(str,s,i);
    printf("il y a %d occurences de %c\n",cpt,s);
    */

    return 0;
} 