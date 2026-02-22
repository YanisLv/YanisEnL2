#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int naive(char *m, char *t, int lm, int lt){
    int indice;
    int k = 0;
    for(int i = 0; i<lt-lm+1;i++){
        if(m[0] == t[i]){
            int j = i;
            k = 0;
            while(j<m){
                if(t[j] == m[k]){
                    j++;
                    k++;
                }
            }
            if(k== lm){
                return i;
            }
        }
    }
    return -1;
}

int main(){

    return 0;
}