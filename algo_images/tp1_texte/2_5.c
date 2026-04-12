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
//2) car il s'agit d'un grand nombre 
/*
3)
ebook, notre, other, parts, under,
terms, check, where, using, chuck, greif, start, paris
*/
int main(){
    char *a = "ebook", *b ="notre",*c="other",*d="parts", *e ="under", *f ="terms";
    char *g = "check", *h ="where", *i ="using", *j ="chuck";
    char lettre = 'a';
    printf("%u \n",h0(a,strlen(a),1869461003));
    printf("%u \n",h0(b,strlen(b),1869461003));
    printf("%u \n",h0(c,strlen(c),1869461003));
    printf("%u \n",h0(d,strlen(d),1869461003));
    printf("%u \n",h0(e,strlen(e),1869461003));
    printf("%u \n",h0(f,strlen(f),1869461003));
    printf("%u \n",h0(g,strlen(g),1869461003));
    printf("%u \n",h0(h,strlen(h),1869461003));
    printf("%u \n",h0(i,strlen(i),1869461003));
    printf("%u \n",h0(j,strlen(j),1869461003));
    return 0;
}

