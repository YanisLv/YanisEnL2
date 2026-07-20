#include<stdio.h>

/*
// -----------BOUCLE FOR-------------------//
int main()
{
    int n, fact = 1;
    printf("entrez n:\n");
    scanf("%d",&n);
    for(int i = 1; i<=n;i++)
    {
        fact = fact * i;
        //printf("%d\n", fact);
    }
    printf("%d factorielle = %d\n", n,fact);
    return 0;

}



//----------------BOUCLE WHILE------------------------//

int main()
{
    int n, fact = 1, i=1;
    printf("entrez n:\n");
    scanf("%d",&n);
    while(i<=n){
        fact = fact * i;
        i++;
    }
    printf("%d factorielle = %d\n", n,fact);
    return 0;
}
*/

//----------------BOUCLE DO------------------------//

int main()
{

    int n, i=1, fact =1;
    printf("entrez n:\n");
    scanf("%d",&n);
    do{
        
        fact *= i;
        i++;
    }while(i<=n);
    printf("%d factorielle = %d\n", n,fact);
    return 0;
}