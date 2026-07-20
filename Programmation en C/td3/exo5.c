#include<stdio.h>
#include<stdlib.h>


void cesar(char chaine[255], int n){

    int i = 0;
    while(chaine[i] != '\0'){
        chaine[i] = ((chaine[i]-97)+n)%26;
        chaine[i] = chaine[i]+97;
        i++;
    }
    printf("%s\n",chaine);
} 

void decesar(char chaine[255], int n){
    int i = 0;
    while(chaine[i] != '\0'){
        chaine[i] = ((chaine[i]-97)-n)%26;
        chaine[i] = chaine[i]+97;
        i++;
    }
    printf("%s\n",chaine);


}


int main()
{

    char str[255];
    printf("entrez chaine\n");
    scanf("%s",&str);
    //cesar(str,1);
    decesar(str,1);

    return 0;
}