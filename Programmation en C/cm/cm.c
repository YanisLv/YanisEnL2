#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// UNIONS
union ascii{
    int encodage;
    char caractere;
    float reel;
};
// ChDB
union decoupage{
    int n;
    struct champ{
    int d0 : 8;
    int d1 : 8;
    int d2 : 8;
    int d3 : 8;
    }o;
    
};

enum tmp{
    val1 = 17,
    val2
};
int main(){
    // ---------UNIONS--------------
    printf("exo unions \n");
    union ascii a;
    int n;
    printf("entrer l'entier a encoder \n");
    scanf("%d",&n);
    /*
    a.encodage = n;
    printf("l'encodage de %d est %c le flottant est %f \n",n, a.caractere,a.reel);
    
    printf("exo champs \n");
    //----------CHAMPS DE BIT --------
    union decoupage u;
    u.n = n;
    
    printf("%d en binaire est %d|%d|%d|%d\n",u.o.d0,u.o.d1,u.o.d2,u.o.d3);
    // ENUM
    */
    printf("val 1 = %d, val2 = %d, val3 = %d\n",val1,val2);
    return 0;
    
}