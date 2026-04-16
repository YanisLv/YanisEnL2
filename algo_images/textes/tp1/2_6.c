#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>
uint64_t h0(char *s, int len,int p){
    int somme = 0;
    for(int i = 0; i<len;i++){
        somme += (int)s[i];
    }
    return somme%p;
}

uint64_t h1(char *s, int len, int B,int p){
    int somme = 0;
    for(int i = 0; i<len;i++){
        somme += pow(B,len-i) * (int)s[i];
    }
    return somme % p;
}
int rk0(char *t, char *m,int p){
    int hm = h0(m,strlen(m),p);
    for(int i = 0; i<=strlen(t)-strlen(m);i++){
        int j = 0;
        char tmp;
        while(j<strlen(m)){
            tmp += t[i+j];
            j++;
        }
        tmp = '\0';
        int ht = h0(tmp,strlen(tmp),p);
        if(ht == hm){
            return 1;
        }
    }
    return -1;
}

int main(){
    char *a = "abceeddceabcdde";
    char *b = "abcd";
    int test = rk0(a,b,1869461003);
    if(test == 1){
        printf("le caractere a ete trouve \n");
    }
    else{
        printf("non trouve \n");
    }
    return 0;
}